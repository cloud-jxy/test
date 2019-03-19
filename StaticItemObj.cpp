#include "stdafx.h"
#include "StaticItemObj.h"


StaticItemObj::StaticItemObj()
{
}


StaticItemObj::~StaticItemObj()
{
}

StaticItemObj::StaticItemObj(CString strKey, CString strValue, CString strID, int startByte, int startBite, int biteLen, FuncToString func, double ratio, double offset) {
	m_strKey = strKey;
	m_strValue = strValue ? strValue : _T("未检测到");
	m_strID = strID;
	m_startByte = startByte;
	m_startBite = startBite;
	m_biteLen = biteLen;
	m_ratio = ratio;
	m_offset = offset;
}

static unsigned char GetFlag(int bite_len) {
	unsigned char vals[] = { 1, 2, 4, 8, 16, 32, 64, 128 };
	unsigned char ret = 0;
	int i = 0;

	for (i = 0; i < bite_len; i++) {
		ret += vals[i];
	}

	return ret;
}

BOOL StaticItemObj::IsSameId(unsigned int i)
{
	unsigned int val;
	char *str_id = T2A(m_strID.GetBuffer(0));
	val = atof(str_id);

	return val == i;
}

double StaticItemObj::Calculate(unsigned char* data) {
	int i_val = 0; // double不能进行位移运算， 先用int过渡
	double d_val;
	int start_byte = m_startByte;
	int start_bite = m_startBite;
	int bite_len = m_biteLen;
	double ratio = m_ratio;
	double offset = m_offset;
	BOOL is_intel = TRUE;

	if (bite_len <= 8) {
		unsigned char flag = GetFlag(bite_len);
		unsigned char val = data[start_byte] >> start_bite;
		i_val = val & flag;
	}
	else {
		if (is_intel) {
			int left_len = bite_len;

			while (left_len) {
				int index = start_byte + (bite_len - left_len) / 8;
				i_val = i_val + (data[index] << (bite_len - left_len));
				left_len -= 8;
			}
		}
		else {
			int left_len = bite_len;
			int byte_len = bite_len / 8;
			int offset_from_right = 0;

			while (left_len) {
				offset_from_right = (bite_len - left_len) / 8;
				int index = start_byte + (byte_len - 1) - offset_from_right;
				i_val = i_val + (data[index] << (bite_len - left_len));
				left_len -= 8;
			}
		}
	}

	d_val = ratio * i_val + offset;
	return d_val;
}

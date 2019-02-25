#pragma once

class HaideProtocolDialog;

class FrameRuleObj {
public:
	CString name;
	CString id;
	int start_byte;
	int start_bite;
	int bite_len;
	double ratio;
	double offset;

	CString description1;
	CString description2;
	CString group;

	BOOL is_intel;
	CString str_from;

	BOOL IsSameId(int i)
	{
		USES_CONVERSION;
		char *str_id = T2A(id.GetBuffer(0));

		return atoi(str_id) == i;
	}

	unsigned char GetFlag(int bite_len) {
		unsigned char vals[] = { 1, 2, 4, 8, 16, 32, 64, 128 };
		unsigned char ret = 0;
		int i = 0;

		for (i = 0; i < bite_len; i++) {
			ret += vals[i];
		}

		return ret;
	}

	double Parse(unsigned char *data) {
		int i_val = 0; // double不能进行位移运算， 先用int过渡
		double d_val;

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

	CString Parse2(unsigned char *data) {
		CString ret;
		double val = Parse(data);
		
		// 用int进行强制类型转换，如果后边有小数，int会有截断误差的
		if ((int)val == val) {
			ret.Format("%.0f", val);	// 注意，这是不要用%d
		}
		else {
			ret.Format("%.2lf", val);
		}

		return ret;
	}
};

enum OperateType {
	ADD
	, EDIT
	, LOOK
};

// FrameRuleDialog 对话框

class FrameRuleDialog : public CDialogEx
{
	DECLARE_DYNAMIC(FrameRuleDialog)

public:
	FrameRuleDialog(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~FrameRuleDialog();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_FRAME_RULE_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()

public:
	OperateType m_operate;
	HaideProtocolDialog *m_p_dlg;
	afx_msg void OnBnClickedOk();
	CString m_str_name;
	CString m_str_id;
	int m_i_start_byte;
	int m_i_start_bite;
	int m_i_bite_len;
	double m_ratio;
	double m_offset;
	CString m_str_decription1;
	CString m_str_decription2;
	BOOL m_is_intel;

	virtual BOOL OnInitDialog();

	int m_list_index;
	afx_msg void OnBnClickedCheck1();
	afx_msg void OnBnClickedCheck2();
	CString m_str_group;
	CString m_str_from;
};

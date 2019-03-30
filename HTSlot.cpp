#include "stdafx.h"
#include "HTSlot.h"

HTSlot::HTSlot() {
	m_leftLen = 0;
	m_preLen = 0;
	m_posOfParseData = 0;
	m_count = 0;
}

void HTSlot::OnCOMRecv() {
//	TRACE("parent: OnCOMRecv\n");
	int readLen = 1;

	while (true) {
		memset(m_curData, 0, 1024);
		//readLen = m_pSerialPort->readData(m_curData, 32);
		readLen = m_pSerialPort->readData(m_curData, 1024);

		TRACE("recv: %d, %s\n", readLen, m_curData);
		if (readLen <= 0) {
			break;
		}

		if (readLen > 16) {
			continue;
		}

		//m_count++;
		//if (m_count == 1) {
		//	continue;
		//}

		Parse(readLen);
		//ParseHT(m_curData);
	}
}

int n = 0;

void HTSlot::ParseHT(char *data) {
	int h, t;
	sscanf(data, "H%dT%d", &h, &t);
	TRACE("parent: h= %d, t=%d\n", h, t);
	OnCOMRecvHT(h, t);
}

void HTSlot::Parse(int curLen) {
	char cEnd = '-';
	char cStart = 'H';
	char *startPtr = 0;
	char *endPtr = 0;

	memset(m_parseData, 0, sizeof(m_parseData));
	if (m_preLen > 0) {
		memcpy(m_parseData, m_preData, m_preLen);
		memcpy(m_parseData + m_preLen, m_curData, curLen);
	}
	else {
		memcpy(m_parseData, m_curData, curLen);
	}

	startPtr = strchr(m_parseData, cStart);

	TRACE("startPtr = %p\n", startPtr);

	if (startPtr == NULL) {
		//没有找到开始字符, 存入m_preData
		m_preLen = strlen(m_parseData);
		memcpy(m_preData, m_parseData, m_preLen);

		return;
	}

	endPtr = strchr(startPtr, cEnd);

	TRACE("endPtr = %p\n", endPtr);

	if (endPtr == NULL) {
		// 没有找到结束字符,保存入m_preData
		m_preLen = strlen(m_parseData);
		memcpy(m_preData, m_parseData, m_preLen);

		return;
	}

	//具有开始和结束标记，开始解析
	//char tmp[64] = {0};
	//memcpy(tmp, startPtr, endPtr - startPtr);

	ParseHT(startPtr);

	//将endPtr后的剩余数据，存入m_preData
	m_preLen = strlen(endPtr);
	memset(m_preData, 0, 64);
	memcpy(m_preData, endPtr, m_preLen);
}

void HTSlot::OnCOMRecvHT(int h, int t) {
	TRACE("parent: h= %d, t=%d\n", h, t);
}


void HTSlot::SetSerialPort(CSerialPort *p) {
	m_pSerialPort = p;
}


void HTSlot::StartMonitor() {
	m_pSerialPort->readReady.connect(this, &HTSlot::OnCOMRecv);
}

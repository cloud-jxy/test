#include "stdafx.h"
#include "HTSlot.h"

HTSlot::HTSlot() {
	m_leftLen = 0;
	m_preLen = 0;
	m_posOfParseData = 0;
}

void HTSlot::OnCOMRecv() {
	TRACE("parent: OnCOMRecv\n");
	int readLen = 1;

	while (true) {
		memset(m_curData, 0, 1024);
		readLen = m_pSerialPort->readData(m_curData, 1024);
		TRACE("%s\n", m_curData);
		if (readLen <= 0) {
			break;
		}
		Parse(readLen);
		//ParseHT(m_curData);
	}
}


void HTSlot::ParseHT(char *data) {
	int h, t;
	sscanf(data, "H%dT%d", &h, &t);
	
	OnCOMRecvHT(h, t);
}

void HTSlot::Parse(int curLen) {
	memset(m_parseData, 0, sizeof(m_parseData));
	if (m_preLen > 0) {
		memcpy(m_parseData, m_preData, m_preLen);
		memcpy(m_parseData + m_preLen, m_curData, curLen);
	}
	else {
		memcpy(m_parseData, m_curData, curLen);
	}


	char *delim = "-";
	char *p;
	char *pLast;	//指向，最后一组HT数据，先添加，以后可能会用到。
	p = strtok(m_parseData, delim);

	while (p != NULL) {
		pLast = p;

		ParseHT(p);

		p = strtok(NULL, delim);
	}
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

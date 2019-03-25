#pragma once

#include "CSerialPort\sigslot.h"
#include "CSerialPort\SerialPort.h"

using namespace itas109;
using namespace std;

class HTSlot : public has_slots<>
{
public:
	HTSlot();
	virtual void OnCOMRecv();
	virtual void OnCOMRecvHT(int h, int t);

public:
	CSerialPort *m_pSerialPort;
	virtual void SetSerialPort(CSerialPort *p);;
	virtual void ParseHT(char *data);
	char m_curData[1024] = { 0 };

	/*下面的变量及函数，可能是我太过谨慎了，即使暂不使用，也先保留*/
	void Parse(int);
	char m_preData[64] = { 0 };
	char m_parseData[1088] = { 0 };
	int m_leftLen;
	int m_preLen;
	int m_posOfParseData;

	void StartMonitor();
};


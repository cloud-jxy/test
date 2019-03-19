#pragma once

class CMyTabDialog;
typedef CString(CMyTabDialog::*PtrFuncToString)(double);

class StaticItemObj
{
public:
	StaticItemObj();
	StaticItemObj(CString key, CString value, CString strID, int startByte, int startBite, int biteLen, PtrFuncToString func = NULL, double ratio = 1, double offset = 0);
	~StaticItemObj();
public:
	CString m_strKey;
	CString m_strValue;

	CString m_strID;
	int m_startByte;
	int m_startBite;
	int m_biteLen;
	double m_ratio;
	double m_offset;

	BOOL IsSameId(unsigned int i);
	double Calculate(unsigned char* p);

	void* m_pParam;
	PtrFuncToString m_pFuncToString;
};

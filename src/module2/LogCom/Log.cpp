// Log.cpp : Implementation of CLog

#include "pch.h"
#include "Log.h"


// CLog

CLog::CLog() {
    m_source = SysAllocString(L"C:\\TEMP\\Log.txt");
}

CLog::~CLog() {
    if (m_source) SysFreeString(m_source);
}

STDMETHODIMP CLog::get_Source(BSTR* pVal)
{
    // TODO: Add your implementation code here
    *pVal = SysAllocString(m_source);

    return S_OK;
}


STDMETHODIMP CLog::put_Source(BSTR newVal)
{
    // TODO: Add your implementation code here
    if (m_source) SysFreeString(m_source);
    m_source = SysAllocString(newVal);

    return S_OK;
}


STDMETHODIMP CLog::Write(BSTR message)
{
    // TODO: Add your implementation code here
    SYSTEMTIME time;
    TCHAR text[1024];
    DWORD dwBytes;  // uint32_t dwBytes;

    GetSystemTime(&time);
    HANDLE hFile = CreateFile(OLE2T(m_source),
        GENERIC_WRITE, NULL, NULL, OPEN_ALWAYS,
        FILE_ATTRIBUTE_NORMAL, NULL);

    _stprintf_s(text, _T("[%04d-%02d-%02d %02d:%02d:%02d] %s\r\n"),
        time.wYear, time.wMonth, time.wDay,
        time.wHour, time.wMinute, time.wSecond,
        OLE2T(message));

    SetFilePointer(hFile, 0, 0, FILE_END);
    dwBytes = _tcslen(text) * sizeof(TCHAR);
    WriteFile(hFile, text, dwBytes, &dwBytes, NULL);
    CloseHandle(hFile);

    return S_OK;
}

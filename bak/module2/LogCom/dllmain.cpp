// dllmain.cpp : Implementation of DllMain.

#include "pch.h"
#include "framework.h"
#include "resource.h"
#include "LogCom_i.h"
#include "dllmain.h"

CLogComModule _AtlModule;

// DLL Entry Point
extern "C" BOOL WINAPI DllMain(HINSTANCE hInstance, DWORD dwReason, LPVOID lpReserved)
{
	hInstance;
	return _AtlModule.DllMain(dwReason, lpReserved);
}


STDMETHODIMP CLogComModule::get_Source(BSTR* pVal)
{
	// TODO: Add your implementation code here

	return S_OK;
}


STDMETHODIMP CLogComModule::put_Source(BSTR newVal)
{
	// TODO: Add your implementation code here

	return S_OK;
}


STDMETHODIMP CLogComModule::Write(BSTR message)
{
	// TODO: Add your implementation code here

	return S_OK;
}

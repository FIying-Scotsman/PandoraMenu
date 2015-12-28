#include <windows.h>
#include <string>
#include <psapi.h>

using namespace std;

DWORD64 GetModuleBase(HANDLE hProc, std::string &sModuleName)
{
	HMODULE *hModules;
	hModules = 0;
	char szBuf[50];
	DWORD cModules = 0;
	DWORD64 dwBase = 0;

	EnumProcessModules(hProc, hModules, 0, &cModules);
	hModules = new HMODULE[cModules / sizeof(HMODULE)];

	if (EnumProcessModules(hProc, hModules, cModules / sizeof(HMODULE), &cModules)) {
		for (int i = 0; i < cModules / sizeof(HMODULE); i++) {
			if (GetModuleBaseName(hProc, hModules[i], szBuf, sizeof(szBuf))) {
				if (sModuleName.compare(szBuf) == 0) {
					dwBase = (DWORD64)hModules[i];
					break;
				}
			}
		}
	}

	delete[] hModules;

	return dwBase;
}

void BYPASS_ONLINE()
{
	__int64 Address = GetModuleBase(GetCurrentProcess(), std::string("GTA5.exe"));



	CHAR *MemoryBuff = new CHAR[4096];
	HANDLE hProcess = GetCurrentProcess();
	BYTE bytes[10] = { 0x48, 0x8B, 0x88, 0x10, 0x01, 0x00, 0x00, 0x48, 0x8B, 0xC1 };//BYPASS_SPAWN
	BYTE bytes2[10] = { 0x83, 0xBB, 0x34, 0x01, 0x00, 0x00, 0xFF, 0x0F, 0x95, 0xC0 };//BYPASS_EVERY_TIME_CHECK_FOR_PLAYER_MODEL
	BYTE nop2[2] = { 0x90, 0x90 };
	BYTE nop3[3] = { 0x90, 0x90, 0x90 };

	int Check = 0;
	for (;;)
	{
		ReadProcessMemory(hProcess, (LPVOID)Address, (LPVOID)MemoryBuff, 4096, NULL);
		for (INT p = 0; p < 4096; p++)
		{
			Address++;
			MemoryBuff++;
			if (memcmp(MemoryBuff, bytes, 10) == 0)
			{
				WriteProcessMemory(hProcess, (LPVOID)(Address + 0x20), nop2, 2, NULL);
				WriteProcessMemory(hProcess, (LPVOID)(Address + 0x2D), nop2, 2, NULL);
				Check += 1;
			}
			if (memcmp(MemoryBuff, bytes2, 10) == 0)
			{
				WriteProcessMemory(hProcess, (LPVOID)(Address - 3), nop3, 3, NULL);
				Check += 1;
			}
			if (Check >= 2)
			{
				goto endfunc;
			}
		}
		MemoryBuff = MemoryBuff - 4096;
	}
endfunc:;
}
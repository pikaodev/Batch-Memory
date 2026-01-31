#include "batch_exec.h"
#include <windows.h>

void BatMem(const std::string& script) {

    SECURITY_ATTRIBUTES sa{};
    sa.nLength = sizeof(sa);
    sa.bInheritHandle = TRUE;

    HANDLE readPipe = nullptr;
    HANDLE writePipe = nullptr;

    if (!CreatePipe(&readPipe, &writePipe, &sa, 0))
        return;

    STARTUPINFOA si{};
    PROCESS_INFORMATION pi{};
    si.cb = sizeof(si);
    si.dwFlags = STARTF_USESTDHANDLES;
    si.hStdInput = readPipe;
    si.hStdOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    si.hStdError = GetStdHandle(STD_ERROR_HANDLE);

    if (!CreateProcessA(
        nullptr,
        (LPSTR)"cmd.exe",
        nullptr,
        nullptr,
        TRUE,
        0, // set to 0 if u wish it to show cmd from ur script; if not set to CREATE_NO_WINDOW
        nullptr,
        nullptr,
        &si,
        &pi))
    {
        CloseHandle(readPipe);
        CloseHandle(writePipe);
        return;
    }

    DWORD written;
    WriteFile(writePipe, script.data(), (DWORD)script.size(), &written, nullptr);
    WriteFile(writePipe, "\r\nexit\r\n", 8, &written, nullptr);

    CloseHandle(writePipe);
    CloseHandle(readPipe);

    WaitForSingleObject(pi.hProcess, INFINITE);
    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);
}

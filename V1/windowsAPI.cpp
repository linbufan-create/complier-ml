#include <Windows.h>
#include <bits/stdc++.h>
#include "data.hpp"
using namespace std;
// 编译器路径
wstring GetSelfPath()
{
    wchar_t Path[MAX_PATH] = {0};
    GetModuleFileNameW(NULL, Path, MAX_PATH);
    return filesystem::path(Path).parent_path().wstring();
}
// 源代码路径
wstring GetFileName()
{
    wchar_t CmdPath[MAX_PATH] = {0};
    GetCurrentDirectoryW(MAX_PATH, CmdPath);
    wstring Path = filesystem::path(CmdPath).parent_path().wstring();
    wstring temp = L"";
    for (wchar_t c : file_name)
    {
        temp += c;
        if (c == '\\')
        {
            Path += temp;
            temp = L"";
        }
    }
    return Path;
}
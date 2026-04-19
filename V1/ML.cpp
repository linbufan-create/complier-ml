// 于2026/4/18创建
// 实现小型编译器
// 规则:
// 1.  int x    //新建整型变量
// 2.  char c  //新建字符变量
// 3.  print("")//输出字符串
#include <bits/stdc++.h>
#include "read.hpp"
#include "WindowsAPI.hpp"
#include "data.hpp"
#include "wrtie.hpp"
#include "split.hpp"
using namespace std;
// 获得路径
void get_path()
{
    self_path = GetSelfPath();
    file_path = GetFilePath();
}
// 获得文件名以及汇编文件名
void get_all_filename(char *ml_file_name)
{
    strcpy(file_name, ml_file_name);
    memcpy(asm_name, file_name, strlen(file_name) - 2);
    asm_name[strlen(file_name) - 2] = '\0';
    strcat(asm_name, "asm");
}

// 解析文件
void parse_file()
{
    for (int i = 0; i < file_content_split.size(); i++)
    {
        string &line = file_content_split[i];
        while (line[0] == ' ')
        {
            line.erase(0);
        }
    }
}
// 输出函数部分的汇编代码(暂时不考虑实现)
void write_function()
{
}
// 输出数据部分的汇编代码
void write_data()
{
}
// 输出代码部分的汇编代码
void write_code()
{
}
// 编译+链接汇编文件
void build()
{
    system(strcat("cmd ", strcat(asm_name, "/link /subsystem:console kernel32.lib")));
}
int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        cout << "ERROR:NO FILENAME\n";
        return EXIT_FAILURE;
    }
    try
    {
        file_content = read(argv[1]);
    }
    catch (...)
    {
        cout << "ERROR:CAN NOT FIND OR OPEN THE FILE\n";
        return EXIT_FAILURE;
    }
    get_path();
    write_head();
    get_all_filename(argv[1]);
    freopen(file_name, "w", stdout);
    split();
    parse_file();
    if (argc >= 3)
    {
        build();
    }
    return EXIT_SUCCESS;
}
#pragma once
#ifndef DATA_HPP
#define DATA_HPP

#endif // DATA_HPP
//存储所有数据(作用域仅在函数内的除外)
#include<bits/stdc++.h>
using namespace std;
char file_name[_MAX_FNAME];
char asm_name[_MAX_FNAME];
size_t size_of_file_content;
stack<char> stk;      // 用来配对大小括号
string code_function; // 暂时不考虑实现
string file_content;
vector<string> file_content_split;
string read(const char filename[]) {}
string code_data; // 存储data区的代码
string code_code; // 存储code区的代码

//于2026/4/18创建
//实现小型编译器
//规则:
//1.  int x    //新建整型变量
//2.  char c  //新建字符变量
//3.  print("")//输出字符串
#include<bits/stdc++.h>
#include"read.hpp"
#include"WindowsAPI.hpp"
#include"data.hpp"
#include"wrtie.hpp"
using namespace std;

void get_path(){
    self_path=GetSelfPath();
    file_path=GetFilePath();
}
//文件头
void write_heads()
{
    cout << ".386" << endl;
    cout << ".model flat,stdcall" << endl;
    cout << "" << endl;
    cout << "ExitProcess proto dwExitCode : dword" << endl;
    cout << "GetStdHandle proto nStdHandle : dword" << endl;
    cout << "WriteConsoleA proto hConsoleOutput : dword," << endl;
    cout << "ReadConsoleA proto hConsoleInput:dword, lpBuffer:ptr byte, nChars:dword, lpRead:ptr dword, lpReserved:dword" << endl;
    cout << "lpBuffer : ptr byte," << endl;
    cout << "nChars : dword," << endl;
    cout << "lpWritten : ptr dword," << endl;
    cout << "lpReserved : dword" << endl;
    cout << "STD_OUTPUT_HANDLE equ -11" << endl;
    cout << "STD_INPUT_HANDLE equ -10 " << endl;
}
//获得文件名以及汇编文件名
void get_all_filename(char* ml_file_name){
    strcpy(file_name,ml_file_name);
    memcpy(asm_name, file_name, strlen(file_name) - 2);
    asm_name[strlen(file_name) - 2] = '\0';
    strcat(asm_name, "asm");
}
//分行
void split(){
    string temp;
    for(int i=0;i<file_content.size();i++){
        //转义字符,跳过下一个字符
        if(file_content[i]=='\\'){
            i++;
            continue;
        }
        //注释要两个字符，不能只有一个字符,防止判断时越界
        else if(i<file_content.size()-1){
            //单行注释
            if(file_content[i]=='/'&&file_content[i+1]=='/'){
                //文件尾注释
                if(i+1==file_content.size()-1){
                    break;
                }
                //查找换行符
                for(int j=i+2;j<file_content.size();j++){
                    //转义下一个，跳过
                    if(file_content[j]=='\\'){
                        j++;
                    }
                    //找到了换行符,跳转到转行符后
                    else if(file_content[j]=='\n'){
                        i=j;
                        break;
                    }
                }
                continue;
            }
            //注释块
            if(file_content[i]=='/'&&file_content[i+1]=='*'){
                //文件尾注释
                if (i + 1 == file_content.size() - 1)
                {
                    break;
                }
                for(int j=i+2;j<file_content.size()-1;j++){
                    // 转义下一个，跳过
                    if (file_content[j] == '\\')
                    {
                        j++;
                    }
                    //跳转到结束部分后
                    if(file_content[j]=='*'&&file_content[j+1]=='/'){
                        i=j+2;
                        break;
                    }
                }
                continue;
            }
            //是换行符,切割,清空temp
            else if(file_content[i]=='\n'){
                file_content_split.push_back(temp);
                temp="";
            }
            //其他字符,加入内容
            else{
                temp+=file_content[i];
            }
        }
        // 是换行符,切割,清空temp
        else if (file_content[i] == '\n')
        {
            file_content_split.push_back(temp);
            temp = "";
        }
        // 其他字符,加入内容
        else
        {
            temp += file_content[i];
        }
    }
    if(temp==""){
        return;
    }
    file_content_split.push_back(temp);
    return;
}
//解析文件
void parse_file(){
   for(int i=0;i<file_content_split.size();i++){
        string &line=file_content_split[i];
        while(line[0]==' '){
            line.erase(0);
        }
        
   }
}
//输出函数部分的汇编代码(暂时不考虑实现)
void write_function(){
    
}
//输出数据部分的汇编代码
void write_data(){
    
}
//输出代码部分的汇编代码
void write_code(){
    
}
//编译+链接汇编文件
void build()
{
    system(strcat("cmd ", strcat(asm_name, "/link /subsystem:console kernel32.lib")));
}
int main(int argc,char* argv[]){
    if(argc<2){
        cout<<"ERROR:NO FILENAME\n";
        return EXIT_FAILURE;
    }
    try{
        file_content=read(argv[1]);
    }catch(...){
        cout<<"ERROR:CAN NOT FIND OR OPEN THE FILE\n";
        return EXIT_FAILURE;
    }
    get_path();
    write_head();
    get_all_filename(argv[1]);
    freopen(file_name,"w",stdout);
    split();
    parse_file();
    if(argc>=3){
        build();
    }
    return EXIT_SUCCESS;
}
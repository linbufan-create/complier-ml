#include<bits/stdc++.h>
#include"data.hpp"
using namespace std;\
//从文件读入代码
string read(const char filename[]){
    ifstream file(filename);
    if (!file.is_open())
    {
       throw("can not open");
    }
    string content((istreambuf_iterator<char>(file)),istreambuf_iterator<char>());
    return content;
}
//获得连续的一段函数、变量名
//line表示所在的行(file_content_split的下标)
//pos表示开始位置(下标)
string get_name(int line,int pos){
    string &line_content=file_content_split[line];
    string temp="";
    for(int i=pos;i<line_content.size();i++){
        if((line_content[i]>='a'&&line_content[i]<='z')||(line_content[i]>='A'&&line_content[i]<='Z')||(line_content[i]=='_')){
            temp+=line_content[i];
        }
        else{
            return temp;
        }
    }
}
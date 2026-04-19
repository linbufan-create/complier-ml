#include<bits/stdc++.h>
using namespace std;
string read(const char filename[]){
    ifstream file(filename);
    if (!file.is_open())
    {
       throw("can not open");
    }
    string content((istreambuf_iterator<char>(file)),istreambuf_iterator<char>());
    return content;
}
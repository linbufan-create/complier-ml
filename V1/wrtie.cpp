#include<bits/stdc++.h>
using namespace std;
void write_head(){
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
void write_code() {

}
void write_data() {

}
void write_function() {

}
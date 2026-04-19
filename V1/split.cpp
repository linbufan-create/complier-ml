#include<bits/stdc++.h>
#include"data.hpp"
using namespace std;
// 分行
void split()
{
    string temp;
    for (int i = 0; i < file_content.size(); i++)
    {
        // 转义字符,跳过下一个字符
        if (file_content[i] == '\\')
        {
            i++;
            continue;
        }
        // 注释要两个字符，不能只有一个字符,防止判断时越界
        else if (i < file_content.size() - 1)
        {
            // 单行注释
            if (file_content[i] == '/' && file_content[i + 1] == '/')
            {
                // 文件尾注释
                if (i + 1 == file_content.size() - 1)
                {
                    break;
                }
                // 查找换行符
                for (int j = i + 2; j < file_content.size(); j++)
                {
                    // 转义下一个，跳过
                    if (file_content[j] == '\\')
                    {
                        j++;
                    }
                    // 找到了换行符,跳转到转行符后
                    else if (file_content[j] == '\n')
                    {
                        i = j;
                        break;
                    }
                }
                continue;
            }
            // 注释块
            if (file_content[i] == '/' && file_content[i + 1] == '*')
            {
                // 文件尾注释
                if (i + 1 == file_content.size() - 1)
                {
                    break;
                }
                for (int j = i + 2; j < file_content.size() - 1; j++)
                {
                    // 转义下一个，跳过
                    if (file_content[j] == '\\')
                    {
                        j++;
                    }
                    // 跳转到结束部分后
                    if (file_content[j] == '*' && file_content[j + 1] == '/')
                    {
                        i = j + 2;
                        break;
                    }
                }
                continue;
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
    if (temp == "")
    {
        return;
    }
    file_content_split.push_back(temp);
    return;
}
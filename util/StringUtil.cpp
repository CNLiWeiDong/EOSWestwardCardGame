//
// Created by lwd on 2018/5/30.
//

#include "StringUtil.h"

//分割字符串
vector<string> StringUtil::split(string line, const string delimiter)
{
    vector<string> vec;

    if(line.empty() || delimiter.empty())
    {
        return vec;
    }

    size_t dLen = delimiter.size();
    size_t sbpos = 0;
    size_t spos = line.find(delimiter);

    if (spos == string::npos)
    {
        vec.push_back(line);
        return vec;
    }
    while (spos != string::npos)
    {
        vec.push_back(line.substr(sbpos, spos - sbpos));
        sbpos = spos + dLen;
        spos = line.find(delimiter, sbpos);
    }
    if (sbpos != spos)
    {
        vec.push_back(line.substr(sbpos, spos - sbpos));
    }
    return vec;
}
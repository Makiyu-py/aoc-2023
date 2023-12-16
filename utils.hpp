#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

namespace aoc_utils
{
    string readFile(string fn)
    {
        ifstream file;
        file.open(filesystem::canonical(fn));

        stringstream outstring;
        string line;
        while (getline(file, line))
        {
            outstring << line << '\n';
        }

        file.close();

        return outstring.str();
    }
    vector<string> split_string(string &to_split, string delim)
    {
        string throwaway = to_split;
        vector<string> out;

        size_t pos = 0;
        string token;
        while ((pos = throwaway.find(delim)) != string::npos) {
            token = throwaway.substr(0, pos);
            out.push_back(token);
            throwaway.erase(0, pos + delim.length());
        }
        // last item is out of the loop and becomes throwaway (aka to_split)
        if (!throwaway.empty())
            out.push_back(throwaway);

        return out;
    }

    int char_to_int(char& val)
    {
        return val - '0';
    }
}
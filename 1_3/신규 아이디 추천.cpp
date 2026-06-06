#include <iostream>
#include <string>
#include <vector>

using namespace std;

string Level7(string id)
{
    string res;
    if (id.size() <= 2)
    {
        char lastCh = id.back();

        res = id;

        for (int i = id.size(); i < 3; ++i)
            res += lastCh;
    }
    else
        res = id;

    return res;
}

string Level6(string id)
{
    string res;

    if (id.size() >= 16)
    {
        res = id.substr(0, 15);
        if (res.back() == '.') res.pop_back();
    }
    else
        res = id;

    res = Level7(res);

    return res;
}

string Level5(string id)
{
    string res;

    if (id.empty())
        res = "a";
    else
        res = id;

    res = Level6(res);

    return res;
}

string Level4(string id)
{
    string res;
    size_t id_size = id.size();

    for (int i = 0; i < id_size; ++i)
    {
        if (id[i] == '.')
        {
            if (i == 0 || i == id_size - 1) continue;
        }
        res += id[i];
    };

    res = Level5(res);

    return res;
}

string Level3(string id)
{
    string res;
    bool flag = true;

    for (char ch : id)
    {
        if (ch == '.')
        {
            if(flag)
            {
                res += ch;
                flag = false;
            }
        }
        else
        {
            res += ch;
            flag = true;
        }
    }

    res = Level4(res);

    return res;
}

string Level2(string id)
{
    string res;

    for (char ch : id)
    {
        if (ch >= 'a' && ch <= 'z')
        {
            res += ch;
            continue;
        }
        if (ch >= '0' && ch <= '9')
        {
            res += ch;
            continue;
        }
        if (ch == '-')
        {
            res += ch;
            continue;
        }
        if (ch == '_')
        {
            res += ch;
            continue;
        }
        if (ch == '.')
        {
            res += ch;
            continue;
        }
    }

    res = Level3(res);

    return res;
}

string Level1(string id)
{
    string res;

    for (char ch : id)
        res += tolower(ch);

    res = Level2(res);

    return res;
}

string solution(string new_id) {
    string answer = "";
    answer = Level1(new_id);
    return answer;
}

int main()
{
    string new_id = "abcdefghijklmn.p";

    solution(new_id);

    return 0;
}
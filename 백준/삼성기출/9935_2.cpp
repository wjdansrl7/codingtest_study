// 스택 활용

#include <iostream>
#include <algorithm>
using namespace std;

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s, boom, temp = "";

    cin >> s;
    cin >> boom;

    for (int i = 0; i < s.size(); i++)
    {
        temp += s[i];
        if (temp.back() == boom.back())
        {
            bool ch = true;
            if (temp.size() < boom.sie())
            {
                continue;
            }
            for (int j = 0; j < boom.size(); j++)
            {
                if (temp[temp.size() - boom.size() + j] != boom[j])
                {
                    ch = false;
                    break;
                }
            }
            if (ch)
            {
                for (int j = 0; j < boom.size(); j++)
                {
                    temp.pop_back();
                }
            }
        }
        if (temp.empty())
        {
            cout << "FRULA" << '\n';
        }
        else
            cout << temp << '\n';
    }

    return 0;
}

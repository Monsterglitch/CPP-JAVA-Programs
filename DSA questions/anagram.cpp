#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

bool isAnagram (string s, string t) {
    unordered_map<char, int> mp;
    if (s.size() != t.size())
    {
        return false;
    }
    for (int i : s)
    {
        mp[i] += 1;
    }
    for (int i = 0; i < s.size(); i++)
    {
        if ((mp.find(t[i]) != mp.end()))
        {
            mp[t[i]] = mp[t[i]] - 1;
            if (mp[t[i]] == 0)
            {
                mp.erase(t[i]);
            }
        } else {
            return false;
        }
    }
    return true;
}
int main()
{
    cout<<isAnagram("aacc", "ccac");
    return 0;
}
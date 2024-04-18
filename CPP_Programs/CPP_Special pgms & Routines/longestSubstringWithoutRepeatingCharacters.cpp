#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int lengthOfLongestSubstring(string s) {
    unordered_map<char, int> mp;
    int size = 0, start = 0, end = 0;
    while (end < s.size()) {
        if (mp.find(s[end]) != mp.end() && mp[s[end]] >= start) {
            start = mp[s[end]] + 1;
        }
        mp[s[end]] = end;
        size = max(size, end - start + 1);
        end++;
    }
    return size;
}

int main()
{
    string str = "pwwkew";
    cout<<lengthOfLongestSubstring(str);
    return 0;
}

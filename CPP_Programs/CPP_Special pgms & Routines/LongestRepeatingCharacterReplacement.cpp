#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int characterReplacement (string s, int k) {
    unordered_map<char, int> mp;
    int start = 0, end = 0, res = 0, max_mp = 0;

    for (end = 0; end < s.size(); ++end) {
        mp[s[end]]++;
        max_mp = max(max_mp, mp[s[end]]);

        // If the number of replacements needed is greater than k, shrink the window
        if (end - start + 1 - max_mp > k) {
            mp[s[start]]--;
            start++;
        }

        // Update the result
        res = max(res, end - start + 1);
    }
    return res;
}

int main() {
    int k = 1;
    string str = "AABABBA";
    cout<<characterReplacement(str, k);
    return 0;
}
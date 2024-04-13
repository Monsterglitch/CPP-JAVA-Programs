#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
    public:
        bool isPalindrome(string s) {
            transform(s.begin(), s.end(), s.begin(), ::tolower);
            s.erase(remove_if(s.begin(), s.end(), [](char c) { return !isalnum(c); }), s.end());
            if (s.length() < 1) {
                return true;
            }
            return rec(0, s);
        }

    private:
        static bool rec(int i, const string& s) {
            if (i >= s.length() / 2) {
                return true;
            }
            if (s[i] != s[s.length() - i - 1]) {
                return false;
            }
            return rec(i + 1, s);
        }
};

int main()
{
    string str = "A man, a plan, a canal: Panama";
    Solution s;
    cout<<s.isPalindrome(str);
    return 0;
}
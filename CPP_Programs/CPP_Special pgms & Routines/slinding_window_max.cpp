#include <iostream>
#include <vector>
using namespace std;

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    int l = 0, r = k-1, curr_max = 0;
    vector<int> res;
    while(r != nums.size()) {
        for (int i = l; i <= r; ++i) {
            curr_max = max(curr_max, nums[i]);
        }
        res.push_back(curr_max);
        l++;
        r++;
    }
    return res;
}

int main() {
    vector<int> qn{1, -1}, ans;
    ans = maxSlidingWindow(qn, 1);
    for (int i : ans) {
        cout<<i<<" ";
    }
    return 0;
}
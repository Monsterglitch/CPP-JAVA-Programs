#include <iostream>
#include <vector>
using namespace std;

// class Solution {
// public:
//     vector<int> productExceptSelf(vector<int>& nums) {
//         int n = nums.size();
//         vector<int> prefix(n, 1);
//         vector<int> suffix(n, 1);
//         vector<int> result(n, 1);
//         for (int i = 1; i < n; i++) {
//             prefix[i] = prefix[i - 1] * nums[i - 1];
//         }
//         for (int i = n - 2; i >= 0; i--) {
//             suffix[i] = suffix[i + 1] * nums[i + 1];
//         }
//         for (int i = 0; i < n; i++) {
//             result[i] = prefix[i] * suffix[i];
//         }
//         return result;
//     }
// };

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n, 1);

        for (int i = 1; i < n; i++) {
            result[i] = result[i - 1] * nums[i - 1];
        }

        int suffix_product = 1;
        for (int i = n - 1; i >= 0; i--) {
            result[i] *= suffix_product;
            suffix_product *= nums[i];
        }

        return result;
    }
};

int main()
{
    Solution s;
    vector<int> nums{1, 2, 3, 4};
    vector<int> result = s.productExceptSelf(nums);
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    return 0;
}
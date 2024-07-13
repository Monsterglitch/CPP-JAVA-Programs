#include <iostream>
#include <vector>
using namespace std;

int maxArea (vector<int>& height) {
    int left = 0, right = height.size() - 1, area = 0;
    for (int i = 0; i < height.size(); i++)
    {
        while (left <= right)
        {
            area = max(area, ((right - left) * min(height[left], height[right])));
            if (height[left] < height[right])
            {
                left++;
            }
            else
            {
                right--;
            }
        }
    }
    return area;
}

int main()
{
    vector<int> height{1, 8, 6, 2, 5, 4, 8, 3, 7};
    cout<<maxArea(height);
    return 0;
}


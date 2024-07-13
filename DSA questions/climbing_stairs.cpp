#include <iostream>
using namespace std;

int climbStairs(int n) {
    int one = 1, two = 1, temp = 0;
    for(int i = 0; i < n-1; ++i) {
        temp = one;
        one = one + two;
        two = temp;
    }
    return one;
}

int main()
{
    cout<<climbStairs(5);
    return 0;
}
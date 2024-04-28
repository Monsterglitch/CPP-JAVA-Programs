#include <iostream>
using namespace std;

/*
    Given a target height T and a high jump value HJ, 
    Find the minimum no. of steps possible to attain the target height T.
*/

int flag(int HJ, int T) {
    int res = 0, temp = 0;
    res = T / HJ;
    if (T % HJ == 0) {
        return res;
    } else {
        temp = T - HJ*res;
        res += temp;
    }
    return res;
}

int main()
{
    cout<<flag(3, 8);
    return 0;
}

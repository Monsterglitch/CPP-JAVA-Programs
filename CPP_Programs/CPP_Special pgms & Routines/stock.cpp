#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

// int maxProfit(vector<int>& prices) {
//     if (prices.empty())
//     {
//         return 0;
//     }
//     float inf = INFINITY;
//     float A = -prices[0];
//     float B = inf*-1;
//     float C = inf*-1;
//     float D = inf*-1;

//     for (int i = 0; i < prices.size(); i++)
//     {
//         A = max<float>(A, -prices[i]);
//         B = max<float>(B, A + prices[i]);
//         C = max<float>(C, B - prices[i]);
//         D = max<float>(D, C + prices[i]);
//     }
//     return static_cast<int>(D);
// }

int maxProfit(vector<int>& prices) {
    int t1Cost, t2Cost;
    t1Cost = t2Cost = INT_MAX;
    int t1Profit, t2Profit;
    t1Profit = t2Profit = 0;
    for(int price : prices) {
        t1Cost = min(t1Cost, price);
        t1Profit = max(t1Profit, price - t1Cost);
        t2Cost = min(t2Cost, price - t1Profit);
        t2Profit = max(t2Profit, price - t2Cost);
    }
    return t2Profit;
}

int main()
{
    vector<int> prices{3, 3, 5, 0, 0, 3, 1, 4};
    cout<<"Output: "<<maxProfit(prices);
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

vector<int> leaders(int arr[], int size){
    stack<int> sk;
    vector<int> ans;
    sk.push(arr[size-1]);
    for (int i = size-2; i >= 0; i--)
    {
        if(arr[i] >= sk.top())
        {          
            sk.push(arr[i]);
        }
    }
    while(!sk.empty()){
        ans.push_back(sk.top());
        sk.pop();
    }
    return ans;
}
    
int main()
{
    int arr[] = {16, 17, 4, 3, 5, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    vector<int> res = leaders(arr, n);
    for(auto i: res)
        cout<<i<<" ";
    return 0;
}

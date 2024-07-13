#include <bits/stdc++.h>
using namespace std;

struct List
{
    int profit, weight;
};
bool compareBySize(List a, List b)
{
    return ((a.profit / a.weight) > (b.profit / b.weight));
}
void knapsack (List list[], int weight, int size)
{
    sort(list, list + size, compareBySize);
    int Totalweight = 0;
    float Totalprofit = 0;	
	for (int i = 0; i < size; i++)
	{
		cout << "[" << list[i].profit << "," << list[i].weight
			<< "] ";
		
	    if ((list[i].weight < weight) && ((Totalweight + list[i].weight) <= weight)) 
	    {
	        Totalweight += list[i].weight;
	        Totalprofit += list[i].profit;
	    } 
	    else 
	    {
            int rem = weight - list[i].weight;
            if (rem > 0) 
            {
                // float element = (float(rem) / float(list[i].weight)) * float(list[i].profit);
                float element = (static_cast<float>(rem) / list[i].weight) * list[i].profit;
                Totalprofit += element;
                Totalweight += rem;
            } 
            else 
            {
                continue;
            }
	    }
	}
	cout<<endl<<Totalprofit<<" "<<Totalweight;
}
int main ()
{
    List list[] = {{100, 20}, {60, 10}, {120, 30}};
    int weight = 50;
    int size = sizeof(list) / sizeof(list[0]);
    knapsack(list, weight, size);
    return 0;
}

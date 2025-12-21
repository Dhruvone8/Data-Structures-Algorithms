// GFG Link: https://www.geeksforgeeks.org/problems/fractional-knapsack-1587115620/1

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Item // Create a struct
{
    double value;
    double weight;
};

class Solution
{
public:
    bool static comp(Item a, Item b) //  Create a custom comparator
    {
        double r1 = a.value / a.weight;
        double r2 = b.value / b.weight;
        return r1 > r2;
    }

    double fractionalKnapsack(vector<int> &val, vector<int> &wt, int capacity)
    {
        int n = val.size();
        vector<Item> items(n);

        for (int i = 0; i < n; i++)
        {
            items[i] = {(double)val[i], (double)wt[i]};
        }

        sort(items.begin(), items.end(), comp);

        double maxValue = 0.0;

        for (int i = 0; i < n; i++)
        {
            if (items[i].weight <= capacity) // If the sack has the capacity to hold the entire item
            {
                maxValue += items[i].value;
                capacity -= items[i].weight;
            }

            else
            {
                maxValue += ((items[i].value) / (items[i].weight)) * capacity;
                break;
            }
        }
        return maxValue;
    }
};
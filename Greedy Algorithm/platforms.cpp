// GFG Link: https://www.geeksforgeeks.org/problems/minimum-platforms-1587115620/1

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int minPlatform(vector<int>& arr, vector<int>& dep) 
{
    int n = arr.size();

    sort(arr.begin(), arr.end());
    sort(dep.begin(), dep.end());

    int count = 0;
    int max_count = 0; // Storing maximum intersections between train time

    int a = 0;
    int b = 0;

    while(a < n && b < n)
    {
        if(arr[a] <= dep[b]) // Train Arrived before the departure 
        {
            count++;
            a++;
        }
        
        else    // Train departed before the arrival 
        {
            count--;
            b++;
        }

        max_count = max(max_count, count);
    }

    return max_count;
}

int main()
{
    
    return 0;
}
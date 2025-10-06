// https://www.geeksforgeeks.org/problems/union-of-two-sorted-arrays-1587115621/1

#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;

vector<int> findUnion(vector<int> &a, vector<int> &b) 
{
    int n = a.size();
    int m = b.size();
    vector<int> unarr;
    
    int i = 0;
    int j = 0;
    
    while(i < n && j < m)
    {
        if(a[i] <= b[j])
        {
            if(unarr.size() == 0 || unarr.back() != a[i])
            {
                unarr.push_back(a[i]);
            }
            
            i++;
        }
        
        else
        {
            if(unarr.size() == 0 || unarr.back() != b[j])
            {
                unarr.push_back(b[j]);
            }
            
            j++;
        }
    }
    
    while(j < m)
    {
        if(unarr.size() == 0 || unarr.back() != b[j])
        {
            unarr.push_back(b[j]);
        }
            
        j++;
    }
    
    while(i < n)
    {
        if(unarr.size() == 0 || unarr.back() != a[i])
        {
            unarr.push_back(a[i]);
        }
        
        i++;
    }
    
    return unarr;
}
// Leetcode Link: https://leetcode.com/problems/merge-sorted-array/description/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// Using Extra Space 
void merge1(vector<int>& nums1, int m, vector<int>& nums2, int n) 
{
    int first = 0;
    int second = 0;
    vector<int> temp;

    while(first < m && second < n)
    {
        if(nums1[first] <= nums2[second])
        {
            temp.push_back(nums1[first]);
            first++;
        }
        else
        {
            temp.push_back(nums2[second]);
            second++;
        }
    }

    while(first < m)
    {
        temp.push_back(nums1[first]);
        first++;
    }

    while(second < n)
    {
        temp.push_back(nums2[second]);
        second++;
    }

    for(int i = 0; i < temp.size(); i++)
    {
        nums1[i] = temp[i];
    }
}

// Using Constant Space
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) 
{
    int left = m - 1;
    int right = 0;
    while(left >= 0 && right < n)
    {
        if(nums1[left] > nums2[right])
        {
            swap(nums1[left], nums2[right]);
            left--;
            right++;
        }
        else
        {
            break;
        }
    }

    sort(nums1.begin(), nums1.begin() + m);
    sort(nums2.begin(), nums2.end());

    for(int i = 0; i < n; i++)
    {
        nums1[i + m] = nums2[i];
    }
}

int main()
{
    
    return 0;
}
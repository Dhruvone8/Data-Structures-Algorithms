// Leetcode Link: https://leetcode.com/problems/median-of-two-sorted-arrays/description/

#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

// Better Solution
// T.C : O(n)
// S.C : O(1)
double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
{
    int n1 = nums1.size();
    int n2 = nums2.size();
    int i = 0;
    int j = 0;
    int n = (n1 + n2);
    int index2 = n / 2;
    int index1 = index2 - 1;
    int count = 0;
    int el1 = -1;
    int el2 = -1;

    while (i < n1 && j < n2)
    {
        if (nums1[i] < nums2[j])
        {
            if (count == index1)
            {
                el1 = nums1[i];
            }

            if (count == index2)
            {
                el2 = nums1[i];
            }

            i++;
            count++;
        }

        else 
        {
            if(count == index1)
            {
                el1 = nums2[j];
            }
            if(count == index2)
            {
                el2 = nums2[j];
            }

            j++;
            count++;
        }
    }

    while(i < n1)
    {
        if(count == index1)
        {
            el1 = nums1[i];
        }

        if(count == index2)
        {
            el2 = nums1[i];
        }

        count++;
        i++;
    }

    while(j < n2)
    {
        if(count == index1)
        {
            el1 = nums2[j];
        }

        if(count == index2)
        {
            el2 = nums2[j];
        }

        count++;
        j++;
    }

    if(n % 2 == 1)
    {
        return el2;
    }

    return (el1 + el2) / 2.0;
}

// Optimal Solution
double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
{
    
}

int main()
{

    return 0;
}
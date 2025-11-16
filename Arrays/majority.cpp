// Leetcode Link: https://leetcode.com/problems/majority-element-ii/

// There will be at max 2 elements which will appear more than [n/3] times

#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
using namespace std;

vector<int> majorityElement(vector<int> &nums) // Better Solution
{
    int n = nums.size();
    unordered_map<int, int> hash;
    vector<int> ans;

    int mini = int(n / 3) + 1;

    for (int i = 0; i < n; i++)
    {
        hash[nums[i]]++;

        if (hash[nums[i]] == mini)
        {
            ans.push_back(nums[i]);
        }

        if (ans.size() == 2)
        {
            break;
        }
    }

    return ans;
}

vector<int> majorityElementOpt(vector<int> &nums)
{
    int n = nums.size();
    int count1 = 0;
    int count2 = 0;
    int element1 = INT16_MIN;
    int element2 = INT16_MIN;
    vector<int> ans;

    for (int i = 0; i < n; i++)
    {
        if (count1 == 0 && nums[i] != element2)
        {
            count1 = 1;
            element1 = nums[i];
        }

        else if (count2 == 0 && nums[i] != element1)
        {
            count2 = 1;
            element2 = nums[i];
        }

        else if (element1 == nums[i])
        {
            count1++;
        }

        else if (element2 == nums[i])
        {
            count2++;
        }

        else
        {
            count1--;
            count2--;
        }
    }

    count1 = 0;
    count2 = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        if (element1 == nums[i])
        {
            count1++;
        }

        if (element2 == nums[i])
        {
            count2++;
        }
    }

    int minel = (n / 3) + 1;
    if (count1 >= minel)
    {
        ans.push_back(element1);
    }

    if (count2 >= minel)
    {
        ans.push_back(element2);
    }

    return ans;
}
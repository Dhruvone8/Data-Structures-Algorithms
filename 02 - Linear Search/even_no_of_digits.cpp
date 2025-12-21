#include <iostream>
#include <vector>
using namespace std;

// Leetcode Link: https://leetcode.com/problems/find-numbers-with-even-number-of-digits?envType=problem-list-v2&envId=array

class Solution
{
public:
    int findNumbers(vector<int> &nums)
    {
        int evencount = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            int count = 0;
            while (nums[i] > 0)
            {
                count++;
                nums[i] /= 10;
            }
            if (count % 2 == 0)
            {
                evencount++;
            }
        }
        return evencount;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {12, 345, 2, 6, 7896};
    int answer = s.findNumbers(nums);
    cout << answer;
}
#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
using namespace std;

vector<int> maxSlidingWindow(vector<int> &nums, int k)
{
    vector<int> ans;
    deque<int> dq;

    for (int i = 0; i < nums.size(); i++)
    {
        if (!dq.empty() && dq.front() <= (i - k)) // Maintaning correct window elements
        {
            dq.pop_front();
        }

        while (!dq.empty() && nums[dq.back()] <= nums[i]) // Maintaining monotonic decreasing order in the deque
        {
            dq.pop_back();
        }

        dq.push_back(i);   

        if (i >= k - 1)     // A window starts from k - 1
        {
            ans.push_back(nums[dq.front()]);
        }
    }

    return ans;
}

int main()
{
    vector<int> arr = {1, 3, -1, -3, 5, 3, 6, 7};

    vector<int> ans = maxSlidingWindow(arr, 3);

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}
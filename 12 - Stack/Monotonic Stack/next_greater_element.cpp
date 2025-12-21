#include <iostream>
#include <vector>
#include <map>
#include <stack>
using namespace std;

vector<int> nextGreaterElement1(vector<int> &nums)  // Maintain a decreasing order in the monotonic stack
{
    int n = nums.size();
    stack<int> st;
    vector<int> ans(n);

    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && st.top() <= nums[i])
        {
            st.pop();
        }

        if (st.empty())
        {
            ans[i] = -1;
        }
        else
        {
            ans[i] = st.top();
        }

        st.push(nums[i]);
    }

    return ans;
}

vector<int> nextGreaterElement2(vector<int> &nums) // Circular Array
{
    int n = nums.size();
    stack<int> st;
    vector<int> res(n);

    // Double the array hypothetically to behave it like a circular array
    for (int i = 2 * n - 1; i >= 0; i--)
    {
        while (!st.empty() && st.top() <= nums[i % n])
        {
            st.pop();
        }

        // Find NGE for only i < n
        if (i < n)
        {
            if (st.empty())
            {
                res[i] = -1;
            }

            else
            {
                res[i] = st.top();
            }
        }

        st.push(nums[i % n]);
    }

    return res;
}

int main()
{
    vector<int> nums1 = {11, 4, 5, 9};

    vector<int> ans = nextGreaterElement1(nums1);

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}

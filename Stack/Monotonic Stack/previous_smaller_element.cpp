#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> previous_smaller_element(vector<int> &nums)
{
    stack<int> st;
    int n = nums.size();
    vector<int> ans(n);

    for (int i = 0; i < nums.size(); i++)
    {
        while (!st.empty() && nums[i] <= st.top())
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

int main()
{
    vector<int> arr = {5, 7, 9, 6, 4, 1, 3, 8};
    vector<int> ans = previous_smaller_element(arr);

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}
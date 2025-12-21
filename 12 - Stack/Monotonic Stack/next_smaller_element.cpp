#include<iostream>
#include<vector>
#include<stack>
using namespace std;

vector<int> nextSmallerElement(vector<int> &nums)      // Maintain a increasing order in the monotonic stack
{
    int n = nums.size();
    stack<int> st;
    vector<int> ans(n);

    for(int i = n - 1; i >= 0; i--)
    {
        while(!st.empty() && st.top() >= nums[i])
        {
            st.pop();
        }

        if(st.empty())
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
    vector<int> arr = {10, 9, 8, 7};

    vector<int> ans = nextSmallerElement(arr);
    for(int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}
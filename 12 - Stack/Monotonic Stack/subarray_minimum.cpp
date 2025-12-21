#include <iostream>
#include <stack>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> nextSmallerElement(vector<int> &arr)
{
    int n = arr.size();
    vector<int> nse(n);
    stack<int> st;

    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && arr[st.top()] > arr[i])
        {
            st.pop();
        }

        if (st.empty())
        {
            nse[i] = n;
        }

        else
        {
            nse[i] = st.top();
        }

        st.push(i);
    }

    return nse;
}

vector<int> previousSmallerOrEqualElement(vector<int> &arr)
{
    stack<int> st;
    int n = arr.size();
    vector<int> ans(n);

    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && arr[st.top()] >= arr[i])
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

        st.push(i);
    }

    return ans;
}

int sumSubarrayMins(vector<int> &arr)
{
    vector<int> nse = nextSmallerElement(arr);
    vector<int> pse = previousSmallerOrEqualElement(arr);
    int sum = 0;
    int m = 1e9 + 7;

    for (int i = 0; i < arr.size(); i++)
    {
        // Calculate number of elements present on the left
        int left = i - pse[i];

        // Calculate number of elements present on the right
        int right = nse[i] - i;

        sum = (sum + (right * left * arr[i])) % m;
    }

    return sum;
}

int main()
{
    vector<int> arr = {73, 55, 83, 55};

    cout << sumSubarrayMins(arr);

    return 0;
}
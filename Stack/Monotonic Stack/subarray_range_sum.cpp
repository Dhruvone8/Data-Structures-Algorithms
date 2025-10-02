#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

vector<int> nextSmallerElement(vector<int> &arr)
{
    int n = arr.size();
    vector<int> nse(n);
    stack<int> st;

    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && arr[st.top()] >= arr[i])
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
    int n = arr.size();
    vector<int> pse(n);
    stack<int> st;

    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && arr[st.top()] > arr[i])
        {
            st.pop();
        }

        if (st.empty())
        {
            pse[i] = -1;
        }

        else
        {
            pse[i] = st.top();
        }

        st.push(i);
    }

    return pse;
}

int sumSubarrayMins(vector<int> &arr)
{
    vector<int> pse = previousSmallerOrEqualElement(arr);
    vector<int> nse = nextSmallerElement(arr);
    int n = arr.size();
    long long sum = 0;
    int m = 1e9 + 7;

    for(int i = 0; i < n; i++)
    {
        int left = i - pse[i];
        int right = nse[i] - i;

        sum = (sum + (1LL * right * left * arr[i])) % m;
    }

    return sum;
}

vector<int> nextGreaterElement(vector<int> &arr)
{
    int n = arr.size();
    vector<int> nge(n);
    stack<int> st;

    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && arr[st.top()] <= arr[i])
        {
            st.pop();
        }

        if (st.empty())
        {
            nge[i] = n;
        }

        else
        {
            nge[i] = st.top();
        }

        st.push(i);
    }

    return nge;
}

vector<int> previousGreaterOrEqualElement(vector<int> &arr)
{
    int n = arr.size();
    vector<int> pge(n);
    stack<int> st;

    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && arr[st.top()] < arr[i])
        {
            st.pop();
        }

        if (st.empty())
        {
            pge[i] = -1;
        }

        else
        {
            pge[i] = st.top();
        }

        st.push(i);
    }

    return pge;
}

int sumSubarrayMaxs(vector<int> &arr)
{
    vector<int> pge = previousGreaterOrEqualElement(arr);
    vector<int> nge = nextGreaterElement(arr);
    int n = arr.size();
    long long sum = 0;
    int m = 1e9 + 7;

    for(int i = 0; i < n; i++)
    {
        int left = i - pge[i];
        int right = nge[i] - i;

        sum = (sum + (1LL * right * left * arr[i])) % m;
    }

    return sum;
}

long long subArrayRanges(vector<int> &nums)
{
    long long min = sumSubarrayMins(nums);
    long long max = sumSubarrayMaxs(nums);

    return max - min;
}

int main()
{
    vector<int> arr = {1, 4, 3};

    cout << subArrayRanges(arr);

    return 0;
}
// Return the area of largest rectangle in the histogram

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
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

vector<int> previousSmallerElement(vector<int> &arr)
{
    int n = arr.size();
    vector<int> pse(n);
    stack<int> st;

    for (int i = 0; i < arr.size(); i++)
    {
        while (!st.empty() && arr[st.top()] >= arr[i])
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

int largestRectangleArea(vector<int> &heights)
{
    vector<int> nse = nextSmallerElement(heights);
    vector<int> pse = previousSmallerElement(heights);

    int max_rec = 0;

    for (int i = 0; i < heights.size(); i++)
    {
        int area = heights[i] * (abs(nse[i] - pse[i]) - 1);

        max_rec = max(max_rec, area);
    }

    return max_rec;
}

// Most Optimal Solution
// Two Pointer Approach

int largestRectangleAreaOptimal(vector<int> &heights)
{
    int n = heights.size();
    stack<int> st;
    int max_rec = 0;
    int pse;
    int nse;
    int element;
    int area;

    for (int i = 0; i < heights.size(); i++)
    {
        while (!st.empty() && heights[st.top()] > heights[i])
        {
            element = st.top();
            st.pop();

            nse = i;
            if (st.empty())
            {
                pse = -1;
            }
            else
            {
                pse = st.top();
            }

            area = heights[element] * (nse - pse - 1);
            max_rec = max(max_rec, area);
        }

        st.push(i);
    }

    while (!st.empty()) // There are still elements left in the stack, the nse of these elements will be n
    {
        nse = n;
        element = st.top();
        st.pop();

        if (st.empty())
        {
            pse = -1;
        }
        else
        {
            pse = st.top();
        }

        area = heights[element] * (nse - pse - 1);
        max_rec = max(area, max_rec);
    }

    return max_rec;
}

int main()
{
    vector<int> arr = {4, 3, 5, 5, 9, 2, 8, 4, 7, 2, 3, 8, 3, 5, 4, 7, 9};

    cout << largestRectangleAreaOptimal(arr);

    return 0;
}

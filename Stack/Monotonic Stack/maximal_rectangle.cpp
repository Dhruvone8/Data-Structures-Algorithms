#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

int largestRectangleArea(vector<int> &heights)
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

int maximalRectangle(vector<vector<char>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();
    int max_area = 0;

    vector<vector<int>> prefixSum(n, vector<int>(m));

    // calculate Prefix Sum for each row
    for (int j = 0; j < m; j++)
    {
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            if (matrix[i][j] == '1')
            {
                sum++;
                prefixSum[i][j] = sum;
            }
            
            else if(matrix[i][j] == '0')
            {
                sum = 0;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        max_area = max(max_area, largestRectangleArea(prefixSum[i]));
    }

    return max_area;
}

int main()
{
    vector<vector<char>> matrix = {{'1', '0', '1', '0', '0'},
                                   {'1', '0', '1', '1', '1'},
                                   {'1', '1', '1', '1', '1'},
                                   {'1', '0', '0', '1', '0'}};

    cout << maximalRectangle(matrix);

    return 0;
}
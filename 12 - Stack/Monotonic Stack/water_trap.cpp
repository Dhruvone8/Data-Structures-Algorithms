#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

int trap(vector<int> &height)
{
    // Calcuate PrefixMax and SuffixMax

    int n = height.size();
    int total = 0;

    vector<int> PrefixMax(n);
    PrefixMax[0] = height[0];

    for (int i = 1; i < n; i++)
    {
        PrefixMax[i] = max(height[i], PrefixMax[i - 1]);
    }

    vector<int> SuffixMax(height.size());
    SuffixMax[n - 1] = height[n - 1];

    for (int i = n - 2; i >= 0; i--)
    {
        SuffixMax[i] = max(height[i], SuffixMax[i + 1]);
    }

    for (int i = 0; i < n; i++)
    {
        if (PrefixMax[i] > height[i] && SuffixMax[i] > height[i])
        {
            int minHeight = min(PrefixMax[i], SuffixMax[i]);
            total += minHeight - height[i];
        }
    }

    return total;
}

// Most Optimal Solution
// Two Pointer Approach

int trapOpt(vector<int> &arr)
{
    int n = arr.size();

    int left = 0;
    int right = n - 1;

    int units = 0;

    int leftMax = 0;
    int rightMax = 0;

    while (left < right)
    {
        if (arr[left] <= arr[right]) // There is a taller building at the right so we can check for left
        {
            if (leftMax > arr[left]) // There is a taller building on the left so water can be stored
            {
                units += leftMax - arr[left];
            }

            else // There is no building on the left or there is no building to the left that is taller than current one
            {
                leftMax = arr[left];
            }

            left++;
        }

        else // Building at the left is taller so check for right
        {
            if (rightMax > arr[right]) // There is a taller building on the right so water can be stored
            {
                units += rightMax - arr[right];
            }

            else
            {
                rightMax = arr[right];
            }

            right--;
        }
    }

    return units;
}

int main()
{
    vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};

    cout << trapOpt(height);

    return 0;
}
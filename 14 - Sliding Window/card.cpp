// Leetcode Link: https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/description/

#include <iostream>
#include <vector>
#include <algorithm>
#include<numeric>
using namespace std;

int maxScore(vector<int> &cardPoints, int k)
{
    int n = cardPoints.size();

    if(n == k)
    {
        int ans = std::accumulate(cardPoints.begin(), cardPoints.end(), 0);
        return ans;
    }

    int leftSum = 0;
    int rightSum = 0;
    int maxSum = 0;

    for (int i = 0; i < k; i++)
    {
        leftSum = leftSum + cardPoints[i];
    }

    maxSum = leftSum;
    int rindex = n - 1;

    for (int i = k - 1; i >= 0; i--)
    {
        leftSum = leftSum - cardPoints[i];
        rightSum = rightSum + cardPoints[rindex];
        rindex--;

        maxSum = max(maxSum, leftSum + rightSum);
    }

    return maxSum;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6, 1};

    cout << maxScore(arr, 3);

    return 0;
}
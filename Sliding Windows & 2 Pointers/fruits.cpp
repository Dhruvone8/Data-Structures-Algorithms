// Leetcode Link: https://leetcode.com/problems/fruit-into-baskets/description/

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;


// Time Complexity : O(2N)
int totalFruit(vector<int> &fruits)
{
    int n = fruits.size();
    int left = 0;
    int right = 0;
    int max_fruits = 0;
    unordered_map<int, int> hash;

    while (right < n)
    {
        hash[fruits[right]]++;

        if (hash.size() > 2)
        {
            while (hash.size() > 2)
            {
                hash[fruits[left]]--;
                if (hash[fruits[left]] == 0)
                {
                    hash.erase(fruits[left]);
                }
                left++;
            }
        }

        if(hash.size() <= 2)
        {
            max_fruits = max(max_fruits, right - left + 1);
        }

        right++;
    }

    return max_fruits;
}

int main()
{

    return 0;
}
// Leetcode Link: https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int numberOfSubstrings(string s)
{
    int n = s.length();
    int right = 0;
    int left = 0;
    int count = 0;
    vector<int> hash(3, -1);

    for (int i = 0; i < n; i++)
    {
        hash[s[i] - 'a'] = i;

        if (hash[0] != -1 && hash[1] != -1 && hash[2] != -1) // All the 3 char is seen
        {
            int min_index1 = min(hash[0], hash[1]);
            int min_index = min(min_index1, hash[2]);
            count += (1 + min_index);
        }
    }
    return count;
}

int main()
{
    string s = "abcabc";
    cout << numberOfSubstrings(s);
    return 0;
}
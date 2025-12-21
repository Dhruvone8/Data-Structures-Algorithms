// Leetcode Link: https://leetcode.com/problems/longest-repeating-character-replacement/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int characterReplacement(string s, int k)
{
    int n = s.length();
    vector<int> hash(26, 0);
    int left = 0;
    int right = 0;
    int maxlength = 0;
    int maxfrequency = 0;

    while (right < n)
    {
        hash[s[right] - 'A']++;
        maxfrequency = max(maxfrequency, hash[s[right] - 'A']);

        while ((right - left + 1) - maxfrequency > k) // If the length of the string isn't valid, shrink the window size
        {
            hash[s[left] - 'A']--;
            maxfrequency = 0;
            for (int i = 0; i < 26; i++)
            {
                maxfrequency = max(maxfrequency, hash[i]);
            }
            
            left++;
        }

        if ((right - left + 1) - maxfrequency <= k) // If the length of the string is valid
        {
            maxlength = max(maxlength, right - left + 1);
        }

        right++;
    }

    return maxlength;
}

int main()
{
    string s = "ABAB";

    cout << characterReplacement(s, 2);

    return 0;
}
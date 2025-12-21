// Leetcode Link: https://leetcode.com/problems/longest-substring-without-repeating-characters/

#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;

int lengthOfLongestSubstring(string s) 
{
    int n = s.length();
    int length;
    int maxlength = 0;
    int left = 0;
    int right = 0;

    vector<int> hash(255, -1);
    
    while(right < n)
    {
        if(hash[s[right]] != -1)   // The char is already present in the hashmap
        {
            if(hash[s[right]] >= left)  // Check if the last occurence of the char is within the substring and not before it 
            {
                left = hash[s[right]] + 1;
            }
        }

        length = right - left + 1;
        maxlength = max(length, maxlength);
        
        hash[s[right]] = right; // Store the char traversed
        right++;
    }

    return maxlength;
}

int main()
{
    string s = "pwwkew";
    int ans = lengthOfLongestSubstring(s);
    cout << ans;
    return 0;
}
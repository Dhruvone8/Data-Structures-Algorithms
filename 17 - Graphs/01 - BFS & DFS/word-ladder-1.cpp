// Leetcode Link: https://leetcode.com/problems/word-ladder/

#include <bits/stdc++.h>
using namespace std;

int ladderLength(string beginWord, string endWord, vector<string> &wordList)
{
    int n = wordList.size();

    // For each char in each word, try all letters from a-z and check whether it exists in the wordList
    queue<pair<string, int>> q;

    // Push the first starting word to the queue along with its level
    q.push({beginWord, 1});

    // Set for O(1) lookup for linear search
    unordered_set<string> st(wordList.begin(), wordList.end());

    // Erase the word from the set after its visited
    st.erase(beginWord);

    while (!q.empty())
    {
        string word = q.front().first;
        int len = q.front().second;
        q.pop();
        if (word == endWord)
        {
            return len;
        }

        // for every char in every word, check chars from a-z
        for (int i = 0; i < word.length(); i++)
        {
            char original = word[i];
            for (char ch = 'a'; ch <= 'z'; ch++)
            {
                word[i] = ch;
                if (st.find(word) != st.end())
                {
                    st.erase(word);
                    q.push({word, len + 1});
                }
            }
            word[i] = original;
        }
    }

    return 0;
}
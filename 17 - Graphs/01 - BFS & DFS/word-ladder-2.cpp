// Leetcode Link: https://leetcode.com/problems/word-ladder-ii/

#include <bits/stdc++.h>
using namespace std;

vector<vector<string>> findLadders(string beginWord, string endWord, vector<string> &wordList)
{
    // Set for fast lookup
    unordered_set<string> st(wordList.begin(), wordList.end());

    // Queue to store the sequence
    queue<vector<string>> q;

    q.push({beginWord});

    vector<string> usedonLevel;

    usedonLevel.push_back(beginWord);
    int level = 0;

    vector<vector<string>> ans;

    while (!q.empty())
    {
        vector<string> words = q.front();
        q.pop();

        // Erase all the words that have been used in the previous level
        if (words.size() > level)
        {
            level++;
            for (auto it : usedonLevel)
            {
                st.erase(it);
            }
            usedonLevel.clear();
        }

        // The last word in the array / list
        string word = words.back();

        if (word == endWord)
        {
            if (ans.size() == 0)
            {
                ans.push_back(words);
            }
            else if (ans[0].size() == words.size())
            {
                ans.push_back(words);
            }
        }

        for (int i = 0; i < word.size(); i++)
        {
            char original = word[i];
            for (char ch = 'a'; ch <= 'z'; ch++)
            {
                word[i] = ch;
                if (st.find(word) != st.end())
                {
                    words.push_back(word);

                    q.push(words);

                    // Mark as visited on the level
                    usedonLevel.push_back(word);

                    words.pop_back();
                }
            }

            word[i] = original;
        }
    }

    return ans;
}

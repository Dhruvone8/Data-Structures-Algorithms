// Leetcode Link: https://leetcode.com/problems/generate-parentheses

#include <iostream>
#include <vector>
using namespace std;

vector<string> result;

bool isValid(string s)
{
    int count = 0;
    for (auto ch : s)
    {
        if (ch == '(')
        {
            count++;
        }
        if (ch == ')')
        {
            count--;
        }
        if (count < 0) // At any instance if count value becomes less than 0, the parentheses becomes invalid
        {
            return false;
        }
    }
    return count == 0;
}

void generate(string s, int n)
{
    if (s.length() == 2 * n)
    {
        if (isValid(s))
        {
            result.push_back(s);
        }
        return;
    }

    s.push_back('('); // Take an opening parentheses
    generate(s, n);

    s.pop_back(); // Remove the opening the parentheses

    s.push_back(')'); // Take closing parentheses
    generate(s, n);

    s.pop_back(); // Remove the closing parentheses again
}

vector<string> generateParenthesis(int n)
{
    generate("", n);
    return result;
}

int main()
{
    vector<string> ans = generateParenthesis(3);
    for (auto i : ans)
    {
        cout << i << " ";
    }
    return 0;
}
#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> asteroidCollision(vector<int> &asteroids)   // Using Stack
{

    stack<int> st;
    vector<int> ans;

    for (int i = 0; i < asteroids.size(); i++)
    {
        if (asteroids[i] > 0) // Push Positive element to the stack
        {
            st.push(asteroids[i]);
        }

        else
        {
            while (!st.empty() && st.top() > 0 && abs(asteroids[i]) > st.top())
            {
                st.pop();
            }

            if (!st.empty() && st.top() > 0 && abs(asteroids[i]) == st.top())
            {
                st.pop();
                continue;
            }

            if (!st.empty() && st.top() > 0 && abs(asteroids[i]) < st.top())
            {
                continue;
            }

            if (st.empty() || st.top() < 0)
            {
                st.push(asteroids[i]);
            }
        }
    }

    while (!st.empty())
    {
        ans.push_back(st.top());
        st.pop();
    }

    reverse(ans.begin(), ans.end());
    return ans;
}

vector<int> asteroidCollision2(vector<int> &asteroids)  // Using Array
{

    vector<int> ans;

    for (int i = 0; i < asteroids.size(); i++)
    {
        if (asteroids[i] > 0) // Push Positive element to the stack (asteroid moving to the right)
        {
            ans.push_back(asteroids[i]);
        }

        else // If Element is negative (asteroid moving to the left)
        {
            // If size of asteroid moving to the left is bigger than the size of asteroid moving to the right
            while (ans.size() != 0 && ans.back() > 0 && abs(asteroids[i]) > ans.back())
            {
                ans.pop_back();
            }

            // If the size of asteroid moving to the left is equal to the size of asteroid moving to the right
            if (ans.size() != 0 && ans.back() > 0 && abs(asteroids[i]) == ans.back())
            {
                ans.pop_back();
                continue;
            }

            // If the size of asteroid moving to the left is less than the size of asteroid moving to the right
            if (ans.size() != 0 && ans.back() > 0 && abs(asteroids[i]) < ans.back())
            {
                continue;
            }

            // If the stack is empty (all the asteroids moving to the right are destroyed)
            // Or the asteroid at the front/top is moving to the left (Even if there arrives a rightwards moving asteroid afterwards it won't affect it)
            if (ans.size() == 0 || ans.back() < 0)
            {
                ans.push_back(asteroids[i]);
            }
        }
    }

    return ans;
}

int main()
{
    vector<int> asteroids = {4, 7, 1, 1, 2, -3, -7, 17, 15, -18, -19};

    vector<int> ans = asteroidCollision(asteroids);

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}
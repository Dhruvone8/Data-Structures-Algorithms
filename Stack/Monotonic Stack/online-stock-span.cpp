#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

class StockSpanner
{
public:

    stack<pair<int,int>> st;
    int index = -1;
    int ans = 1; 

    StockSpanner()
    {
        index = -1;     
    }

    int next(int price)
    {
        index = index + 1;

        while(!st.empty() && st.top().first <= price)
        {
            st.pop();
        }

        if(!st.empty())
        {
            ans = index - st.top().second;
        }

        else 
        {
            ans = index + 1;
        }
        
        st.push({price, index});
    
        return ans;
    }
};

int main()
{
    StockSpanner s;
    cout << s.next(100) << endl;
    cout << s.next(80) << endl;
    cout << s.next(60) << endl;
    cout << s.next(70) << endl;
    cout << s.next(60) << endl;
}
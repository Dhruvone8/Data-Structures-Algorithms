// Find the elements in the array whose sum is equal to k

#include <iostream>
#include <vector>
using namespace std;

void array_sum(int index, vector<int> ans, int s, int sum, vector<int> arr)
{
    if (index == arr.size())
    {
        if(s == sum)
        {
            for (int i = 0; i < ans.size(); i++)
            {
                cout << ans[i] << " ";
            }
            cout << endl;
        }
        return;
    }

    int value = arr[index];
    vector<int> newans = ans;
    newans.push_back(value);

    array_sum(index + 1, newans, s + value, sum, arr);
    array_sum(index + 1, ans, s, sum, arr);
}

int main()
{
    vector<int> arr = {1,2,1};
    array_sum(0, {}, 0, 2, arr);
    return 0;
}
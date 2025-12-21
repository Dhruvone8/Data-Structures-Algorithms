#include <iostream>
#include <vector>
using namespace std;

void permutations(string p, string up)
{
    if (up.length() == 0)
    {
        cout << p << endl;
        return;
    }

    char ch = up[0];

    for (int i = 0; i <= p.length(); i++)
    {
        string first = p.substr(0, i);
        string second = p.substr(i, p.length());
        permutations(first + ch + second, up.substr(1));
    }
}

vector<string> permutations_in_array(string p, string up)
{
    if (up.length() == 0)
    {
        vector<string> arr;
        arr.push_back(p);
        return arr;
    }

    char ch = up[0];
    vector<string> ans;

    for (int i = 0; i <= p.length(); i++)
    {
        string first = p.substr(0, i);
        string second = p.substr(i);

        // recursive call
        vector<string> temp = permutations_in_array(first + ch + second, up.substr(1));

        // append all results from temp into ans
        for (string s : temp)
        {
            ans.push_back(s);
        }
    }

    return ans;
}

int main()
{
    permutations("", "abc");
    cout << endl;
    vector<string> arr = permutations_in_array("", "abc");

    cout << "[";
    for (size_t i = 0; i < arr.size(); i++)
    {
        cout << arr[i];
        if (i != arr.size() - 1)
        {
            cout << ", ";
        }
    }
    cout << "]" << endl;
    return 0;
}
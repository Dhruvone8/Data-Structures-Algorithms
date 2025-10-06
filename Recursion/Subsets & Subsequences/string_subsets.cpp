/* Use Cases:
Premutations and Combinations
Subsets
*/

/* Print all the subsets of a string */

#include <iostream>
#include <vector>
using namespace std;

void string_subsets(string p, string up)
{
    if (up.empty())
    {
        cout << p << " ";
        return;
    }

    char ch = up[0];

    string_subsets(p + ch, up.substr(1));
    string_subsets(p, up.substr(1));
}

int main()
{
    string_subsets("", "abc");
    return 0;
}
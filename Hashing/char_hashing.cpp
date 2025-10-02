#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<char> arr = {'M', 'U', 'M', 'B', 'A', 'I'};

    vector<int> hash(26, 0);

    for (int i = 0; i < arr.size(); i++)
    {
        hash[arr[i] - 'A']++;
    }

    char alphabet;
    cout << "Enter alphabet whose frequency you need: ";
    cin >> alphabet;

    cout << "The frequency of " << alphabet << " is " << hash[alphabet - 'A'] << endl;
    return 0;
}
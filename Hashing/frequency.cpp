#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 3, 4, 7, 9, 10};
    vector<int> hash(15, 0);

    for (int i = 0; i < arr.size(); i++)
    {
        hash[arr[i]]++;
    }

    int element;
    cout << "Enter element whose frequency you need: ";
    cin >> element;

    cout << "The frequency of " << element << " is " << hash[element] << endl;
    return 0;
}
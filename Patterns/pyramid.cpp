#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter the value of n: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++) // Spaces
        {
            cout << " ";
        }

        for (int j = 1; j <= i + 1; j++)    // Left part of numbers
        {
            cout << j;
        }

        for(int j = i; j > 0; j--)
        {
            cout<<j;
        }

        cout<<endl;
    }
    return 0;
}
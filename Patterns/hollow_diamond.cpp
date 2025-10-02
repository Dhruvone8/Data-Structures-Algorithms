#include <iostream>
using namespace std;
int main()
{
    int n;
    cout << "Enter value of n: ";
    cin >> n;

    // Top Part
    for (int i = 0; i < n; i++) // Outer Loop
    {
        for (int j = 0; j < n - i - 1; j++) // Spaces
        {
            cout << " ";
        }

        cout << "*"; // Star

        if (i != 0) // Spaces (only for i > 0)
        {
            for (int j = 0; j < 2 * i - 1; j++)
            {
                cout << " ";
            }
            cout << "*";
        }

        cout << endl;
    }

    // Bottom Part
    for (int i = 0; i < n - 1; i++) // Outer Loop
    {
        for (int j = 0; j < i + 1; j++) // Spaces
        {
            cout << " ";
        }
        cout << "*";

        if(i != n - 2)
        {
            for (int j = 0; j < 2 * (n - i) - 5; j++)
            {
                cout << " ";
            }
            cout << "*";
       }
        cout << endl;
    }

    return 0;
}
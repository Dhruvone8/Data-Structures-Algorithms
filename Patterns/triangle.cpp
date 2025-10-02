#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter the value of n: ";
    cin >> n;

    cout << "1. Star Pattern: " << endl;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << "* ";
        }
        cout << endl;
    }

    cout << "\n2. Reverse Triangle Pattern: " << endl;
    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j >= 1; j--)
        {
            cout << j << " ";
        }
        cout << endl;
    }

    int num = 1;

    cout << "\n3. Flyod's Triangle Pattern: " << endl;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << num << " ";
            num++;
        }
        cout << endl;
    }

    cout << "\n4. Inverted Triangle Pattern: " << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++) // Print Spaces
        {
            cout << " ";
        }

        for (int j = 0; j < n - i; j++)
        {
            cout << i + 1;
        }
        cout << endl;
    }

    return 0;
}

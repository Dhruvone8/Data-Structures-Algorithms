#include <iostream>
#include <vector>
using namespace std;

int count = 1;

void name(int count, int n, string a)
{
    if (count > n)
    {
        return;
    }

    cout << a << endl;

    return name(count + 1, n, a);
}

int main()
{
    int n;
    string a;
    cout << "Enter your name: ";
    cin >> a;
    cout << "How many times you want to print the name: ";
    cin >> n;

    name(1, n, a);
    return 0;
}
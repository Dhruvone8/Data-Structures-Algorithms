#include <iostream>
#include <vector>
using namespace std;

void swap(vector<int> &arr, int index1, int index2)
{
    int temp = arr[index1];
    arr[index1] = arr[index2];
    arr[index2] = temp;
}

int main()
{
    vector<int> array = {9, 4, 2, 5, 3};
    swap(array, 0, 1);
    for (int i = 0; i < array.size(); i++)
    {
        cout << array[i] << " ";
    }
    return 0;
}
#include <iostream>
#include <vector>
using namespace std;

void swap(vector<int> &arr, int index1, int index2)
{
    int temp = arr[index1];
    arr[index1] = arr[index2];
    arr[index2] = temp;
}

void reverse(vector<int> &arr, int start, int end)
{
    start = 0;
    end = arr.size() - 1;
    while (start < end)
    {
        swap(arr, start, end);
        start++;
        end--;
    }
}
int main()
{
    vector<int> array = {9, 4, 2, 5, 3};
    reverse(array, 0, array.size() - 1);
    for (int i = 0; i < array.size(); i++)
    {
        cout << array[i] << " ";
    }
    return 0;
}
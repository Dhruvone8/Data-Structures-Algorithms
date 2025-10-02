#include <iostream>
#include <vector>
using namespace std;

void swap_array(int left, int right, vector<int> nums)
{
    if (left == right)
    {
        for (int i = 0; i < nums.size(); i++)
        {
            cout << nums[i];
        }
        return;
    }

    swap(nums[left], nums[right]);

    swap_array(left + 1, right - 1, nums);
}

int main()
{
    vector<int> nums = {1, 2, 3, 4, 5};
    swap_array(0, nums.size() - 1, nums);

    return 0;
}
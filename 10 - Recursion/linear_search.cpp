#include <iostream>
#include <vector>
using namespace std;

int linear_search(vector<int> &nums, int i, int target)
{
    if (i > nums.size() - 1)
    {
        return -1;
    }

    if (nums[i] == target)
    {
        return i;
    }

    return linear_search(nums, i + 1, target);
}

vector<int> linear_search_vector(vector<int> &nums, int i, int target, vector<int> &ans) // Passing List as a argument
{
    if (i > nums.size() - 1)
    {
        return ans;
    }

    if (nums[i] == target)
    {
        ans.push_back(i);
    }

    return linear_search_vector(nums, i + 1, target, ans);
}

vector<int> linear_search_vector1(vector<int> &nums, int i, int target) // vector array is not passed as a argument
{
    vector<int> ans; // After each function call a new vector array is created

    if (i > nums.size() - 1)
    {
        return ans;
    }

    if (nums[i] == target) // This will contain answer for that function call only
    {
        ans.push_back(i);
    }

    vector<int> a = linear_search_vector1(nums, i + 1, target); // Answer for each function calls

    ans.insert(ans.end(), a.begin(), a.end()); // Inserts the answers for each function call in the array

    return ans;
}

int main()
{
    vector<int> nums = {1, 2, 3, 4, 5, 6};
    vector<int> nums1 = {1, 2, 2, 3, 5, 6, 5};

    cout << "First occurrence of 5 in nums: ";
    cout << linear_search(nums, 0, 5) << endl;

    vector<int> ans;
    ans = linear_search_vector(nums1, 0, 5, ans);

    cout << "All indices of 5 in nums1 using vector array as function argument: ";
    for (int index : ans)
    {
        cout << index << " ";
    }
    cout << endl;

    vector<int> ans1;
    ans1 = linear_search_vector1(nums1, 0, 5);

    cout << "All indices of target in nums1 using vector array inside the function: ";
    for (int idx : ans1)
    {
        cout << idx << " ";
    }
    cout << endl;

    return 0;
}

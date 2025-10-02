#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
{
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());

    vector<int> ans;
    int i = 0; 
    int j = 0;

    while(i < nums1.size() && j < nums2.size())
    {
        if(nums1[i] > nums2[j])
        {
            j++;
        }

        else if(nums2[j] > nums1[i])
        {
            i++;
        }

        else if (nums1[i] == nums2[j])
        {
            if(ans.size() == 0 || ans.back() != nums1[i])
            {
                ans.push_back(nums1[i]);
            }
            i++;
            j++;
        }
    }
    return ans;
}

int main()
{
    vector<int> num1 = {45, 18, 7};
    vector<int> num2 = {45, 18, 17};
    vector<int> ans = intersection(num1, num2);
    for(int i = 0; i<ans.size(); i++)
    {
        cout<<ans[i]<<" ";
    }
    return 0;
}
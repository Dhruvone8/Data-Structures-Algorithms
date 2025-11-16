// Leetcode Link: https://leetcode.com/problems/pascals-triangle/description/
// Leetcode Link: https://leetcode.com/problems/pascals-triangle-ii/description/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
1. To Find value of the element at the given {Row, Col} in a Pascal Triangle
-> Find (Row - 1)c(Col - 1)
*/

// Function to find element at given {Row, Col} i.e Find (Row - 1)c(Col - 1)
int findelement(int row, int col)
{
    int ans = 1;

    for (int i = 0; i < col - 1; i++)
    {
        ans = ans * (row - i);
        ans = ans / (i + 1);
    }

    return ans;
}

/*
2. Print all the elements of the Nth Row
-> In a Pascal Triangle, nth row has n elements
*/

// Function to get all elements of the given row
vector<int> getRow(int rowIndex)
{
    vector<int> rowitems(rowIndex + 1); 
    long long ans = 1;
    rowitems[0] = 1;

    for (int i = 1; i <= rowIndex; i++)
    {
        ans = ans * (rowIndex - i + 1);
        ans = ans / i;
        rowitems[i] = ans;
    }

    return rowitems;
}

/*
3. Print all the pascal triangle elements till the given row
-> Find all the row elements for each row
*/

// Function to generate all the pascal elements
vector<vector<int>> generate(int numRows)
{
    vector<vector<int>> ans(numRows);

    for(int i = 1; i <= numRows; i++)
    {
        ans[i] = getRow(i);
    }

    return ans;
}

int main()
{
    int row = 10;
    int col = 3;

    cout << "Element at " << row << "th row and " << col << "rd column is " << findelement(5, 3) << endl; // 10c3 = 120

    vector<int> ans = getRow(5);

    for (int el : ans)
    {
        cout << el << " ";
    }

    return 0;
}
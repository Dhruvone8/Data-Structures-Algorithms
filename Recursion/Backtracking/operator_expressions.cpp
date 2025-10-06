#include <iostream>
#include <vector>
using namespace std;

void solve(string num, int target, int index, string expression, long long expression_value, long long previous_num, vector<string> &result)
{
    if (index == num.size())
    {
        if (expression_value == target)
        {
            result.push_back(expression);
        }
        return;
    }

    for (int i = index; i < num.size(); i++)
    {
        // Skip numbers with leading zeros (e.g., "05")
        if (i != index && num[index] == '0')
        {
            break;
        }

        string current_str = num.substr(index, i - index + 1);
        long long current_num = stoll(current_str);

        if (index == 0)
        {
            // Start the expression, no operator before first number
            solve(num, target, i + 1, current_str, current_num, current_num, result);
        }
        else
        {
            // Addition
            solve(num, target, i + 1, expression + "+" + current_str, expression_value + current_num, current_num, result);

            // Subtraction
            solve(num, target, i + 1, expression + "-" + current_str, expression_value - current_num, -current_num, result);

            // Multiplication
            solve(num, target, i + 1, expression + "*" + current_str,
                  expression_value - previous_num + previous_num * current_num,
                  previous_num * current_num,
                  result);
        }
    }
}

vector<string> addOperators(string num, int target)
{
    vector<string> result;
    solve(num, target, 0, "", 0, 0, result);
    return result;
}

int main()
{
    string num = "123";
    int target = 6;
    vector<string> expressions = addOperators(num, target);

    for (string expr : expressions)
    {
        cout << expr << endl;
    }
    return 0;
}

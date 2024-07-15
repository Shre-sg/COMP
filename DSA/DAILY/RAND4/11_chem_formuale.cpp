#include <iostream>
#include <string>
#include <map>
#include <stack>
#include <cctype>

using namespace std;

// 726. Number of Atoms
// Given a string formula representing a chemical formula, return the count of each atom.

// The atomic element always starts with an uppercase character, then zero or more lowercase letters, representing the name.

// One or more digits representing that element's count may follow if the count is greater than 1. If the count is 1, no digits will follow.

// For example, "H2O" and "H2O2" are possible, but "H1O2" is impossible.
// Two formulas are concatenated together to produce another formula.

// For example, "H2O2He3Mg4" is also a formula.
// A formula placed in parentheses, and a count (optionally added) is also a formula.

// For example, "(H2O2)" and "(H2O2)3" are formulas.
// Return the count of all elements as a string in the following form: the first name (in sorted order), followed by its count (if that count is more than 1), followed by the second name (in sorted order), followed by its count (if that count is more than 1), and so on.

// The test cases are generated so that all the values in the output fit in a 32-bit integer.

// Example 1:

// Input: formula = "H2O"
// Output: "H2O"
// Explanation: The count of elements are {'H': 2, 'O': 1}.
// Example 2:

// Input: formula = "Mg(OH)2"
// Output: "H2MgO2"
// Explanation: The count of elements are {'H': 2, 'Mg': 1, 'O': 2}.
// Example 3:

// Input: formula = "K4(ON(SO3)2)2"
// Output: "K4N2O14S4"
// Explanation: The count of elements are {'K': 4, 'N': 2, 'O': 14, 'S': 4}.

// Constraints:

// 1 <= formula.length <= 1000
// formula consists of English letters, digits, '(', and ')'.
// formula is always valid.

class Solution
{
public:
    string countOfAtoms(string formula)
    {
        int n = formula.size();
        string result = "";
        map<string, int> elementCount;         // To store final counts of each element
        stack<pair<string, int>> elementStack; // To store elements and their counts
        stack<int> multiplierStack;            // To store multipliers for nested structures
        int currentMultiplier = 1;             // Current multiplier for nested elements
        int i = 0;

        // Parse the formula
        while (i < n)
        {
            string element = "", countStr = "";
            int j = i;

            // Parse element name and its count
            if (formula[i] >= 'A' && formula[i] <= 'Z')
            {
                element += formula[i];
                j = i + 1;
                while (j < n && formula[j] >= 'a' && formula[j] <= 'z')
                {
                    element += formula[j];
                    j++;
                }
                while (j < n && formula[j] >= '0' && formula[j] <= '9')
                {
                    countStr += formula[j];
                    j++;
                }
                if (countStr == "")
                {
                    elementStack.push({element, 1});
                }
                else
                {
                    elementStack.push({element, stoi(countStr)});
                }
                i = j;
            }
            else if (formula[i] == '(')
            {
                elementStack.push({"(", 0});
                i++;
            }
            else if (formula[i] == ')')
            {
                j = i + 1;
                while (j < n && formula[j] >= '0' && formula[j] <= '9')
                {
                    countStr += formula[j];
                    j++;
                }
                int multiplier = (countStr == "") ? 1 : stoi(countStr);
                elementStack.push({")", multiplier});
                i = j;
            }
        }

        // Process the elements in the stack and apply multipliers
        while (!elementStack.empty())
        {
            string element = elementStack.top().first;
            int count = elementStack.top().second;
            elementStack.pop();
            if (element == ")")
            {
                currentMultiplier *= count;
                multiplierStack.push(count);
            }
            else if (element == "(")
            {
                currentMultiplier /= multiplierStack.top();
                multiplierStack.pop();
            }
            else
            {
                int adjustedCount = currentMultiplier * count;
                elementCount[element] += adjustedCount;
            }
        }

        // Build the result string
        for (auto &elem : elementCount)
        {
            result += elem.first;
            if (elem.second != 1)
            {
                result += to_string(elem.second);
            }
        }

        return result;
    }
};

int main()
{
    Solution solution;
    string formula;

    cout << "Enter a chemical formula: ";
    cin >> formula;

    string result = solution.countOfAtoms(formula);
    cout << "The count of atoms is: " << result << endl;

    return 0;
}

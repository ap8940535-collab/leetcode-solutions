/**
 * Problem: 20. Valid Parentheses
 * Difficulty: Easy
 * Category: Stack
 *
 * Time Complexity:  O(N)
 * Space Complexity: O(N)
 */

#include <iostream>
#include <string>
#include <stack>

class Solution {
public:
    bool isValid(std::string s) {
        std::stack<char> st;

        for (char c : s) {
            if (c == '(') {
                st.push(')');
            } else if (c == '{') {
                st.push('}');
            } else if (c == '[') {
                st.push(']');
            } else {
                if (st.empty() || st.top() != c) {
                    return false;
                }
                st.pop();
            }
        }

        return st.empty();
    }
};

int main() {
    Solution sol;
    std::cout << "\"()[]{}\": " << (sol.isValid("()[]{}") ? "true" : "false") << "\n";
    std::cout << "\"(]\": " << (sol.isValid("(]") ? "true" : "false") << "\n";
    std::cout << "\"([{}])\": " << (sol.isValid("([{}])") ? "true" : "false") << "\n";
    return 0;
}

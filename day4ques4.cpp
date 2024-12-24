#include <iostream>
#include <stack>
#include <string>
using namespace std;

int scoreOfParentheses(string s) {
    stack<int> st;
    st.push(0);

    for (char c : s) {
        if (c == '(') {
            st.push(0);
        } else {
            int top = st.top();
            st.pop();
            int score = max(2 * top, 1);
            st.top() += score;
        }
    }

    return st.top();
}

int main() {
    string s;
    cout << "Enter a balanced parentheses string: ";
    cin >> s;

    int result = scoreOfParentheses(s);
    cout << "Score of the string: " << result << endl;

    return 0;
}

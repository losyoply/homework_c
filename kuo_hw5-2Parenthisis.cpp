#include <iostream>
#include <string>

using namespace std;

// Match left parenthesis with right. Return true if it's a match.
bool match(char L, char R) {
    switch (L) {
    case '(': return R == ')';
    case '{': return R == '}';
    case '[': return R == ']';
    case '<': return R == '>';
    } return false;
}

// Check if x is a left parenthesis.
bool is_left(char x) {
    switch (x) {
    case '(':
    case '{':
    case '[':
    case '<': return true;
    } return false;
}

int main()
{
    char p_stack[1000]; // Picked over std::stack since the size of input is already known.
    int T;
    bool error_flag;
    string input;
    cin >> T;
    getchar(); // Get rid of a newline.
    for (int testcase = 1; testcase <= T; testcase++) {
        getline(cin, input);
        error_flag = false;
        int top = -1;
        if (!input.empty()) {
            for (string::iterator i = input.begin(); i != input.end(); i++) {
                if (is_left(*i)) p_stack[++top] = *i;
                else if (top < 0 || !match(p_stack[top--], *i)) {
                    error_flag = true;
                    break;
                }
            }
        }
        if (top >= 0) error_flag = true; // Check if there are still unmatched left parentheses remaining.
        cout << "Case " << testcase << ": ";
        if (error_flag) cout << "No\n";
        else cout << "Yes\n";
    }

    return 0;
}



// By IntSys


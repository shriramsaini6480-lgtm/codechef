class Solution {
    int precedence(char op) {
        if (op == '^') return 3;
        if (op == '*' || op == '/') return 2;
        if (op == '+' || op == '-') return 1;
        return 0;
    }

public:
    string infixToPrefix(string& s) {
        string reversed = s;
        reverse(reversed.begin(), reversed.end());

        // Swap parentheses after reversing.
        for (char& ch : reversed) {
            if (ch == '(') ch = ')';
            else if (ch == ')') ch = '(';
        }

        stack<char> a;
        string p;

        for (char ch : reversed) {
            if (isalnum(static_cast<unsigned char>(ch))) {
                p += ch;
            } else if (ch == '(') {
                a.push(ch);
            } else if (ch == ')') {
                while (!a.empty() && a.top() != '(') {
                    p += a.top();
                    a.pop();
                }
                if (!a.empty()) a.pop(); // Remove '('
            } else {
                while (!a.empty() && a.top() != '(' &&
                       (precedence(a.top()) > precedence(ch) ||
                        (precedence(a.top()) == precedence(ch) && ch == '^'))) {
                    p += a.top();
                    a.pop();
                }
                a.push(ch);
            }
        }

        while (!a.empty()) {
            p += a.top();
            a.pop();
        }

        reverse(p.begin(), p.end());
        return p;
    }
};
class Solution {
    int precedence(char op) {
        if (op == '^') return 3;
        if (op == '*' || op == '/') return 2;
        if (op == '+' || op == '-') return 1;
        return 0;
    }

public:
    string infixToPostfix(string& s) {
        stack<char> a;
        string p;

        for (char ch : s) {
            if (isalnum(static_cast<unsigned char>(ch))) {
                p += ch;
            } else if (ch == '(') {
                a.push(ch);
            } else if (ch == ')') {
                while (!a.empty() && a.top() != '(') {
                    p += a.top();
                    a.pop();
                }
                if (!a.empty()) a.pop();
            } else {
                while (!a.empty() && a.top() != '(' &&
                       (precedence(a.top()) > precedence(ch) ||
                        (precedence(a.top()) == precedence(ch) && ch != '^'))) {
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

        return p;
    }
};
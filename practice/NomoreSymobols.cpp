#include <bits/stdc++.h>
using namespace std;

unordered_map<string, int> numMap = {
    {"zero", 0}, {"one", 1}, {"two", 2}, {"three", 3}, {"four", 4},
    {"five", 5}, {"six", 6}, {"seven", 7}, {"eight", 8}, {"nine", 9}
};

unordered_map<string, int> opPrecedence = {
    {"pow", 3}, {"mul", 2}, {"div", 2}, {"add", 1}, {"sub", 1}, {"rem", 1}
};

int parseMultiDigitNumber(const string& word) {
    int result = 0;
    string currentDigit;
    for (char c : word) {
        if (c == 'c') {
            // Validate and convert current digit word
            if (numMap.find(currentDigit) == numMap.end()) {
                return -1; // Invalid digit word
            }
            result = result * 10 + numMap[currentDigit];
            currentDigit.clear();
        } else {
            currentDigit += c;
        }
    }
    // Add last digit if available
    if (!currentDigit.empty()) {
        if (numMap.find(currentDigit) == numMap.end()) {
            return -1; // Invalid digit word
        }
        result = result * 10 + numMap[currentDigit];
    }
    return result;
}

bool isValidWord(const string& word) {
    return numMap.count(word) || opPrecedence.count(word) || parseMultiDigitNumber(word) != -1;
}

// Evaluate expression based on precedence
int evaluateExpression(stack<int>& values, stack<string>& ops) {
    int val2 = values.top(); values.pop();
    int val1 = values.top(); values.pop();
    string op = ops.top(); ops.pop();

    if (op == "add") return val1 + val2;
    if (op == "sub") return val1 - val2;
    if (op == "mul") return val1 * val2;
    if (op == "div") {
        if (val2 == 0) throw runtime_error("division by zero");
        return val1 / val2;
    }
    if (op == "rem") return val1 % val2;
    if (op == "pow") return pow(val1, val2);
    return 0;
}

int evaluate(const vector<string>& tokens) {
    stack<int> values;
    stack<string> ops;

    for (const string& token : tokens) {
        if (numMap.count(token)) {
            values.push(numMap[token]);
        } else if (opPrecedence.count(token)) {
            while (!ops.empty() && opPrecedence[ops.top()] >= opPrecedence[token]) {
                if (values.size() < 2) return -2; // Not enough values for operation
                values.push(evaluateExpression(values, ops));
            }
            ops.push(token);
        } else {
            int num = parseMultiDigitNumber(token);
            if (num == -1) return -1; // Invalid word
            values.push(num);
        }
    }

    while (!ops.empty()) {
        if (values.size() < 2) return -2; // Invalid expression structure
        values.push(evaluateExpression(values, ops));
    }

    return values.size() == 1 ? values.top() : -2; // Final result or invalid expression
}

int main() {
    string input;
    getline(cin, input);

    vector<string> tokens;
    stringstream ss(input);
    string word;
    while (ss >> word) {
        tokens.push_back(word);
    }

    // Validate all tokens first
    for (const string& token : tokens) {
        if (!isValidWord(token)) {
            cout << "expression evaluation stopped invalid words present" << endl;
            return 0;
        }
    }

    try {
        int result = evaluate(tokens);
        if (result == -1) {
            cout << "expression evaluation stopped invalid words present" << endl;
        } else if (result == -2) {
            cout << "expression is not complete or invalid" << endl;
        } else {
            cout << result << endl;
        }
    } catch (const runtime_error&) {
        cout << "expression is not complete or invalid" << endl;
    }

    return 0;
}

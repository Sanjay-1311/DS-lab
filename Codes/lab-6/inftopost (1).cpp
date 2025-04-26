#include <iostream>
#include <cctype>
#include <string>
#include "stack_sll.h"

using namespace std;

int precedence(char op);
string infixToPostfix(const string& infix);
int evaluatePostfix(const string& postfix);


// **MAIN MENU FUNCTION**
int main() {
    string infix, postfix;
    int result;
    int stop = 0;
    
    while (!stop) {
        cout << "\nMenu:\n1. Enter Infix Expression\n2. Convert to Postfix\n3. Evaluate Postfix\n4. Exit\n\nEnter choice: ";
        int choice;
        cin >> choice;
        cin.ignore(); // Ignore '\n' left by cin in the buffer (in order to use getline)
        
        switch (choice) {
            case 1:
                cout << "Enter infix expression: ";
                getline(cin, infix);
                break;
                
            case 2:
                if (infix.empty()) {
                    cout << "No infix expression entered!\n";
                } else {
                    postfix = infixToPostfix(infix);
                    cout << "Postfix expression: " << postfix << endl;
                }
                break;
                
            case 3:
                if (postfix.empty()) {
                    cout << "No postfix expression available!\n";
                } else {
                    result = evaluatePostfix(postfix);
                    cout << "Result: " << result << endl;
                }
                break;
                
            case 4:
                stop = 1;
                cout << "Exiting...";
                break;
                
            default:
                cout << "Invalid choice! Try again.\n";
        }
    }
    
    return 0;
}
// Function to get precedence of operators
int precedence(char op) {
    if (op == '=') return 1;  
    if (op == '+' || op == '-') return 2;
    if (op == '*' || op == '/' || op == '%') return 3;
    return 0; // Non-operators
}

// Function to convert infix to postfix using Stack
string infixToPostfix(const string& infix) {
    Stack s;
    string postfix;
    
    for (char ch : infix) {
        if (isalnum(ch)) {  
            postfix += ch;  
        }
        else if (ch == '(') {
            s.push(ch);
        }
        else if (ch == ')') {
            while (!s.isempty() && s.peek() != '(') {
                postfix += s.pop();
            }
            s.pop(); // Remove '('
        }
        else {  
            while (!s.isempty() && precedence(s.peek()) >= precedence(ch)) {
                postfix += s.pop();
            }
            s.push(ch);
        }
    }
    
    while (!s.isempty()) {
        postfix += s.pop();
    }
    
    return postfix;
}

// Function to evaluate a postfix expression using Stack
int evaluatePostfix(const string& postfix) {
    Stack s;
    
    for (char ch : postfix) {
        if (isdigit(ch)) {
            s.push(ch - '0'); 
        }
        else {
            int b = s.pop(); 
            int a = s.pop();
            
            switch (ch) {
                case '+': s.push(a + b); break;
                case '-': s.push(a - b); break;
                case '*': s.push(a * b); break;
                case '/': s.push(a / b); break;
                case '%': s.push(a % b); break;
                case '=': s.push(b); break; // Return only the top value (RHS)
            }
        }
    }
    
    return s.pop();
}

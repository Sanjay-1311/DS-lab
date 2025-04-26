//Program to check if parentheses in an expression are balanced using stack

#include <iostream>
#include "stack_sll.h"
using namespace std;

bool isBalanced(string expr);

int main() {
    int choice;
    string expr;
    
    do {
        cout << "\nMenu:\n1. Check Balance\n2. Exit\nEnter choice: ";
        cin >> choice;
        cin.ignore();
        
        switch (choice) {
            case 1:
                cout << "Enter expression of '(' and ')': ";
                getline(cin, expr);
                if (isBalanced(expr))
                    cout << "Balanced Parentheses!\n";
                else
                    cout << "Unbalanced Parentheses!\n";
                break;
            case 2:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != 2);
    
    return 0;
}

// Function to check if parentheses are balanced
bool isBalanced(string expr) {
    Stack s;
    for (char ch : expr) {
        if (ch == '(') {
            s.push(ch);
        } else if (ch == ')') {
            if (s.isempty()) return false; // Unmatched closing bracket
            s.pop();
        }
    }
    return s.isempty(); // Stack should be empty if balanced
}

//This program will implement various operations of a type of List ADT called Stack using array
#include <iostream>
#define SIZE 5
using namespace std;

class Stack{
    private:
    char arr[SIZE];
    int top;
    
    public:
    //Method Prototypes
    Stack():top(-1){}
    bool push(char);
    char pop();
    char peek();
};

int main(){
    Stack stack;
    int choice;
    char value,result;
    do{
        cout << "\n\nMENUS\n1.Push\n2.Pop\n3.Peek\n4.Exit\n" << endl;
        cout << "Enter Choice : " ;
        cin >> choice;
        switch(choice){
            case 1:
            cout << "Enter the value to be pushed : " ;
            cin >> value;
            if(stack.push(value)){
                cout << "Successfully inserted" << endl;
            }
            else{
                cout << "==== Overflow.Stack is full ! ==== " << endl;
            }

            break;
            case 2:
            result=stack.pop();
            if (result=='\0'){
                cout << "==== Underflow.Stack is empty ==== " << endl;
            }
            else{
                cout << "The Popped element from the stack is " << result << endl;
            }
            break;
            case 3:
            result=stack.peek();
            if (result==0){
                cout << "==== Stack is Empty ! ====" << endl;
            }
            else{
                cout << "The topmost element of the stack is " << result << endl;
            }
            break;
            case 4:
            cout << "Exiting..." << endl;
            break;
            default:
            printf("Invalid choice");
        }
    }while(choice!=4);
    return 0;
}
//This Method will insert the given character in the stack
bool Stack::push(char value){
    if (top==SIZE-1){
        return false;
    }
    else{
        arr[++top]=value;
        return true;
    }
}
//This Method will delete the topmost character in the stack
char Stack::pop(){
    if(top==-1){
        return '\0';
    }
    else{
        char character=arr[top];
        top--;
        return character;
    }
}
//This Method will display the topmost character in the stack without deleting it
char Stack::peek(){
    if(top==-1){
        return '\0';
    }
    else{
        return arr[top];
    }
}

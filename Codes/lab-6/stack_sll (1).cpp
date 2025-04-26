//This program will implement various operaions of a type of List ADT called Stack using linked list
#include<iostream>
using namespace std;

class Stack{
    private:
    struct node {
        int data;
        struct node* next;
    }*head;
    typedef struct node node;

    public:
    //Method Prototypes
    Stack():head(NULL){}
    void push(char);
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
            stack.push(value);
            cout << "Successfully inserted" << endl;
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
//This Method will insert the given value on top of the stack
void Stack::push(char value){
    node *newnode = (node*)malloc(sizeof(node));
    newnode->data = value;
    newnode->next = head;
    head = newnode;
    return;
}
//This Method will delete the topmost character in the stack
char Stack::pop(){
    if(head==NULL)
    {
        return '\0';
    }
    else
    {
        node *temp = head;
        int value = temp->data;
        head = temp->next;
        free(temp);
        return value;
    }
}
//This Method will display the topmost element of the stack without deleting it
char Stack::peek(){
    if(head==NULL){
        return 0;
    }
    else{
        return head->data;
    }
}

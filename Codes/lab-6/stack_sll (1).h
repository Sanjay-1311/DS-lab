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
    bool isempty(){return head==NULL;};
};

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

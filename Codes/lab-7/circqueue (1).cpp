//Implementation of queue using circular linked list
/*
   1. Write a C++ menu-driven program to sort a given array in ascending order. Design proper functions, maintain boundary conditions, and follow coding best practices. The menus are as follows,

a.       Bubble Sort

b.      Selection Sort

c.       Insertion Sort

d.      Exit

 

2. Convert the sorting program into a header file and include it into a new cpp file. Write a C++ menu-driven program for linear and binary search in this new cpp file. Utilize any of the sorting functions in the included header file to sort the input array before performing a binary search. Design proper functions, maintain boundary conditions and follow coding best practices. The menu-driven program supports,

a.       Linear Search

b.      Binary Search

c.       Exit
*/
#include<iostream>
using namespace std;

class queue{
    private:
        struct node{
            int data;
            node* next;
        };
        node* front;
        node* rear;
    public:
    queue(){
        front=nullptr;
        rear=nullptr;
    }
        int enqueue(int);
        int dequeue();
        int peek();
        

};


int main(){
    class queue q1;
    int inf;
    int ch;
    inf=1;
    while (inf==1){
        cout<<"Enter 1 to enqueue an element"<<endl;
        cout<<"Enter 2 to dequeue an element"<<endl;
        cout<<"Enter 3 to peek"<<endl;
        cout<<"Enter 4 to exit"<<" ";
        cin>>ch;
        if(ch==1){
            int val;
            cout<<"Enter the value you want to enqueue ";
            cin>>val;
            q1.enqueue(val);
        }
        else if (ch==2){
            q1.dequeue();
        }
        else if (ch==3){
            q1.peek();
        }
        else if (ch==4){
            break;
        }
        else{
            cout<<"Enter valid choice"<<endl;
        }
    }
    return 0;
}
//Function to enqueue an element
int queue::enqueue(int val){
    struct node* newnode=new struct node();
    newnode->data=val;
    newnode->next=nullptr;
    if (front==nullptr){
        front=newnode;
        rear=newnode;
        rear->next=newnode;
        return 1;
    }
    rear->next=newnode;
    newnode->next=front;
    rear=rear->next;
    return 1;
}
//Function to dequeue an element
int queue::dequeue(){
    int temp;
    temp=front->data;
    if (front==nullptr){
        cout<<"The queue is empty";
        return 0;
    }
    front=front->next;
    rear->next=front;
    return temp;
}
//Function to peek at the queue
int queue::peek(){
    if (front==nullptr){
        cout<<"The queue is empty"<<endl;
        return 0;
    }
    cout<<front->data<<endl;
    return 1;
}
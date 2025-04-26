#include<iostream>
using namespace std;
#define size 5
class ListADT{
    private:
        int list[size];
    public:
        int count=0;
        int insbeg(int value);
        int insend(int value);
        int inspos(int value,int pos);
        int deletebeg();
        int deleteend();
        int deletepos(int pos);
        int search(int target);
        int display();
        int rotate();
};
int main(){
    class ListADT list1;
    int choice;
    int inf=1;
    while (inf==1){
        cout<<"Enter 1 for Inserting at beg"<<"\n"<<"Enter 2 for Inserting at end"<<"\n"<<"Enter 3 for inserting at position"<<"\n"<<"Enter 4 for delete beg"<<endl;
        cout<<"Enter 5 for delete end"<<"\n"<<"Enter 6 for Deleting at postion"<<"\n"<<"Enter 7 for search"<<"\n"<<"Enter 8 for display"<<"\n"<<"Enter 9 for Rotate"<<"\n"<<"Enter 10 to exit"<<endl;
        cout<<endl;
        cout<<"Enter your choice";
        cin>>choice;
        if (choice==1){
            int value;
            cout<<"Enter the value you want to insert at beg"<<" ";
            cin>>value;
            list1.insbeg(value);
        }
        else if (choice==2){
            int value;
            cout<<"Enter the value you want to insert at end"<<" ";
            cin>>value;
            list1.insend(value);
        }
        else if (choice==3){
            int value;
            int position;
            cout<<"Enter the value you want to insert";
            cin>>value;
            cout<<"Enter the position you want to enter the value in";
            cin>>position;
            list1.inspos(value,position);
        }
        else if (choice==4){
            list1.deletebeg();
        }
        else if (choice==5){
            list1.deleteend();
        }
        else if (choice==6){
            int position;
            cout<<"Enter position ";
            cin>>position;
            list1.deletepos(position);
        }
        else if (choice==7){
            int target;
            cout<<"Enter target element";
            cin>>target;
            list1.search(target);
        }
        else if (choice==8){
            list1.display();
        }
        else if (choice==9){
            int k;
            cout<<"Enter the number of times you want to rotate";
            cin>>k;
            
            if (k<0){
                cout<<"Invalid";
            }
            else{
                k=k%list1.count;
                for (int i=0;i<k;i++){
                    list1.rotate();
                }
            }
        }
    
        else if (choice ==10){
            cout<<"The program is over";
            break;
        }
        else{
            cout<<"Invalid choice";
        }
        
    }
    return 1;
}
//Function to insert a value at the beginning 
int ListADT::insbeg(int val){
    if (count==size){
        cout<<"The list is full";
        return 0;
    }
    for (int i=count;i>0;i--){
        list[i]=list[i-1];
    }
    list[0]=val;
    count++;
    return 1;
}
//Function to display the list
int ListADT::display(){
    if (count==0){
        cout<<"The list is empty";
        return 0;
    }
    for (int i=0;i<count;i++){
        cout<<list[i]<<endl;
    }
    return 1;
}
//Function to insert a value at the end
int ListADT::insend(int value){
    if (count==size){
        cout<<"The list is full";
        return 0;
    }
    list[count]=value;
    count++;
    return 1;
}
//Function to insert a value at a given position
int ListADT::inspos(int value,int pos){
    if (count==size){
        cout<<"The list if full";
        return 0;
    }
    if (pos<=0 || pos>count){
        cout<<"Enter valid position";
        return 0;
    }
    for (int i=count;i>pos-1;i--){
        list[i]=list[i-1];
    }
    list[pos-1]=value;
    count++;
    return 1;
}
//Function to delete the beginning element of the list
int ListADT::deletebeg(){
    int temp=list[0];
    if (count==0){
        cout<<"The list is empty"<<endl;
        return 0;
    }
    for (int i=0;i<count;i++){
        list[i]=list[i+1];
    }
    count--;
    return temp;
}
//Function to delete the last element of the list
int ListADT::deleteend(){
    int temp=list[count-1];
    if (count==0){
        cout<<"The list is empty"<<endl;
        return 0;
    }
    count--;
    return temp;
}
//Function to delete an element at a given position
int ListADT::deletepos(int pos){
    int temp=list[pos-1];
    if (count==0){
        cout<<"The list is empty"<<endl;
        return 0;
    }
    for (int i=pos-1;i<count;i++){
        list[i]=list[i+1];
    }
    count--;
    return temp;
}
//Function to search for a target element in the list
int ListADT::search(int target){
    for (int i=0;i<count;i++){
        if (list[i]==target){
            cout<<"The element is found at pos "<<i+1<<endl;
            return 1;
        }
    }
    return 0;
    
}
//Function to rotate a list k times
int ListADT::rotate(){
    int temp=list[count-1];
    for (int i=count-1;i>0;i--){
        list[i]=list[i-1];
    }
    list[0]=temp;
    return 1;
}
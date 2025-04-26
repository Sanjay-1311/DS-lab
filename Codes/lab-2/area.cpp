#include <iostream>
#include <cstdlib>
#include<cmath>
using namespace std;
class shapes{
    public:
        int length;
        int breadth;
        int width;
        int getareasquare(){
            return length*length;
        }
        int getareacube(){
            return 6*length*length;
        }
        int getarearectangle(){
            return length*breadth;
        }   
        int getareacuboid(){
            return 2*((length*breadth)+(breadth*width)+(width*length));
        }
};

int main(){
    int length,breadth,width;
    class shapes s1;
    s1.length=0;
    s1.width=0;
    s1.breadth=0;
    int inf=1;
    cout<<"Enter length breadth and width"<<endl;
    cin>>length>>breadth>>width;
    s1.length=length;
    s1.width=width;
    s1.breadth=breadth;
    while(inf==1){
        int choice;
        cout << "Enter 1 for square\n"<<"Enter 2 for Cube\n"<<"Enter 3 for Rectangle\n"<<"Enter 4 for cuboid\n"<<"Enter 5 to exit"<<endl;
        cin >> choice;
        if (choice==1){
            int result=s1.getareasquare();
            cout<<result<<endl;
        }
        else if (choice==2){
            int result=s1.getareacube();
            cout<<result<<endl;
        }
        else if (choice==3){
            int result=s1.getarearectangle();
            cout<<result<<endl;
        }
        else if (choice==4){
            int result=s1.getareacuboid();
            cout<<result<<endl;
        }
        else if(choice==5){
            cout<<"Over";
            break;
        }
        else{
            cout<<"Enter valid choice"<<endl;
        }
    }
    return 0;
}
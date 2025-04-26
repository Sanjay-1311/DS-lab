#include <iostream>
#include <cstdlib>
#include<cmath>
using namespace std;
bool ispalindrome(int* num);
bool isArmstrong(int* num);
bool isPerfect(int* num);
int main(){
    int* inf=(int*)malloc(sizeof(int));
    *inf=1;
    while (*inf==1){
        int* choice=(int*)malloc(sizeof(int));
        cout << "Enter 1 for palindrome\n"<<"Enter 2 for Armstong\n"<<"Enter 3 for perfect\n"<<"Enter 4 to exit"<<endl;
        cin >> *choice;
        if (*choice==1){
            int* number=(int*)malloc(sizeof(int));
            cout<<"Enter the number";
            cin>>*number;
            if (ispalindrome(number)){
                cout<<"It is a palindrome"<<endl;
            }
            else{
                cout<<"It is not a palindrome"<<endl;
            }
            free(number);
        }
        else if(*choice==2){
            int* number=(int*)malloc(sizeof(int));
            cout<<"Enter the number";
            cin>>*number;
            if (isArmstrong(number)){
                cout<<"It is an armstrong number"<<endl;
            }
            else{
                cout<<"It is not an Armstrong number"<<endl;
            }
            free(number);
        }
        else if(*choice==3){
            int* number=(int*)malloc(sizeof(int));
            cout<<"Enter the number";
            cin>>*number;
            if (isPerfect(number)){
                cout<<"It is a perfect number"<<endl;
            }
            else{
                cout<<"It is not a perfect number"<<endl;
            }
        }
        else if (*choice==4){
            cout<<"Over"<<endl;
            break;
        }
        else{
            cout<<"Enter a valid choice"<<endl;
        }
    }
    return 0;
}
bool ispalindrome(int* num){
    int* original=(int*)malloc(sizeof(int));
    int* reversed=(int*)malloc(sizeof(int));
    bool* result=(bool* )malloc(sizeof(bool));
    *original=*num;
    *reversed=0;
    while(*num>0){
        *reversed=*reversed*10+*num%10;
        *num/=10;
    }
    *result=(*reversed==*original);
    return *result;
}
bool isArmstrong(int* num){
    int*original=(int*)malloc(sizeof(int));
    int*original1=(int*)malloc(sizeof(int));
    int*digit=(int*)malloc(sizeof(int));
    int*digits=(int*)malloc(sizeof(int));
    int*sum=(int*)malloc(sizeof(int));
    bool* result=(bool* )malloc(sizeof(bool));
    *original=*num;
    *original1=*num;
    *sum=0;
    *digit=0;
    *digits=0;
    while(*num>0){
        *digits+=1;
        *num/=10;
    }
    while(*original1>0){
        *digit=*original1%10;
        *sum+=pow(*digit,*digits);
        *original1/=10;
    }
    *result=(*sum==*original);
    return *result;
}
bool isPerfect(int*num){
    int* i=(int*)malloc(sizeof(int));
    int* sum=(int*)malloc(sizeof(int));
    bool* result=(bool* )malloc(sizeof(bool));
    *sum=0;
    for((*i)=1;(*i)<=((*num)/2);(*i)++){
        if(*(num)%(*i)==0){
            *sum+=*i;
        }
    }
    *result=(*sum==*num);
    return *result;

}
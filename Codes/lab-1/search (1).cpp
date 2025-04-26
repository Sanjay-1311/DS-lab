// searching an element using linear and binary search
#include <cstdio>
#include <cstdlib>
#include "sort.h"
void linear(int arr[],int target,int size);
int binary(int arr[],int target,int size);
int main(){
    int size;
    printf("enter size");
    scanf("%d",&size);
    int arr[size]={}; 
    for (int i=0;i<size;i++){
        printf("Enter the %d element",i+1);
        scanf("%d",&arr[i]);
    }
    int target;
    printf("Enter the target element ");
    scanf ("%d",&target);
    printf("Enter 1 to linear search \n");
    printf("Enter 2 to binary searh \n");
    printf("Enter 3 to exit \n");
    int inf=1;
    while (inf==1){
        int choice;
        printf("Enter 1 to linear search \n");
        printf("Enter 2 to binary searh \n");
        printf("Enter 3 to exit \n");
        printf("Enter your choice(1,2,3)");
        scanf("%d",&choice);
        if (choice==1){
            linear(arr,target,size);
        }
        else if (choice==2){
            bubblesort(arr,size);
            int res=binary(arr,target,size);
            if (res!=-1){
                printf("The element was found in position number %d\n",res+1);
            }
            else{
                printf("The element was not found in the given arrar=y");
            }
        }
        
        else if (choice==3){
            printf("Program is completed\n");
            break;
        }
        else{
            printf("Enter a valid choice\n");
        }
    }
    return 0;
}
void linear(int arr[],int target,int size){
    for (int i=0;i<size;i++){
        if (arr[i]==target){
            printf("The target element is found at %d position\n",i+1);
        }
    }
}
int binary(int arr[],int target,int size){
   
        int beg=0;
        int end=size-1;
        
        while (beg<=end){
            int mid=(beg+end)/2;
            if (target==arr[mid]){
                return mid;
            }
            else if (arr[mid]<target){
                beg=mid+1;
            }
            else if (arr[mid]>target){
                end=mid-1;
            }
        }
    return -1;
}
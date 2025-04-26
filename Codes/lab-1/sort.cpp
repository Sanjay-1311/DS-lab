/*
Sortng an array using bubble insertion and selection sort
*/
#include<cstdio>
#include<cstdlib>
void bubblesort(int arr[],int size);
void insertionsort(int arr[],int size);
void selectionsort(int arr[],int size);
int main(){
    int size;
    printf("Enter size");
    scanf("%d",&size);
    int arr[size]={}; 
    for (int i=0;i<size;i++){
        printf("Enter the %d element",i+1);
        scanf("%d",&arr[i]);
    }
    printf("Enter 1 to bubble sort \n");
    printf("Enter 2 to insertion sort\n");
    printf("Enter 3 to selection sort\n");
    printf("Enter 4 to exit\n");
    int inf=1;
    while (inf==1){
        int choice;
        printf("Enter your choic(1,2,3,4)");
        scanf("%d",&choice);
        if (choice==1){
            bubblesort(arr,size);
        }
        else if (choice==2){
            insertionsort(arr,size);
        }
        else if (choice==3){
            selectionsort(arr,size);
        }
        else if (choice==4){
            printf("Over");
            break;
        }
        else{
            printf("Enter valid choice");
        }
    }
    return 0;
}
//Function to perform bubble sort
void bubblesort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) { // Limit comparisons to the unsorted part
            if (arr[j] > arr[j + 1]) {
                // Swap
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    // Print the sorted array
    printf("Sorted array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// function to perform insertionsort
void insertionsort(int arr[],int size){
    for (int i=1;i<size;i++){
        int key=arr[i];
        int j=i-1;
        while (j>=0 && arr[j]>key){
            arr[j+1]=arr[j];
            j-=1;
        }
        arr[j+1]=key;
    }
    for (int i=0;i<size;i++){
        printf("%d ",arr[i]);
        printf("\n");
    }
}
// function to perform selection sort
void selectionsort(int arr[],int size){
    for (int i=0;i<size;i++){
        int minindex=i;
        for (int j=i+1;j<size;j++){
            if (arr[j]<arr[minindex]){
                minindex=j;
            }

        }
        int temp=arr[minindex];
        arr[minindex]=arr[i];
        arr[i]=temp;
    }
    for (int i=0;i<size;i++){
        printf("%d ",arr[i]);
        printf("\n");
    }
}
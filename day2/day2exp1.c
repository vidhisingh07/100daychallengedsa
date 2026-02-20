// Delete an Element from an Array

// Problem: Write a C program to delete the element at a given 1-based position pos from an array of n integers. Shift remaining elements to the left.

// Input:
// - First line: integer n
// - Second line: n space-separated integers
// - Third line: integer pos (1-based position to delete)

// Output:
// - Print the updated array with (n-1) elements, space-separated

// Example:
// Input:
// 5
// 10 20 30 40 50
// 2

// Output:
// 10 30 40 50

// Explanation: Delete position 2 (element 20), remaining elements shift left
#include<stdio.h>
int main(){
    int size,i,pos;
    int arr[100];
    printf("enetr number of integers in an array: ");
    scanf("%d",&size);
    printf("enetr elements");
    for ( i = 0; i < size;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("enetr position ");
    scanf("%d",&pos);
    for ( i = pos-1; i < size-1; i++)
    {
        arr[i]=arr[i+1];
    }
    size--;
    for ( i = 0; i < size; i++)
    {
        printf("%d ",arr[i]);
    }
    
    return 0;
    
    
}

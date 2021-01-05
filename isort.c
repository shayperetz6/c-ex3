#define size_arr 50
#include <stdio.h>
void printArray(int *arr, int length)
{
    int i;
    for (i=0;i<length-1;i++)
    {
        printf("%d ,", *(arr+i)); 
    }
    printf ("%d",*(arr+i));
    printf ("\n");
}
void shift_element(int* arr, int i)
{
    int j;
    for (j=i;j>0;j--)
    {
        *(arr+j)=*(arr+j-1);
    }
}
void insertion_sort(int* arr , int len)
{
    int i,j,key;
    for (i=1;i<len;i++)
    {
        key=*(arr+i);
        j=i-1;
        while((key<*(arr+j))&&(j>=0))
        {
          j--;
          
        }
        j++;
        int *ptr=arr+j;
        
        shift_element(ptr,i-j);
        *(arr+j)=key;
    }
}

int main()
{
    int array[size_arr];
    int i,num;
    printf ("enter 50 number into array: \n");
    for (i=0;i<size_arr;i++)
    {
        scanf("%d",&num);
        *(array+i)=num;
    }
     insertion_sort(array, size_arr);

    printf("After insetionSort \n");
    printArray(array, size_arr);
    return 0;
}
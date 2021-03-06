#include <stdio.h>
#include <stdlib.h>

void merge(int *A,int s,int m,int l)
{
    int p=s,q=m+1,i,k=0;
    int arr[l-s+1];

    for(i=s;i<=l;i++)
    {
        if(p>m)      //checks if first part comes to an end or not .
            arr[k++]=*(A+q++);
        else if (q>l)   //checks if second part comes to an end or not
            arr[k++]=*(A+p++);
        else if(*(A+p)<*(A+q))     //checks which part has smaller element.
            arr[k++]=*(A+p++);
        else
            arr[k++]=*(A+q++);
    }
    for (int p=0 ; p< k ;p ++)
    {
        *(A+s++)=arr[p] ;
    }

}

void merge_sort(int *A,int start,int end,int size)
{

    if( start < end )
    {
        int mid = (start + end ) / 2 ;
        merge_sort (A, start , mid ,size) ;
        merge_sort (A,mid+1 , end ,size) ;
        merge(A,start , mid , end);

        for(int i=0;i<size;i++)
            printf("%d",*(A+i));
        printf("\n\n");
    }`
}

int main()
{
    int *arr,size;
    arr=(int*)calloc(20,sizeof(int));
    printf("\nEnter size of the array(MAX_20):");
    scanf("%d",&size);
    arr=realloc(arr,size*sizeof(int));
    for(int i=0;i<size;i++)
        scanf("%d",arr+i);

    merge_sort(arr,0,size-1,size);

    printf("\n\nThe final sorted array is:");
    for(int i=0;i<size;i++)
        printf("%d",*(arr+i));
    printf("\n");
    return 0;
}

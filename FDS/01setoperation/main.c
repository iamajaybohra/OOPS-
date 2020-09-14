#include <stdio.h>
#include <stdlib.h>

int get_set(int *arr)
{
    int len,i;

    printf("\nENTER NUMBER OF ELEMENTS(MAXIMUM 20):");
    scanf("%d",&len);

    arr=realloc(arr,len*sizeof(int));

    for(i=0;i<len;i++)
    {   printf(" \nENTER ELEMENT %d:",(i+1));
        scanf("%d",arr+i);
    }

    return len;
}

int correct_set(int *arr1,int l1)
{
    int  i,j,k;

    for(i=0;i<l1;i++)
    {
        for(j=0;(j<l1) && (j!=i);j++)
        {
            if(*(arr1+i)==*(arr1+j))
            {
                for(k=i;k<(l1-1);k++)
                {
                    *(arr1+k)=*(arr1+k+1);
                }
                l1=l1-1;
            }
        }
    }

return l1;
}

void print_set(int *arr,int len)
{
    int i;

    printf("\nLENGTH OF THE SET IS:%d",len);
    printf("\nTHE SET IS:");

    for(i=0;i<len;i++)
        printf("%d ",*(arr+i));

}

int union_set(int *arr1,int l1,int *arr2,int l2,int *arr3)
{
    int i,j,flag,pos=0;
    for(i=0;i<l1;i++)
        *(arr3+i)=*(arr1+i);

    for(i=0;i<l2;i++)
    {   flag=0;
        for(j=0;j<l1;j++)
        {
            if(*(arr2+i)==*(arr1+j))
            {
                flag=1;
                break;
            }
        }
        if(flag==0)
        {
            *(arr3+l1+pos)=*(arr2+i);
            pos++;
        }
    }

return (l1+pos);
}

int intersect_set(int *arr1,int l1,int *arr2,int l2,int *arr3)
{
    int i,j,flag,pos=0;

    for(i=0;i<l2;i++)
    {   flag=0;
        for(j=0;j<l1;j++)
        {
            if(*(arr2+i)==*(arr1+j))
            {
                flag=1;
                break;
            }
        }
        if(flag==1)
        {
            *(arr3+pos)=*(arr2+i);
            pos++;
        }
    }

    return pos;
}
int diff_set(int *arr1,int l1,int *arr2,int l2,int *arr3)
{
    int i,j,flag,pos=0;
    for(i=0;i<l1;i++)
    {   flag=0;
        for(j=0;j<l2;j++)
        {
            if(*(arr1+i)==*(arr2+j))
            {
                flag=1;
                break;
            }
        }
        if(flag==0)
        {
            *(arr3+pos)=*(arr1+i);
            pos++;
        }
    }
return pos;
}

int symmdiff_set(int *arr1,int l1,int *arr2,int l2,int *arr3)
{
    int l3,l4,l5,arr4[40],arr5[20];

    l3=union_set(arr1,l1,arr2,l2,arr4);
    l4=intersect_set(arr1,l1,arr2,l2,arr5);
    l5=diff_set(arr4,l3,arr5,l4,arr3);

    return l5;
}
int main()
{
    int *set1,*set2,*set3,*set4,*set5,*set6,*set7;
    int len1,len2,len3,len4,len5,len6,len7;
    int choice;

    set1=(int*)calloc(20,sizeof(int));
    set2=(int*)calloc(20,sizeof(int));
    set3=(int*)calloc(40,sizeof(int));
    set4=(int*)calloc(20,sizeof(int));
    set5=(int*)calloc(40,sizeof(int));
    set6=(int*)calloc(40,sizeof(int));
    set7=(int*)calloc(40,sizeof(int));

    while(1)
    {
        printf("\n\n\n\t\tSET OPERATIONS\n\nSELECT ANY ONE OF THE FOLLOWING:\n1.INSERT SET ELEMENTS\n2.UNION OF BOTH SETS\n3.INTERSECTION OF THE SETS\n4.DIFFERENCE OF THE SETS\n5.SYMMETRIC DIFFERENCE OF THE SETS\n6.EXIT\n\n....ENTER YOUR CHOICE....");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:printf("\nFOR SET 1:");
                   len1 = get_set(set1);
                   printf("\nFOR SET 2:");
                   len2 = get_set(set2);
                   len1 = correct_set(set1,len1);
                   len1 = correct_set(set1,len1);
                   len2 = correct_set(set2,len2);
                   len2 = correct_set(set2,len2);
                   set1=realloc(set1,len1*sizeof(int));
                   set2=realloc(set2,len2*sizeof(int));
                   printf("\n\nFOR SET 1:");
                   print_set(set1,len1);
                   printf("\n\nFOR SET 2:");
                   print_set(set2,len2);
                   break;

            case 2:len3=union_set(set1,len1,set2,len2,set3);
                   set3=realloc(set3,len3*sizeof(int));
                   print_set(set3,len3);
                   break;

            case 3:len4=intersect_set(set1,len1,set2,len2,set4);
                   set4=realloc(set4,len4*sizeof(int));
                   print_set(set4,len4);
                   break;

            case 4:len5=diff_set(set1,len1,set2,len2,set5);
                   set5=realloc(set5,len5*sizeof(int));
                   printf("\nFOR SET1-SET2:");
                   print_set(set5,len5);
                   len6=diff_set(set2,len2,set1,len1,set6);
                   set6=realloc(set6,len6*sizeof(int));
                   printf("\nFOR SET2-SET1:");
                   print_set(set6,len6);
                   break;

            case 5:len7=symmdiff_set(set1,len1,set2,len2,set7);
                   set7=realloc(set7,len7*sizeof(int));
                   print_set(set7,len7);
                   break;

            case 6:printf("\nTHANK YOU....\n");
                   return 0;

           default:printf("WRONG CHOICE.ENTER ONCE AGAIN!!!");
                   break;

        }

    }


return 0;
}

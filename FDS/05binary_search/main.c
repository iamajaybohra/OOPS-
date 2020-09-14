#include<stdio.h>
#include<string.h>
int bubble_sort(char name[][10],int n)
{
    int round,j;
    int count1=0,count2=0;
    char temp[10];
    int flag = 0;
    for(round = 1 ; round < n ; round++)
    {
        count1++;
        for(j = 0 ; j < n - round ; j++)
        {
            count2++;
            flag=0;
            if(strcmp(&name[j][0],&name[j+1][0])>0)
            {
                    flag = 1;
                    strcpy(temp,&name[j][0]);
                    strcpy(&name[j][0],&name[j+1][0]);
                    strcpy(&name[j+1][0],temp);
            }
        }

        if(flag==0)
        {
            printf("Array sorted\n\n");
            break;
        }
        printf("After Pass ::%d:: ",round);
        for(int i=0;i<n;i++)
        {
            printf("%s\t",&name[i][0]);
        }
        printf("\n");
    }
    printf("\nIn Bubble sort\n\tOuter Loops Runs :: %d Times\n\tInner Loops Runs :: %d Times\n",count1,count2);
    return (count1*count2);
}
int insertion_sort(char name[][10],int n)
{
    char temp[10];
    int i,j;
    int count1=0,count2=0;
    for(i = 1; i < n ; i++)
    {
        strcpy(temp,&name[i][0]);
        j=i-1;
        count1++;
        while( strcmp(&name[j][0],temp) <0 && j >= 0)
        {
            count2++;
            strcpy(&name[j+1][0],&name[j][0]);
            j = j - 1;
        }
        strcpy(&name[j+1][0],temp);
        for(int i=0;i<n;i++)
        {
            printf("%s\t",&name[i][0]);
        }
        printf("\n");
    }
    printf("\nIn Insertion sort\n\tOuter Loops Runs :: %d Times\n\tInner Loops Runs :: %d Times\n",count1,count2);
    return (count1*count2);
}
int binary_search(char name[][10],int r,int l,char word[])
{
    if(l<=r)
    {
        int mid = (l + r)/2;
        if(strcmp(&name[mid][0],word)==0)
            return mid;
        else if(strcmp(&name[mid][0],word)>0)
            return binary_search(name,mid-1,l,word);
        else
            return binary_search(name,r,mid+1,word);
    }
    else
        return -1;
}
int binary_search2(char name[][10],int r,int l,char word[])
{
     int mid = (l + r)/2;
     if(l<=r)
     {

        if(strcmp(&name[mid][0],word)==0)
            return mid;
        else if(strcmp(&name[mid][0],word)>0)
            {
                r = mid - 1;
            }
        else
            {
                l = mid + 1;
            }
    }
    else
        return -1;

}
int main()
{
    int n,x,y,z;
    printf("\n\nHow Many String Do You want To Enter(MAX_10)?\n");
    scanf("%d",&n);
    char word[10];
    int count1,count2;
    char name[10][10];
    int i;
    for(i=0;i<n;i++)
    {
        printf("\nEnter String %d:",i+1);
        scanf("%s",&name[i][0]);
    }
    int ch;
    do
    {
        printf("\n\nSelect any one of the following:\n1.Bubble Sort\n2.Insertion Sort\n3.Binary Search\n4.Exit\nEnter your option:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1 :count1 =  bubble_sort(name,n);
                    break;

            case 2: count2 = insertion_sort(name,n);
                    break;

            case 3:printf("Enter The Word You Want To find!\n");
                   scanf("%s",word);
                   printf("Enter The Way you Want to do the Search:\n1.RECURSIVE BINARY SORT!\n2.NON-RECURSIVE BINARY SORT!\n");
                   scanf("%d",&z);
                   switch(z)
                   {
                        case 1: x = binary_search(name,n-1,0,word);
                                if(x!=-1)
                                    printf("\nGiven word found at Found at:%d",x+1);
                                else
                                    printf("\nNOt Found!!\n");

                                break;

                        case 2: y = binary_search2(name,n-1,0,word);
                                if(y!=-1)
                                    printf("Given word Found at position:%d",y+1);
                                else
                                    printf("NOt Found!!\n");

                                break;
                        default:printf("\nWrong Input!!!!");
                                 break;
                    }
                    break;

            default:printf("\nWrong Input!!!");
                break;

        }

        if(count1>count2)
            printf("\nBubble Sort Takes More Time!\n");
        else if(count2>count1)
            printf("\nInsertion Sort Takes More Time!\n");
        else
            printf("\nBoth Sorting Technique Takes Same Times");
  }while(ch!=4);

return 0;
}










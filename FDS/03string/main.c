#include<stdio.h>
#include<stdlib.h>

int get_string(char *s1)
{
    int i=0;

    printf("\nENTER THE STRING:");
    scanf("%s",s1);

    while(*(s1+i)!='\0')
    {
        i++;
    }

    s1=realloc(s1,i*sizeof(char));

    return i;

}

int compare_string(char *s1,int l1,char *s2,int l2)
{
    int i,flag=0;

    if(l1==l2)
    {
        for(i=0;i<l1;i++)
        {
            if(*(s1+i)!=*(s2+i))
            {
                flag=1;
                break;
            }
        }

        if(flag==0)
        {
            printf("\nBOTH STRINGS ARE EQUAL");
            return 1;
        }
        else
        {
            printf("\nSTRINGS ARE NOT EQUAL");
            return 0;
        }

    }
    else
    {
        printf("STRINGS ARE NOT EQUAL");
        return 0;
    }

}
void reverse_string(char *s1,int l1,char *s2)
{
    int i,end;

    s2=realloc(s2,l1*sizeof(char));
    end=l1-1;

    for(i=0;i<l1;i++)
    {
        *(s2+i)=*(s1+end);
        end--;
    }

    printf("\nTHE REVERSED 1STRING IS:");
    //for(i=0;i<l1;i++)
    printf("%s", s2);

}

void palindrome(char *s1,int l1,char *s2,int l2)
{
    int ret;

    ret=compare_string(s1,l1,s2,l2);

    if(ret==0)
        printf("\nIT IS NOT A PALINDROME!!");
    else
        printf("\nIT IS A PALINDROME");

}

void vowels(char *s1,int l1)
{
    int i,count=0;

    printf("The Vowels in the string are:");
    for(i=0;i<l1;i++)
    {
        if(*(s1+i)=='a'||*(s1+i)=='e'||*(s1+i)=='i'||*(s1+i)=='o'||*(s1+i)=='u'||*(s1+i)=='A'||*(s1+i)=='E'||*(s1+i)=='I'||*(s1+i)=='O'||*(s1+i)=='U')
        {
            count++;
            printf(" %c",*(s1+i));
        }
    }
    printf("\nTOTAL NUMBER OF VOWELS IN THE STRING:%d",count);

}

void check_substring(char *s1,int l1,char *s2,int l2)
{
    int i,j,flag=0,count=0;

    for(i=0;i<l1;i++)
    {
        flag=0;
        for(j=i;j<(l2+i);j++)
        {
            if(*(s1+j)==*(s2+j-i))
            {
                flag=1;
            }
            else if(*(s1+j)!=*(s2+j-i))
            {
                flag=0;
                break;
            }

        }
        if(flag==1)
        {
            count++;
            printf("\nTHE SUBSTRING FOUND AT: %d",i+1);
        }
    }
    if(count==0)
        printf("THE SUBSTRING NOT FOUND!!");

}

int main()
{
    int choice,len1,len2,len3;
    char *str1,*str2,*str3,*str4;

    str1=(char*)calloc(20,sizeof(char));
    str2=(char*)calloc(20,sizeof(char));
    str3=(char*)calloc(20,sizeof(char));
    str4=(char*)calloc(20,sizeof(char));

    while(1)
    {
        printf("\n\n\t\t\t STRING OPERATIONS\n\nSELECT ANY ONE OF THE FOLLOWING\n\n1.ENTER STRING\n2.LENGTH OF STRING\n3.COMPARE STRING\n4.REVERSE THE STRING\n5.CHECK WETHER STRING IS PALINDROME OR NOT\n6.VOWELS IN THE STRING \n7.SUBSTRING OF THE STRING\n8.EXIT\n\n.....ENTER YOUR OPTION....");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:printf("\nFOR STRING 1");
                   len1=get_string(str1);
                   break;

            case 2:printf("\nLENGTH OF THE STRING:%d\n",len1);
                   break;

            case 3:printf("FOR STRING 2");
                   len2=get_string(str2);
                   compare_string(str1,len1,str2,len2);
                   break;

            case 4:reverse_string(str1,len1,str3);
                   break;

            case 5:reverse_string(str1,len1,str3);
                   palindrome(str1,len1,str3,len1);
                   break;

            case 6:vowels(str1,len1);
                   break;

            case 7:printf("FOR SUB-STRING");
                   len3=get_string(str4);
                   check_substring(str1,len1,str4,len3);
                   break;

            case 8:printf("\nTHANK YOU\n");
                   return 0;

            default:printf("WRONG CHOICE.ENTER AGAIN!!!!!");
                    break;

        }
    }


}

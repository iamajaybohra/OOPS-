#include<stdio.h>
typedef struct employee
{
    int id;
    char name[100];
    long int salary;
    int flag;

    union
    {
        long int mob;
        char email[30];
    }r;

}employee;

int main()
{
    employee e[30];
    int i,l,ch,id,j,pos,flag=0;
    int op;
    FILE *f1,*f2;
    do
    {
        printf("\n\n\t______DATABASE RECORD____\n\nSelect any one of the following\n\n1.Create Database\n2.Display Database\n3.Insert a new record\n4.Delete a record\n5.Update a record\n6.Exit\n\nEnter your choice: ");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1 :printf("\nHow many Records do You want to Enter:");
                    scanf("%d",&l);
                    f1 = fopen("main.txt","w+");
                    for(i=0;i<l;i++)
                    {
                        printf("\nEnter ID:");
                        scanf("%d",&e[i].id);
                        for(j=0;j<l;j++)
                        {
                            if(e[i].id == e[j].id && j!=i)
                            {
                                printf("Enter A valid Id!!!\n");
                                scanf("%d",&e[i].id);
                                j=-1;

                            }

                        }
                        printf("Enter Name");
                        scanf("%s",e[i].name);
                        printf("Enter Salary\n");
                        scanf("%d",&e[i].salary);
                        printf("\Select any one of the following:\n1.Email\n2.Mobile Number\n");
                        scanf("%d",&op);
                        if(op == 1)
                        {
                            e[i].flag = 1;
                            scanf("%s",e[i].r.email);
                        }
                        if (op == 2)
                        {
                            e[i].flag = 2;
                            scanf ("%d", &e[i].r.mob);
                        }
                        if (op == 1)
                            fprintf (f1, "%d %s %d %s\n", e[i].id, e[i].name, e[i].salary,e[i].r.email);
                        if (op == 2)
                        fprintf (f1, "%d %s %d %d\n", e[i].id, e[i].name, e[i].salary,e[i].r.mob);

                    }
                    fclose (f1);
                    break;

            case 2: f1 = fopen ("main.txt", "r+");
                    rewind (f1);
                    //for(i=0;i<l;i++)
                    for(i=0; i<l ;i++)
                    {
                        if(e[i].flag == 1)
                        {
                            fscanf(f1,"%d %s %ld %s",&e[i].id,e[i].name,&e[i].salary,e[i].r.email);
                            printf("The Id is ->%d\n",e[i].id);
                            printf("Name ->%s\n",e[i].name);
                            printf("Salary->%ld\n",e[i].salary);
                            printf("Email->%s\n",e[i].r.email);
                            printf("*-*-*-*-*-*-*-*-*-*\n");

                        }
                        if(e[i].flag == 2)
                        {
                            fscanf(f1,"%d %s %ld %ld",&e[i].id,e[i].name,&e[i].salary,&e[i].r.mob);
                            printf("The Id is ->%d\n",e[i].id);
                            printf("Name ->%s\n",e[i].name);
                            printf("Salary->%ld\n",e[i].salary);
                            printf("Mobile Number->%ld\n",e[i].r.mob);
                            printf("*-*-*-*-*-*-*-*-*-*\n");
                        }
                            //si++;
                    }
                    fclose(f1);
                    break;

            case 3 :printf("Enter The position you want to Enter the Record\n");
                    scanf("%d",&pos);
                    f1 = fopen("main.txt","r+");
                    rewind(f1);
                    f2 = fopen("temp.txt","w+");
                    for (i = 0; i < pos - 1 && !feof (f1); i++)
                    {
                        if (e[i].flag == 1)
                        {
	                        fscanf (f1, "%d %s %ld %s", &e[i].id, e[i].name, &e[i].salary,
		                    e[i].r.email);
	                        fprintf (f2, "%d %s %ld %s\n", e[i].id, e[i].name, e[i].salary,
		                    e[i].r.email);
                        }
                        if (e[i].flag == 2)
                        {
	                        fscanf (f1, "%d %s %ld %ld", &e[i].id, e[i].name, &e[i].salary,
		                    &e[i].r.mob);
	                        fprintf (f2, "%d %s %ld %ld\n", e[i].id, e[i].name, e[i].salary,
		                    e[i].r.mob);
                        }
                    }
                    for (j = i; j < l; j++)
                    {
                        e[j + 1] = e[j];
                    }
                    printf ("Enter The id::");
                    scanf ("%d", &e[i].id);
                    printf ("Enter The Name and Salary\n");
                    scanf ("%s %ld", e[i].name, &e[i].salary);
                    printf ("\t1.Email\n\t2.Mobile Number\n");
                    scanf ("%d", &op);
                    if (op == 1)
                    {
                        e[i].flag = 1;
                        scanf ("%s", e[i].r.email);
                    }
                    if (op == 2)
                    {
                        e[i].flag = 2;
                        scanf ("%ld", &e[i].r.mob);
                    }
                    if (op == 1)
                        fprintf (f2, "%d %s %ld %s\n", e[i].id, e[i].name, e[i].salary,e[i].r.email);
                    if (op == 2)
                        fprintf (f2, "%d %s %ld %ld\n", e[i].id, e[i].name, e[i].salary,e[i].r.mob);
                    while (i < l)
                    {
                        if (e[i].flag == 1)
                        {
	                        fscanf (f1, "%d %s %ld %s", &e[i].id, e[i].name, &e[i].salary,e[i].r.email);
	                        fprintf (f2, "%d %s %ld %s\n", e[i].id, e[i].name, e[i].salary,e[i].r.email);
                        }
                        if (e[i].flag == 2)
                        {
	                        fscanf (f1, "%d %s %ld %ld", &e[i].id, e[i].name, &e[i].salary,&e[i].r.mob);
	                        fprintf (f2, "%d %s %ld %ld\n", e[i].id, e[i].name, e[i].salary,e[i].r.mob);
                        }
                        i++;
                    }

                    fclose (f1);
                    f1 = fopen ("main.txt", "w+");
                    rewind (f1);
                    rewind (f2);
                    i = 0;
                    l++;
                    while (i < l)
                    {
                        if (e[i].flag == 1)
                        {
	                        fscanf (f2, "%d %s %ld %s", &e[i].id, e[i].name, &e[i].salary,e[i].r.email);
	                        fprintf (f1, "%d %s %ld %s\n", e[i].id, e[i].name, e[i].salary,e[i].r.email);
                        }
                        if (e[i].flag == 2)
                        {
	                        fscanf (f2, "%d %s %ld %ld", &e[i].id, e[i].name, &e[i].salary,
		                    &e[i].r.mob);
	                        fprintf (f1, "%d %s %ld %ld\n", e[i].id, e[i].name, e[i].salary,e[i].r.mob);
                        }
                        i++;
                    }

                    fclose (f1);
                    fclose (f2);
                    break;

            case 4: printf ("Tell The id No which you want to Delete\n");
                    scanf ("%d", &id);
                    f1 = fopen ("main.txt", "r+");
                    rewind (f1);
                    f2 = fopen ("temp.txt", "w+");
                    for (i = 0; i < l; i++)
                    {
                        if (e[i].id != id)
                        {
	                        if (e[i].flag == 1)
	                        {
	                            fscanf (f1, "%d %s %ld %s", &e[i].id, e[i].name, &e[i].salary,e[i].r.email);
	                            fprintf (f2, "%d %s %ld %s\n", e[i].id, e[i].name, e[i].salary,e[i].r.email);
	                        }
	                        if (e[i].flag == 2)
	                        {
	                            fscanf (f1, "%d %s %ld %ld", &e[i].id, e[i].name, &e[i].salary,&e[i].r.mob);
	                            fprintf (f2, "%d %s %ld %ld\n", e[i].id, e[i].name, e[i].salary,e[i].r.mob);
	                        }
                        }
                        else
                        {
	                        if (e[i].flag == 1)
	                        {
	                            fscanf (f1, "%d %s %ld %s", &e[i].id, e[i].name, &e[i].salary,e[i].r.email);
	                        }
	                        if (e[i].flag == 2)
	                        {
	                            fscanf (f1, "%d %s %ld %ld", &e[i].id, e[i].name, &e[i].salary,&e[i].r.mob);
	                        }
                        }
                    }

                    fclose (f1);
                    //fclose(f2);
                    f1 = fopen("main.txt","w+");
                    //f2 = fopen("temp.txt","r+");
                    rewind(f1);
                    rewind(f2);
                    l--;
                    i=0;
                    while(i<l)
                    {
                        if(e[i].flag == 1)
                        {
                            fscanf(f2,"%d %s %ld %s",&e[i].id,e[i].name,&e[i].salary,e[i].r.email);                            fprintf(f1,"%d %s %ld %s\n",e[i].id,e[i].name,e[i].salary,e[i].r.email);                        }                        if(e[i].flag == 2)                        {                            fscanf(f2,"%d %s %ld %ld",&e[i].id,e[i].name,&e[i].salary,&e[i].r.mob);                            fprintf(f1,"%d %s %ld %ld\n",e[i].id,e[i].name,e[i].salary,e[i].r.mob);
                        }
                        i++;
                    }

                    printf ("Deleted Successfully!!\n");
                    fclose (f1);
                    fclose (f2);
                    break;

            case 5: printf ("Tell The id No which you want to Update\n");
                    scanf ("%d", &id);
                    f1 = fopen ("main.txt", "r+");
                    rewind(f1);
                    f2 = fopen ("temp.txt", "w+");
                    for (i = 0; i < l; i++)
                    {
                        if (e[i].id != id)
                        {
	                        if (e[i].flag == 1)
	                        {
	                            fscanf (f1, "%d %s %ld %s", &e[i].id, e[i].name, &e[i].salary,e[i].r.email);
	                            fprintf (f2, "%d %s %ld %s\n", e[i].id, e[i].name, e[i].salary,e[i].r.email);
	                        }
	                        if (e[i].flag == 2)
	                        {
	                            fscanf (f1, "%d %s %ld %ld", &e[i].id, e[i].name, &e[i].salary,&e[i].r.mob);
	                            fprintf (f2, "%d %s %ld %ld\n", e[i].id, e[i].name, e[i].salary,e[i].r.mob);
	                        }
                        }
                        else
                        {
	                        if (e[i].flag == 1)
	                        {
	                            fscanf (f1, "%d %s %ld %s", &e[i].id, e[i].name, &e[i].salary,e[i].r.email);
	                        }
	                        if (e[i].flag == 2)
	                        {
	                            fscanf (f1, "%d %s %ld %ld", &e[i].id, e[i].name, &e[i].salary,&e[i].r.mob);
	                        }
	                        printf ("Enter The Name and Salary\n");
	                        scanf ("%s %ld", e[i].name, &e[i].salary);
	                        printf ("\t1.Email\n\t2.Mobile Number\n");
	                        scanf ("%d", &op);
	                        if (op == 1)
	                        {
	                            e[i].flag = 1;
	                            scanf ("%s", e[i].r.email);
	                        }
	                        if (op == 2)
	                        {
	                            e[i].flag = 2;
	                            scanf ("%ld", &e[i].r.mob);
	                        }
	                        if (op == 1)
	                            fprintf (f2, "%d %s %ld %s\n", e[i].id, e[i].name, e[i].salary,e[i].r.email);
	                        if (op == 2)
	                            fprintf (f2, "%d %s %ld %ld\n", e[i].id, e[i].name, e[i].salary,e[i].r.mob);
                        }
                    }
                    fclose (f1);
                    //fclose(f2);
                    f1 = fopen("main.txt","w+");
                    //f2 = fopen("temp.txt","r+");
                    rewind(f1);
                    rewind(f2);
                    //l--;
                    i=0;
                    while(i<l)
                    {
                        if(e[i].flag == 1)
                        {
                            fscanf(f2,"%d %s %ld %s",&e[i].id,e[i].name,&e[i].salary,e[i].r.email);
                            fprintf(f1,"%d %s %ld %s\n",e[i].id,e[i].name,e[i].salary,e[i].r.email);

                        }
                        if(e[i].flag == 2)
                        {
                            fscanf(f2,"%d %s %ld %ld",&e[i].id,e[i].name,&e[i].salary,&e[i].r.mob);
                            fprintf(f1,"%d %s %ld %ld\n",e[i].id,e[i].name,e[i].salary,e[i].r.mob);

                        }
                        i++;

                    }
                    printf("Deleted Successfully!!\n");
                    fclose(f1);
                    fclose(f2);
                    break;

                    }

        }while(ch!=6);


    return 0;
    }




#include<stdio.h>
#include<stdlib.h>


void print_mat(int **m,int r,int c)
{
    int i,j;

    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            printf("%d ",*(*(m+i)+j));

        }
        printf("\n");

    }

}

void get_matrix(int **a,int r,int c)
{
    int i,j;

    printf("Enter the numbers row-wise:\n");

    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            scanf("%d",*(a+i)+j);
        }
    }
    printf("\nThe entered matrix is:\n");
    print_mat(a,r,c);

}


void add_matrix(int **m1,int r1,int c1,int **m2,int r2,int c2,int **m3)
{
    int i,j;

    if(r1==r2 && c1==c2)
    {
        for(i=0;i<r1;i++)
        {
            for(j=0;j<c1;j++)
            {
                m3[i][j]=m1[i][j]+m2[i][j];
            }
        }
        printf("\nThe addition of the matrices is:\n");
        print_mat(m3,r1,c1);
    }
    else
        printf("\nThe Addition of these matrices is not possible\n");
}

void sub(int **m1,int r1,int c1,int **m2,int r2,int c2,int **m3)
{
    int i,j;

    if(r1==r2 && c1==c2)
    {
        for(i=0;i<r1;i++)
        {
            for(j=0;j<c1;j++)
            {
                m3[i][j]=m1[i][j]-m2[i][j];
            }
        }
        printf("\nThe Subtraction of the matrices is:\n");
        print_mat(m3,r1,c1);
    }
    else
        printf("\nThe Subtraction of these matrices is not possible\n");

}

void mul(int **m1,int r1,int c1,int **m2,int r2,int c2,int **m3)
{
    int i,j,k,sum=0;

    if(c1==r2)
    {
        for(i=0;i<r1;i++)
        {
            for(j=0;j<c2;j++)
            {
                for(k=0;k<c1;k++)
                {
                   sum=sum+m1[i][k]*m2[k][j];
                }
            m3[i][j]=sum;
            sum=0;
            }
        }
        printf("\nThe multiplication of the matrices is:\n");
        print_mat(m3,r1,c2);

    }
    else
        printf("\nThe multiplication of the matrices is not possible\n");
}

void saddle_point(int **mat,int r,int c)
{
    int i,j,k,min_row,col_ind,flag=0;

    if(r==c)
    {
        for (i = 0; i < r; i++)
        {
        min_row = mat[i][0];col_ind = 0;
		for (j = 1; j < c; j++)
		{
			if (min_row > mat[i][j])
			{
				min_row = mat[i][j];
				col_ind = j;
			}
		}

		 for (k = 0; k < r; k++)
            if (min_row < mat[k][col_ind])
				break;

        if (k == r)
		{
		printf("Value of Saddle Point %d");

		}
	}
    }
    else
        printf("\nNo Saddle point.\n");



}


void trans_matrix(int **m,int r,int c)
{
     int i,j;
     for(i=0;i<r;i++)
     {
         for(j=0;j<c;j++)
         {
             printf("%d ",m[j][i]);
         }
         printf("\n");
     }
}

void magic_matrix(int **m,int r,int c)
{
    int sumr,sumc,sumd1,sumd2,mag,i,j,flag=0;
    if(r==c)
    {
        mag=(r*((r*r)+1))/2;

        for(i=0;i<r;i++)
        {   sumr=0;sumc=0;sumd1=0;sumd2=0;
            for(j=0;j<c;j++)
            {
                sumr+=m[i][j];
                sumc+=m[j][i];
                sumd1+=m[j][j];
                sumd2+=m[j][r-j-1];
            }
            if(sumr!=mag||sumc!=mag||sumd1!=mag||sumd2!=mag)
            {
                flag=1;
                break;
            }

        }
    }
    else
        printf("\nIt is not a magic square\n");


    if(flag==0)
        printf("\nIt is a magic square matrix.\n");
    else
        printf("\nIt is not a square matrix.");
}

int main()
{
    int **mat1,**mat2,**mat3,**mat4,**mat5,**mat6,**mat7,**mat8,r1,r2,r3,r4,c1,c2,c3,c4,i;
    int choice;

    while(1)
    {
        printf("\n\t\t\tMATRIX OPERATIONS:\n\nSELECT ANY ONE OF THE OPTION\n\n1.Enter the matrix\n2.Addition of the matrices\n3.Subtraction of the matrices\n4.Multiplication of the matrices\n5.Find Saddle Point of the matrix\n6.Find Transpose of the matrix\n7.Check whether the matrix is magic square or not\n8.Exit\n\nEnter your choice:");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:printf("Enter the number of rows:");
                   scanf("%d",&r1);
                   printf("Enter the number of columns:");
                   scanf("%d",&c1);

                   mat1=(int**)calloc(r1,sizeof(int*));
                   for(i=0;i<r1;i++)
                   *(mat1+i)=(int*)calloc(c1,sizeof(int));

                   get_matrix(mat1,r1,c1);

                   break;

            case 2:printf("Enter the second matrix\n");
                   printf("Enter the number of rows:");
                   scanf("%d",&r2);
                   printf("Enter the number of columns:");
                   scanf("%d",&c2);

                   mat2=(int**)calloc(r2,sizeof(int*));
                   for(i=0;i<r2;i++)
                   *(mat2+i)=(int*)calloc(c2,sizeof(int));

                   get_matrix(mat2,r2,c2);

                   mat3=(int**)calloc(r2,sizeof(int*));
                   for(i=0;i<r2;i++)
                   *(mat3+i)=(int*)calloc(c2,sizeof(int));

                   add_matrix(mat1,r1,c1,mat2,r2,c2,mat3);
                   break;

            case 3:printf("Enter the second matrix\n");
                   printf("Enter the number of rows:");
                   scanf("%d",&r4);
                   printf("Enter the number of columns:");
                   scanf("%d",&c4);

                   mat6=(int**)calloc(r4,sizeof(int*));
                   for(i=0;i<r4;i++)
                   *(mat6+i)=(int*)calloc(c4,sizeof(int));

                   get_matrix(mat6,r4,c4);

                   mat7=(int**)calloc(r1,sizeof(int*));
                   for(i=0;i<r1;i++)
                   *(mat7+i)=(int*)calloc(c1,sizeof(int));

                   mat8=(int**)calloc(r1,sizeof(int*));
                   for(i=0;i<r1;i++)
                   *(mat8+i)=(int*)calloc(c1,sizeof(int));

                   printf("\nFOR MATRIX 1-MATRIX 2\n");
                   sub(mat1,r1,c1,mat6,r4,c4,mat7);
                   printf("\nFOR MATRIX 2-MATRIX 1\n");
                   sub(mat6,r4,c4,mat1,r1,c1,mat8);

                   break;

            case 4:printf("Enter the second matrix\n");
                   printf("Enter the number of rows:");
                   scanf("%d",&r3);
                   printf("Enter the number of columns:");
                   scanf("%d",&c3);

                   mat4=(int**)calloc(r3,sizeof(int*));
                   for(i=0;i<r3;i++)
                   *(mat4+i)=(int*)calloc(c3,sizeof(int));

                   get_matrix(mat4,r3,c3);

                   mat5=(int**)calloc(r1,sizeof(int*));
                   for(i=0;i<r1;i++)
                   *(mat5+i)=(int*)calloc(c3,sizeof(int));

                   mul(mat1,r1,c1,mat4,r3,c3,mat5);
                   break;

            case 5:saddle_point(mat1,r1,c1);
                   break;

            case 6:trans_matrix(mat1,r1,c1);
                   break;

            case 7:magic_matrix(mat1,r1,c1);
                   break;

            case 8:printf("\nTHANK YOU!\n\n");
                   return 0;

            default:printf("Wrong Choice.Enter Again");
                    break;

        }




    }

    return 0;
}

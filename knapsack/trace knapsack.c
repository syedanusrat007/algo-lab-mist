#include <stdio.h>

int Knapsack(int W[][10],int maxWeight,int item,int w)
{

        int i=item,k=w,G;

        W[i][k]=maxWeight;

        i=item,k=w;
         while(i>0 && k>0)
         {

             if(W[i][k] != W[i-1][k])
             {
                 G=W[i][k];

                 i=i-1;

                k=k-W[i][k];

             }
            else
                i=i-1;

         }

                 return i;
}




int main()
{
         printf("Enter the number of items : ");
    int item;
    scanf("%d", &item);
    printf("Enter the number of weights : ");
    int w;
    scanf("%d", &w);

    int W[item+1][w+1];
    int i;
    int j;

        for (i=0; i<item+1; i++){
            for (j=0; j<w+1; j++){
    scanf("%d",&W[i][j]);
        }
    }

    int maxWeight;
        scanf("%d",&maxWeight);
    int d =Knapsack(W,maxWeight,item ,w);
    printf("%d",d);

        return 0;
}

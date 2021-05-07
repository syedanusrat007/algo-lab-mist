#include<stdio.h>

int Knapsack(int items,int weight[],int value[],int maxWeight)
{
        int B[items+1][maxWeight+1];
        /* B[i][w] represents maximum value that can be attained if the maximum weight is w and
           items are chosen from 1...i */
        /* B[0][w] = 0 for all w because we have chosen 0 items */
        int i,w;
        for(w=0;w<=maxWeight;w++)
        {
                B[0][w]=0;
        }
        /* B[i][0] = 0 for all w because maximum weight we can take is 0 */
        for(i=0;i<=items;i++)
        {
                B[i][0]=0;
        }
        for(i=1;i<=items;i++)
        {
                for(w=0;w<=maxWeight;w++)
                {
                        if(weight[i]<=w)
                        {
                                if(value[i]+B[i-1][w-weight[i]]>B[i-1][w])
                                {
                                        B[i][w] = value[i]+B[i-1][w-weight[i]];
                                }
                                else
                                    B[i][w] = B[i-1][w];
                        }
                        else B[i][w] = B[i-1][w];
                }

        }
        return B[items][maxWeight];
}
int main()
{
        int items;
        scanf("%d",&items);
        int weight[items+1],value[items+1];
        int iter;
        for(iter=1;iter<=items;iter++)
        {
                scanf("%d%d",&weight[iter],&value[iter]);
        }
        int maxWeight;
        scanf("%d",&maxWeight);
        printf("Max value attained can be %d\n",Knapsack(items,weight,value,maxWeight));

        return 0;
}

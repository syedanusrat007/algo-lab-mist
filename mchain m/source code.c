#include <stdio.h>
#include<stdlib.h>
#define sz 10
int c[sz][sz];
int p[]={30,35,15,5,10,20,25};
int s[0] [0];

int mcm(int i, int j)
{
    int min= 100005;

    if(i==j)
        return 0;
    else{

        int k,sum;
        for(k=i;k<j;k++)
        {

            if(c[i][k]==0)
               c[i][k]= mcm(i,k);
            if(c[k+1][j]==0)
                c[k+1][j]=mcm(k+1,j);

                 sum=c[i][k]+c[k+1][j]+p[i-1]*p[k]*p[j];

              if(sum<min){
                   min = sum;

                s[i][j]=k;

              }
        }


    }
    printf("paranthesis at %d\n",s[i][j]);
 return min;
}

int main()
{
    int a,b;
    scanf("%d%d",&a,&b);

    printf("%d",mcm(a,b));
    return 0;
}

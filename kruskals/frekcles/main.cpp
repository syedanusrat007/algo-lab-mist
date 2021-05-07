//In an episode of the Dick Van Dyke show

#include<iostream>


#include<cstring>


#include<string.h>

#include<cmath>

#include<fstream>
#include<cstdlib>



#include<queue>
using namespace std;
#define clr(a) memset(a,0,sizeof(a))
#define fill(a,v) memset(a,v,sizeof(a))
#define PB push_back
#define pi acos(-1.0)
#define eps 1e-9
int P[100+5],rank[100+5];
double arrx[100+5],arry[100+5];

struct Node{
    int a,b;
    double c;
    bool operator < (const Node &p) const{
    return c>p.c;
    }
};

int FIND(int x)
{
    if(x==P[x]) return x;
    else
    return P[x]=FIND(P[x]);
}

void UNION(int a,int b)
{
    if(rank[a]<rank[b])
        P[a]=FIND(b);
    else
    {
        P[b]=FIND(a);
        if(rank[a]==rank[b])
        rank[a]++;
    }
}
Node nd;

int main()
{
    int tc,i,j,n,cnt,A,B,PA,PB;
    double Cost,Tcost;
    priority_queue<Node>pq;
    cin>>tc;
    while(tc--)
    {
        cin>>n;
        cnt=0;
        Tcost=0;
        while(!pq.empty())
        pq.pop();
        for(i=0;i<n;i++)
            {
                cin>>arrx[i]>>arry[i];
                P[i]=i;
                rank[i]=0;
            }

        for(i=0;i<n;i++)
            for(j=i+1;j<n;j++)
                {
                    Cost=sqrt((arrx[j]-arrx[i])*(arrx[j]-arrx[i])+(arry[j]-arry[i])*(arry[j]-arry[i]));
                    nd.a=i;
                    nd.b=j;
                    nd.c=Cost;
                    pq.push(nd);
                }

        while(!pq.empty())
            {
                if(cnt==n-1) break;
                A=pq.top().a;
                B=pq.top().b;
                Cost=pq.top().c;
                PA=FIND(A);
                PB=FIND(B);
                if(PA!=PB)
                    {
                        Tcost+=Cost;
                        cnt++;
                        UNION(PA,PB);
                    }
                pq.pop();

            }

    printf("%.2lf\n",Tcost);
    if(tc)
    cout<<endl;

    }
return 0;
}

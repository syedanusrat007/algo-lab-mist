#include<iostream>
#include<stdio.h>
#include<vector>
#include<queue>
using namespace std;
vector<int>graph[1000];
int time=0;
int v[1000],d[1000],f[1000];
void dfs(int s)
{
    int i;
    v[s]=1;
    time=time+1;
    d[s]=time;
    int u=s;
    for(i=0;i<graph[u].size();i++)
    {
        if(v[graph[u][i]]==0)
        {
            dfs(graph[u][i]);
        }
    }
    time=time+1;
    f[s]=time;
}
int main()
{
    int n,m,x,y,i;
    scanf("%d%d",&n,&m);
    for(i=0;i<m;i++)
    {
        scanf("%d%d",&x,&y);
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    for(i=1;i<=n;i++)
    {
        if(v[i]==0)
        {
            dfs(i);
        }
    }
    for(i=1;i<=n;i++)
    {
        printf("d= %d and f= %d\n",d[i],f[i]);
    }
    return 0;

}
/*8 6
1 2
2 3
2 4
1 5
6 7
6 8*/

#include<bits/stdc++.h>
#define white -1
#define grey 0
#define black 1
#define infinite -9999
using namespace std;
queue<int>v;
int adj[1000][1000],color[1000],dis[1000],p[1000];
void bfs(int n,int s)
{
    int i,m;
    for(i=0;i<n;i++)
    {
        color[i]=white;
        dis[i]=infinite;
        p[i]=infinite;
    }
    color[s]=grey;
    dis[s]=0;
    v.push(s);
    while(!v.empty())
    {
        m=v.front(); v.pop();
        for(i=0;i<n;i++)
        {
            if(adj[m][i]==1 && color[i]==white)
            {
                color[i]=grey;
                dis[i]=dis[m]+1;
                p[i]=m;
                v.push(i);
            }
        }
        color[i]=black;
        cout<<"Edges: "<<m<<endl;
    }
    for(i=0;i<n;i++)
        cout<<"Distance:"<<dis[i]<<" Parent:"<<p[i]<<endl;
}
int main()
{
    int i,j,n,m,a,b;
    cin>>n>>m;
    for(i=0;i<m;i++)
    {
        cin>>a>>b;
        adj[a][b]=1;
        adj[b][a]=1;
    }
    bfs(n,0);

}
/*
9 9
0 1
1 2
0 4
0 3
3 6
6 7
7 8
1 5
4 6
*/

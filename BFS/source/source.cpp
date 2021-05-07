#include <bits/stdc++.h>

using namespace std;
struct edge{
int u,v,w;
};
int pr[10000];
vector<edge>e;

bool cmp(edge x,edge y)
{
    return x.w<y.w;
}
int find(int r)
{
    if(pr[r]==r) return r;
    else return pr[r];
}
int mst(int n)
{
    int i;
    sort(e.begin(),e.end(),cmp);
    for(i=0;i<n;i++)
    {
        pr[i]=i;
    }
    int count=0,s=0;
    for(i=0;i<e.size();i++)
    {
        int u=  find(e[i].u);
         int v=  find(e[i].v);
         if(u!=v)
         {
             pr[u]=v;
             count++;
             s+=e[i].w;
             cout<<u;
             if(count==n-1) break;
         }

    }
    return s;
}

int main()
{
    int i,n,m,u,v,w;
    cin>>n>>m;
    for(i=0;i<m;i++)
    {
       cin>>u>>v>>w;
       edge get;
       get.u=u;
       get.v=v;
       get.w=w;
       e.push_back(get);
    }
    cout<<mst(n);
    return 0;
}

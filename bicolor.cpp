#include <bits/stdc++.h>
using namespace std;
vector<int>edges[1000];
queue<int>q;
int color[1000],visited[1000],tn;

int bipartite(int s)
{
    int j,k,fr;
    memset(color,-1,sizeof color);
    color[s]=1;
    while(!q.empty())
    {
        q.pop();
    }
    q.push(s);
    for(j=0;j<tn;j++)
    {
        visited[j]=0;
    }
    visited[s]=1;
    while(!q.empty())
    {
        fr=q.front();

        //cout<<"Size Of "<<fr<<"="<<edges[fr].size()<<endl;

        for(k=0;k<edges[fr].size();k++)
        {
            if(visited[edges[fr][k]]==0 && color[edges[fr][k]]==-1)
            {
                 q.push(edges[fr][k]);
                 visited[edges[fr][k]]=1;
                 color[edges[fr][k]]=1-color[fr];

            }


        }
        for(k=0;k<edges[fr].size();k++)
        {
            if(visited[edges[fr][k]]==1 && color[edges[fr][k]]==color[fr])
            {
                return false;

            }

        }

        q.pop();
    }
    return true;
}


int main()
{
    int i,e,p,n,u,v,f,m;
    //freopen("10004.txt","r",stdin);
    //freopen("10004out.txt","w",stdout);
    while(1)
    {
        cin>>tn;
        if(tn==0)
        {
            break;
        }
        cin>>e;
        memset(edges,0,sizeof edges);
        for(i=1;i<=e;i++)
        {
            cin>>u>>v;
            edges[u].push_back(v);
        }
        if(bipartite(0))
        {
            cout<<"BICOLORABLE."<<endl;
        }
        else
        {
            cout<<"NOT BICOLORABLE."<<endl;
        }
    }

    return 0;
}

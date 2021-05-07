#include <iostream>
#include <queue>
#include <string.h>
using namespace std;
int dx[]={1,1,1,-1,-1,-1,0,0};
int dy[]={1,0,-1,1,0,-1,1,-1};
int cost[10][10];
int parent[70];
bool visited[70];
int main()
{
    memset(parent,-1,sizeof parent);
    memset(visited,0,sizeof visited);
    memset(cost,255,sizeof cost);
    char a,b;
    cin>>a>>b;
    int s1 = a-'a',s2 = b-'0'-1;
    cin>>a>>b;
    int t1 = a-'a',t2 = b-'0'-1;
    queue<int> q;
    q.push(s1*8 + s2);
    visited[s1*8+s2] = true;
    cost[s1][s2] = 0;
    while(!q.empty())
     {
        int u = q.front(),x=u/8,y=u%8;
        q.pop();
        for(int i=0;i<8;++i)
        {
            int vx = x+dx[i];
            int vy=y+dy[i];
            int v = vx*8+vy;
            if(vx<0 ||vy<0 || vx>=8 ||vy >=8)
                continue;
            visited[v] = true;
            parent[v] = u;
            q.push(v);

        }
    }
    int t = t1*8+t2;
    while(parent[t]!=(-1))
    {
        cout<<t/8<<" "<<t%8<<endl;
        t = parent[t];
   }
}

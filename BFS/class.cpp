#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <list>
#include <utility>
#include <string>
#include <queue>
#define pii pair< int, int>
#define clear(a) memset(a,-1, sizeof(a))
using namespace std;

int dx[]={1,2,2,1,-1,-2,-2,-1};
int dy[]={2,1,-1,-2,-2,-1,1,2};
string str1,str2;
bool visited[10] [10];
int cost[10][10];

void bfs(int a,int b,int c,int d){
  queue<pii>q;
 clear(visited);
q.push(make_pair(a,b));
visited[a][b]=true;
cost[a][b]=0;
while(!q.empty())
{
    pii top =q.front();
    q.pop();
    if(top.first==c  &&  top.second==d )
    {
        cout<<"To get from "<<str1<<" to "<<str2<<" takes "<<cost[top.first][top.second]<<" knight moves.\n ";
        return;
    }
    for(int i=0;i<8;i++)
    {
        int f = top.first+dx[i];
        int s = top.second+dy[i];
        if((f>0 && f<=8)&& (s>0 && s<=8)&& !visited[f][s])
        {
            visited[f][s]=true;
            cost[f][s]=cost[top.first][top.second]+1;
            q.push(make_pair(f,s));
        }

    }
}
}
int main()
{
    while(cin>>str1>>str2)
    {
        int sx= str1[0]-96;
        int sy= str1[1]-48;
        int fx= str2[0]-96;
        int fy= str2[1]-48;
      bfs(sx,sy,fx,fy);

    }


    return 0;
}




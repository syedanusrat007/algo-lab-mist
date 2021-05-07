#include<bits/stdc++.h>
#define SIZE            100010
using namespace std;

int dist[SIZE];
int parent[SIZE];
map<int, vector< pair<int,int> > > graph;
void dijkstra(int s,int e)
{
    dist[s] =0;
    priority_queue< pair<int,int> > q;
    q.push(make_pair(0,s));
    while(!q.empty()){
        int u = q.top().second;
        q.pop();
        if(u==e) return;
        for(int i =0;i<graph[u].size();i++){
            int v= graph[u][i].first;
            int cost= graph[u][i].second;
            if(dist[v]==-1 || dist[u]+cost < dist[v]){
                dist[v] = dist[u]+cost;
                parent[v]=u;
                q.push(make_pair(-dist[v],v));
            }
        }
    }
}
void printpath(int n)
{
    if(parent[n]==0){
        printf("%d",n);
        return;
    }
    printpath(parent[n]);
    printf(" %d",n);
}
int main()
{
    memset(dist,-1,sizeof(dist));
    int n,m;
    cin>>n>>m;
    for(int i =0 ;i < m;i++){
        int x,y,z;
        cin>>x>>y>>z;

        graph[x].push_back(make_pair(y,z));
        graph[y].push_back(make_pair(x,z));
    }
    dijkstra(1,n);
    if(dist[n]==-1) puts("-1");
    else printpath(n);
    return 0;
}

#include<bits/stdc++.h>
#define pb(a)           push_back(a)
#define pii             pair<int,int>
#define mp(a,b)         make_pair(a,b)
#define ff              first
#define ss              second
#define SIZE            100010
#define write           freopen("output.txt","w",stdout)
#define read            freopen("input.txt","r",stdin)
#define eps             1e-9
using namespace std;
typedef long long int L;
int biton(int n,int pos){return n=n | (1<<pos);}
int bitoff(int n,int pos){return n=n & ~(1<<pos);}
bool bitcheck(int n,int pos){return (bool)(n & (1<<pos));}
inline int nxt(){int a;scanf("%d",&a);return a;}
inline L NXT(){L a;scanf("%lld",&a);return a;}
L dist[SIZE];
int parent[SIZE];
map<int, vector<pii> > graph;
void dijkstra(int s,int e)
{
    dist[s] =0;
    priority_queue < pii, vector <pii>, greater <pii> > q;
    q.push(mp(0,s));
    while(!q.empty()){
        int u = q.top().ss;
        q.pop();
        if(u==e) return;
        for(int i =0;i<graph[u].size();i++){
            int v= graph[u][i].ff;
            int cost= graph[u][i].ss;
            if(dist[v]==-1 || dist[u]+cost < dist[v]){
                dist[v] = dist[u]+cost;
                parent[v]=u;
                q.push(mp(dist[v],v));
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
    int n = nxt(), m=nxt();
    for(int i =0 ;i < m;i++){
        int x=nxt(),y=nxt(),z=nxt();
        graph[x].pb(mp(y,z));
        graph[y].pb(mp(x,z));
    }
    dijkstra(1,n);
    if(dist[n]==-1) puts("-1");
    else printpath(n);
    return 0;
}

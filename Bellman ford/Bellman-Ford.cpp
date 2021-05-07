//THIS IS MY DESIGN

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
#define inf             (1<<26)
using namespace std;
typedef long long int L;
int biton(int n,int pos){return n=n | (1<<pos);}
int bitoff(int n,int pos){return n=n & ~(1<<pos);}
bool bitcheck(int n,int pos){return (bool)(n & (1<<pos));}
inline int nxt(){int a;scanf("%d",&a);return a;}
inline L NXT(){L a;scanf("%lld",&a);return a;}
int dist[SIZE];
struct edge {
    int x,y,z;
};
vector<edge> v;
bool bellmanFord(int s,int n)
{
    for(int i =1 ;i<=n;i++) dist[i] =inf;
    dist[s]=0;
    //cout<<s<<endl;
    for(int i= 1;i<n;i++){
        for(int j=0;j<v.size();j++){
//            cout<<v[j].x <<' '<<v[j].y <<' '<<v[j].z<<endl;
//            cout<<dist[v[j].x] <<' '<<dist[v[j].y] <<endl;
            if(dist[v[j].y] > dist[v[j].x]+v[j].z){
                dist[v[j].y] = dist[v[j].x]+v[j].z;
                //cout<<v[j].y<<' '<<dist[v[j].y]<<' '<< v[j].x <<' '<<dist[v[j].x] <<' '<<v[j].z<<endl;
            }
        }
    }
    for(int i=0;i<v.size();i++){
            if(dist[v[i].y] > dist[v[i].x]+v[i].z){
                return true;
        }
    }
}
int main()
{
    int n=nxt(),m=nxt();
    for(int i =0 ;i<m;i++){
        int a=nxt(),b=nxt(),c=nxt();
        edge e;
        e.x=a;
        e.y=b;
        e.z=c;
        v.pb(e);
    }
    int start=nxt(),destination=nxt();
    bool cycle = bellmanFord(start,n);
    if(cycle) puts("Negetive Cycle detected");
    else printf("%d\n",dist[destination]);
    return 0;
}


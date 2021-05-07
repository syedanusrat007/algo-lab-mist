#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
vector<pair<int,ii> > edjlist;
vector<int> d;
int main()
{
    int i,j,k,l,m,n,a,b,c;
    cin>>n>>m;
    d.assign(n,100000);
    for(i=0;i<m;i++)
    {
        cin>>a>>b>>c;
        edjlist.push_back(make_pair(c,ii(a,b)));

    }
    d[0]=0;
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<m;j++)
        {
            pair<int,ii>v=edjlist[j];
            if(d[v.second.second]>d[v.second.first]+v.first)
                d[v.second.second]=d[v.second.first]+v.first;
        }
    }
    for(j=0;j<m;j++)
        {
            pair<int,ii>v=edjlist[j];
            if(d[v.second.second]>d[v.second.first]+v.first)
                //d[v.second.second]=d[v.first.second]+v.first;
                {
                    cout<<"no solution";
                    return 0;
                }
        }
        for(i=0;i<n;i++)
            cout<<i<<": "<<d[i]<<endl;
}

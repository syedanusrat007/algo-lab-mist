#include <iostream>
#include <vector>
#include <list>
#include <cstdio>
#include <utility>
#include <bits/stdc++.h>
using namespace std;

void bfs(vector <list <int> > adjlist, int p[],int l[],int s)
{

    list<int> :: iterator itr;
    l[s]=0;
    list<int>vqueue;

    vqueue.push_back(s);

    cout<<"bfs traversal : \n";

    while(!vqueue.empty())
    {
        int newv= vqueue.front();
        cout<<newv<<" ";
        itr=adjlist[newv].begin();

        while(itr!=adjlist[newv].end())
        {
            if(l[*itr]==1){
                l[*itr]=l[newv]+1;
                p[*itr]=newv;
                vqueue.push_back(*itr);

            }
             itr++;
        }
        vqueue.pop_front();
    }


}

int main()
{

   int ver,e,v1,v2,i;
   cout<<"enter vertices : \n";
   cin>>ver;
   cout<<"enter edges : \n";
   cin>>e;

   vector< list<int> > adjlist[ver+1];
   cout<<"enter edges v1->v2 : \n";
   for(i=1;i<=e;i++)
   {
       cin>>v1>>v2;
       adjlist[v1].push_back(v2);
       adjlist[v2].push_back(v1);
   }
   cout<<"list : \n";
   for(i=1;i< adjlist.size();i++)
   {
       cout<<"list["<<i<<"]";
       list<int>:: iterator itr= adjlist[i].begin();
       while(itr!=adjlist[i].end())
       {
           cout<<" -> "<<*itr;
           itr++;
       }
       cout<<"\n";
   }

   int p[ver+1];
   int l[ver+1];











}

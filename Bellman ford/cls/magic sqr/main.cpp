#include <iostream>
#include <cmath>
using namespace std;


int main()
{
    int newrow,newcolom,n,value;
    cout<<"please enter an odd integer : \n";
    cin>>n;

    int magic_squre[n][n];

    for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
       magic_squre[i][j] = 0;
    }
  }
  int i=0;
    int j=floor(n/2);
    for(value=1;value<=n*n;value++)
    {
       magic_squre[i][j]=value;
       newrow=(i+1)%n;

       newcolom=(j+1)%n;
       if(magic_squre[newrow][newcolom]==0)
       {
           i=newrow;
           j=newcolom;
          // cout<<i<<" "<<j;
           //cout<<endl;
       }
       else{
        i=(i-1+n)%n;

        // cout<<i<<" "<<j;
          // cout<<endl;
       }
       }


    for(int x=0;x<n;x++)
    {
        for(int y=0;y<n;y++)
        {
            cout<<magic_squre[x][y]<<" ";
        }
       cout<<endl;
    }



    return 0;
}


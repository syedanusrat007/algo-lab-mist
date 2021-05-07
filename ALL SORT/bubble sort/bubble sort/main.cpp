#include <iostream>

using namespace std;

int main()
{
    int i,j,n;
    cin>>n;
    int a[n];
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(i=1;i<n;i++)
    {
        for(j=0;j<n-1;j++)
        {
            if(a[j]>a[j+1])
                swap(a[j+1],a[j]);
        }
    }
    cout<<"sorted array is : "<<endl;
     for(i=0;i<n;i++)
    {
        cout<<a[i]<<endl;
    }


    return 0;
}

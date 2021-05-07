#include <iostream>

using namespace std;

int main()
{
 int i,j,n,key;
    cin>>n;
    int a[n];
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(i=0;i<n;i++)
    {
        j=i;
       while(j>0 && a[j]<a[j-1])
        {
            swap(a[j],a[j-1]);
            j--;
        }

    }
    cout<<"sorted array is : "<<endl;
     for(i=0;i<n;i++)
    {
        cout<<a[i]<<endl;
    }

    return 0;
}

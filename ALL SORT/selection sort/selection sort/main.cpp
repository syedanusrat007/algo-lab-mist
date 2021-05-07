#include <iostream>

using namespace std;

int main()
{
    int i,j,n;
    cin>>n;
    int arr[n];
    for(i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int pos_min;

	for (int i=0; i < n-1; i++)
	{
	    pos_min = i;

		for (int j=i+1; j < n; j++)
		{

		if (arr[j] < arr[pos_min])
                   pos_min=j;

		}

            if (pos_min != i)
            {
                 swap (arr[i],arr[pos_min]);

            }
	}
    cout<<"sorted array is : "<<endl;
     for(i=0;i<n;i++)
    {
        cout<<arr[i]<<endl;
    }


    return 0;
}

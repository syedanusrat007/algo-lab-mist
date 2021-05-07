#include <iostream>
#include <stdlib.h>
using namespace std;

#define MAXSIZE 100

int heap[MAXSIZE] = {-99999};
int heapSize;
void init()
{
    heap[0] = 0;
    heapSize = 0;
}
int left(int i)
{
    return 2*i;
    //your code here
}
int right(int i)
{
    return 2*i+1;
    //your code here
}
void insert(int x)
{
    int hole = ++heapSize;

  for( ; hole>1 && x < heap[hole/2] ; hole = hole/2)
      heap[hole] = heap[hole/2];
  heap[hole] = x;

   //your code here
}
void percolateDown(int hole)
{
    int tmp=heap[hole];
    int target;
  while (2*hole <= heapSize) {
    int l = left(hole);
    int r = right(hole);
    if (r <= heapSize && heap[r] < heap[l])
       target = r;
    else
      target = l;
    if (heap[target] < tmp) {
      heap[hole] = heap[target];
      hole = target;
    }
    else
      break;
  }
  heap[hole] = tmp;

	//your code here
}
void buildHeap()
{
    int i;
    for(i=heapSize/2;i>=1;i--)
    {
        percolateDown(i);
    }


}
int deleteMin()
{
  int x = heap[1];
  heap[1]=heap[heapSize--];
  percolateDown(1);
  return x;
//your code here
}
void heapsort()
{
    buildHeap();
   int m=heapSize,i;
   for(i=1;i<=m-1;i++)
   {
       heap[m-i+1]=deleteMin();
   }
   heapSize=m;
   for(i=1;i<=heapSize;i++)
        cout<<heap[i]<<" ";
    cout<<"\n";

//your code here
}
int main()
{
    init();
    int choice, num;

    int n = 0;
    while(1)
    {
        cout<<"\n1. Insert item. 2. heap sort. \n";



        int ch;
        cin>>ch;
        if(ch==1)
        {
          cout<<"Enter the element to be inserted to the list : ";

            cin>>num;

            insert(num);
            n++;}
             else if(ch==2)
        {
            cout<<"Heap sort\n";


            heapsort();
        }

        }

    return 0;
}

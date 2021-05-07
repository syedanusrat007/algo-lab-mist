/*
Assignment designed by Deen Md. Abdullah, Senior Lecturer, CSE,
For query: rabi.mist@gmail.com
*/

/*
Task:
Run your program for two times and take the maximum between them.
*/

#include<stdio.h>
#include<time.h>
#include<stdlib.h>

int main(){

    FILE *fptr;
    clock_t begin;

    if ((fptr=fopen("input.txt","r"))==NULL){
       printf("Error! opening file");
       exit(1);
    }

    int n, a[11000],i,t=20;
    while(t--){
        fscanf(fptr,"%d",&n);

        for(i=0;i<n;i++)
        {
            fscanf(fptr,"%d",&a[i]);
        }

        begin = clock();

    //---------------------------------------------------
        /* here, do your time-consuming job */


    //---------------------------------------------------
        clock_t end = clock();
        double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;     // time_spent in second

        time_spent=time_spent*1000.f;     // // time_spent in milisecond
        printf("\nTime(ms) for n=%d: %.0lf",n,time_spent);
    }
    return 0;
}

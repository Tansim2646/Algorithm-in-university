#include <bits/stdc++.h>

using namespace std;
struct Activity
{
    string Name;
    int start_time=0;
    int finish_time=0;


};
void sort(Activity arr[],int x) //Insertion sort used here for sort
{
    int i,j;
    Activity key;
    for(i=1; i<x; i++)
    {
        key=arr[i];
        j=i-1;
        while(j>=0 && arr[j].finish_time>key.finish_time)
        {
            arr[j+1]=arr[j];
            j--;

        }
        arr[j+1]=key;
    }
}
void Activity_selection(Activity arr[],int x)
{
    sort(arr,x);
    cout<<"Sorted Activity"<<endl;
    for(int i=0; i<x; i++)
    {
        cout<<arr[i].Name<<" "<<arr[i].start_time<<" "<<arr[i].finish_time<<endl;
    }
    Activity newarray[x];
    int j=0;
    int count=0;

    newarray[count]=arr[0];
    for(int i=1; i<x; i++)
    {
        if(arr[i].start_time>=arr[j].finish_time)
        {
            newarray[count+1]=arr[i];
            j=i;
            count++;


        }
    }
    cout<<"Maximum Activity"<<endl;

    for(int i=0; i<=count; i++)
    {
        cout<<newarray[i].Name<<" "<<newarray[i].start_time<<" "<<newarray[i].finish_time<<endl;
    }

}

int main()
{
    int n=6;
    Activity arr[6]= {{"A",5,9},{"B",1,2},{"C",3,4},{"D",0,6},{"E",5,7},{"F",8,9}};
    cout<<"Input Activity:"<<endl;
    for(int i=0; i<n; i++)
    {
        cout<<arr[i].Name<<" "<<arr[i].start_time<<" "<<arr[i].finish_time<<endl;
    }


    Activity_selection(arr,n);



}

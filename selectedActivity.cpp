#include<bits/stdc++.h>
using namespace std;
struct Activity
{
    int Start_time;
    int End_time;
};
bool AS(Activity a1, Activity a2)
{
return(a1.End_time < a2.End_time);
}

int main()
{
    int n;
    cout<<"Number of Activity: ";
    cin>>n;
    Activity arr[n];
    for(int i=0; i<n; i++)
    {
        cin>> arr[i].Start_time >> arr[i].End_time;
    }
    cout<<"Print all activity: "<<endl;
    for(int i=0; i<n; i++)
    {
        cout<<"starting_time: " << arr[i].Start_time << "ending_time:"  << arr[i].End_time;
        cout<<endl;
    }
    sort(arr,arr+n, AS);
    cout<<"Print sorted array: "<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<"starting_time: " << arr[i].Start_time << "ending_time:"  << arr[i].End_time;
        cout<<endl;
    }
    cout<<"Print selected activity: "<<endl;
   int i=0;
        cout<<"starting_time: " << arr[i].Start_time << "ending_time:"  << arr[i].End_time;
        cout<<endl;
        for(int j=1;j<n;j++)
        {
            if(arr[i].End_time <= arr[j].Start_time)
            {
            cout<<"starting_time: " << arr[j].Start_time << "ending_time:"  << arr[j].End_time;
            i=j;
            cout<<endl;
            }

        }

    return 0;
}

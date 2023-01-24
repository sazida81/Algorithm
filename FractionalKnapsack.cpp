#include<bits/stdc++.h>
using namespace std;
struct ITEM
{
    int price;
    int weight;
};
bool DES(ITEM a1, ITEM a2)
{
    double perunit1 = (double)a1.price / (double)a1.weight;
    double perunit2 = (double)a2.price / (double)a2.weight;
    return(perunit1>perunit2);
}
double knapsack(int cap, ITEM arr[], int n)
{
    sort(arr,arr+n, DES);
    double T=0;
    for(int i=0;i<n;i++)
    {
        if(cap>=arr[i].weight)
        {
            T+=arr[i].price;
            cap-=arr[i].weight;
        }
        else
        {
            double perunit = (double)arr[i].price / (double)arr[i].weight;
            T+=perunit * cap;
        }
    }
    return T;
}
int main()
{
    int n;
    cin>>n;
    int cap;
    cin>>cap;
    ITEM arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i].price >> arr[i].weight;
    }
    cout<<"Print All Item: "<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<" price: " << arr[i].price << " weight: " << arr[i].weight;
        cout<<endl;
    }
    cout<<"Print Knapsack list: ";
    cout<<knapsack(cap, arr, n) <<endl;

}

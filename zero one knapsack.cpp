#include<bits/stdc++.h>
#define sazida() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
int main()
{
    int item,cap,mini;
    cout<<"Enter the capacity: ";
    cin>>cap;
    cout<<"Enter the item: ";
    cin>>item;
    int weight[item];
    int price[item];
    int a = item;
    int b = cap;
    cout<<"Enter the weight: ";
    for(int i=0; i<a; i++)
    {
        cin>>weight[i];     ///the length of weight is the number of item's (a) weight.
    }
    cout<<"Enter the price: ";
    for(int i=0; i<a; i++)
    {
        cin>>price[i];     ///the length of price is the number of item's (a) price.
    }
    int knap[a+1][b+1];   ///item+1 ; capacity+1
    for(int i=0; i<=a; i++)
    {
        for(int j=0; j<=b; j++)
        {
            if(i==0 || j==0)
            {
                knap[i][j] = 0;
            }
        }
    }
    for(int i=1; i<=a; i++)
    {
        for(int j=1; j<=b; j++)
        {
            if(weight[i-1]>j) ///weight of 0th item. items are start from 0 index but here loop start from 1 index so (i-1)
            {
                knap[i][j] = knap[i-1][j];
            }
            else
            {
                mini = j-weight[i-1]; ///we have to do minus the taken weight from total capacity
                if(knap[i-1][mini]+price[i-1]>=knap[i-1][j]) ///add the price of this index with resulted capacity
                {
                    knap[i][j] = knap[i-1][mini]+price[i-1];
                }
                else
                {
                    knap[i][j] = knap[i-1][j];
                }
            }
        }
    }
    cout<<"Print the knapsack table: ";
    for(int i=0; i<=a; i++)
    {
        for(int j=0; j<=b; j++)
        {
            cout<<knap[i][j]<<" ";
        }
        cout<<endl;
    }
    int cnt=0;
    int i=a;
    int j=b;
    vector<int>w;
    vector<int>p;
    while(i>0 && j>0)
    {
        if(knap[i][j]!=knap[i-1][j])
        {
            w.push_back(i);
            p.push_back(price[i]);
            cap-=weight[i-1];
            i--;
            j = cap;
            cnt++;
        }
        else
        {
            i--;
        }

    }
    cout<<"Total selected item: "<<" "<<cnt<<endl;
    reverse(w.begin(),w.end());
    reverse(p.begin(),p.end());
    cout<<"Selected weights: ";
    for(int i=0; i<w.size(); i++)
    {
        cout<<w[i]<<" ";
    }
    cout<<endl;
    cout<<"Selected price: ";
    for(int i=0; i<p.size(); i++)
    {
        cout<<p[i]<<" ";
    }
}

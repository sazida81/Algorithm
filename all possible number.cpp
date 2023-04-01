#include<bits/stdc++.h>
#define sazida() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
int main()
{
    int total,item;
    cout<<"Enter the total value:" ;
    cin>>total;
    cout<<"Enter the item number: ";
    cin>>item;
    int a = item;
    int coin[a];
    int b = total;
    int dif;
    int change[a+1][b+1];
    int Nchange[a+1][b+1];
    cout<<"Print the item list: ";
    for(int i=0;i<a;i++)
    {
        cin>>coin[i];
    }
    for(int i=0;i<=a;i++)
    {
        change[i][0] = 1;
    }
    for(int j=1;j<=b;j++)
    {
        change[0][j] = 0;
    }
    for(int i=1;i<=a;i++)
    {
        for(int j=1;j<=b;j++)
        {
            if(coin[i-1]>j)
            {
                change[i][j] = change[i-1][j];
            }
            else
            {
                dif = j-coin[i-1];
                Nchange[i][j] = change[i][dif];
                change[i][j] = Nchange[i][j] + change[i-1][j];
            }
        }
    }
    cout<<"Print the table: "<<endl;
    for(int i=0;i<=a;i++)
    {
        for(int j=0;j<=b;j++)
        {
            cout<<change[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"Print the maximum possible ways: ";
    cout<<change[a][b]<<endl;
}

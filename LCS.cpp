
#include<bits/stdc++.h>
#define sazida() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
int main()
{
    string a,s;
    cin>>a>>s;
    int l1,l2;
    l1 = a.size();
    l2 = s.size();
    int LCS[l1+1][l2+1];
    char DIRECTION[l1+1][l2+1];
    for(int i=0;i<=l1;i++)
    {
        for(int j=0;j<=l2;j++)
        {
            if(i==0 || j==0)
            {
                LCS[i][j] = 0;
            }
            else
            {
                if(a[i-1]==s[j-1])   ///both string start with 1 index but we need to start from 0 index so (i-1)(j-1)
                {
                    LCS[i][j] = LCS[i-1][j-1]+1; ///(i-1)(j-1) for taking diagonal value
                    DIRECTION[i][j] = 'D';
                }
                else if(LCS[i-1][j]>=LCS[i][j-1])
                {
                    LCS[i][j] = LCS[i-1][j]; ///(i-1) is for taking upper row of same coloumn
                    DIRECTION[i][j] = 'U';
                }
                else
                {
                    LCS[i][j] = LCS[i][j-1];  ///(j-1) is for taking left sided row of same coloumn
                    DIRECTION[i][j] = 'L';
                }
            }
        }
    }
    for(int i=0;i<=l1;i++)
    {
        for(int j=0;j<=l2;j++)
        {
            cout<<LCS[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"LCS Length: "<<LCS[l1][l2]<<endl;
    for(int i=1;i<=l1;i++)
    {
        for(int j=1;j<=l2;j++)
        {
            cout<<DIRECTION[i][j]<<" ";
        }
        cout<<endl;
    }
    int i = l1;
    int j = l2;
    string subsequence;
    while(i>0 && j>0)
    {
        if(DIRECTION[i][j] == 'U')
        {
            i--; ///we will check from upper column
        }
        else if(DIRECTION[i][j] == 'L')
        {
            j--;  ///we will check from left column
        }
        else
        {
            subsequence+=a[i-1];  ///(i-1)for select diagonal value
            i--;   ///i-- & j-- for checking diagonally
            j--;
        }
    }
    reverse(subsequence.begin(),subsequence.end());
    cout<<"LCS String: "<<" "<<subsequence<<endl;
}

#include<bits/stdc++.h>
#define sazida() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define N 10
using namespace std;
//const int N=10e3;
vector<int>graph[N];
bool visit[N];
int BFS(int start)
{
    queue<int>q;
    q.push(start);
    visit[start] = true;
    cout<<start<<" ";
    while(!q.empty())
    {
        int head = q.front();
        q.pop();
        for(auto P:graph[head])
        {
            if(!visit[P])
            {
                visit[P] = true;
                q.push(P);
                cout<<P<<" ";
            }
        }
    }
}
int main()
{
    int node,edge;
    cin>>node>>edge;
    for(int i=0;i<edge;i++)
    {
        int v1,v2;
        cin>>v1>>v2;
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }
    BFS(1);
    return 0;
}


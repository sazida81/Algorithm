#include<bits/stdc++.h>
#define sazida() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define s_tc() int t; cin>>t; for(int i=0;i<t;i++)
#define sze 10
using namespace std;
vector<int>graph[sze];
bool visit[sze];
int DFS(int start)
{
    stack<int>q;
    q.push(start);
    visit[start] = true;
    cout<<start<<" ";
    while(!q.empty())
    {
        int head = q.top();
        q.pop();
        for(auto P:graph[head])
        {
            if(!visit[P]==true)
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
    int node,edge,start;
    cout<<"Enter the node number: ";
    cin>>node;
    cout<<"Enter the edge number: ";
    cin>>edge;
    for(int i=0; i<edge; i++)
    {
        int v1,v2;
        cin>>v1>>v2;
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }
    cout<<"Enter the start node: ";
    cin>>start;
    DFS(start);
}

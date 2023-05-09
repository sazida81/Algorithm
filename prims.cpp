#include<bits/stdc++.h>
using namespace std;
int main()
{
    int node;
    cout<<"Enter the number of node: ";
    cin>>node;
    int edge;
    cout<<"Enter the number of edge: ";
    cin>>edge;
    vector< pair<int,int> > adj[node];
    for(int i=0;i<edge;i++)
    {
        int u,v,w; ///u=(starting node: in which node we will start from)
                   ///v=(connected node: in which node we will go from starting node)
        cin>>u>>v>>w;
        adj[v].push_back({u,w});
        adj[u].push_back({v,w});
    }
    int key[node]; ///to store all the weights of graph
    int parent[node]; ///to store (u) ex: if a node A go through node B then A node will be stored in parent array
    bool isMST[node];
    for(int i=0;i<node;i++)
    {
        key[i] = INT_MAX; ///assume initially all weights are max
        isMST[i] = false;
    }
    key[0] = 0; ///first starting node has no weight
    parent[0] = -1; ///first starting node comes from infinity
    priority_queue< pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0,0}); ///first: weight; second:(v) ex: if a node A go through node B then B node will be stored in queue
    while(!pq.empty())
    {
        int pNode = pq.top().second; ///first connected node
        pq.pop();
        isMST[pNode] = true;
        for(auto a:adj[pNode]) ///checking by tree
        {
            int v = a.first; ///to store all connected node
            int weight = a.second; ///to store all connected nodes weight
            if(isMST[pNode]==false && weight<key[v])
            {
                key[v] = weight;
                parent[v] = pNode; ///parent[v] means we are in (v) node and pNode will be act like (v)
                pq.push({weight,v});
            }
        }
    }
}

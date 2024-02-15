//detecting cycle in a undirected graph :
//the trick is that we run a for loop on the nodes of  a particular node and call the dfs for each of them on condition that they weren't previously visited.
//for first node we pass the parent of the node as -1 and at every call we check whether the parent of the node and the node are same if they are same no cycle detected
//else if the current node being processed and the parent of that node are not same then the cycle is detected.
#include<bits/stdc++.h>
using namespace std;
bool DFS(int node,int parent,vector<int>adj[],int vis[])
{
    vis[node]=1;
    for(auto it:adj[node])
    {
        if(!vis[it])
        {
            if(DFS(it,node,adj,vis))
            return true;
        }
        else if(it!=parent)
        return true;
    }
    return false;
}
bool checkCycle(int V,vector<int>adj[])
{
    int vis[V+1];
    for(int i=0;i<V;i++)
    {
        if(!vis[i])
        if(DFS(i,-1,adj,vis))
        return true;
    }
    return false;
}
int main()
{
    int n,e;
    cin>>n>>e;
    vector<int>adj[n+1];
    for(int i=0;i<e;i++)
    {
        int u,v;cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int>ans;
    int vis[n+1]={0};
    if(checkCycle(n,adj))
    cout<<"Cycle detected";
    else
    cout<<"Cycle not detected";
}

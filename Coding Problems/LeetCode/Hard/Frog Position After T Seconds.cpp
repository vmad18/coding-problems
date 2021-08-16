#include <bits/stdc++.h>

using namespace std; 

vector<int> dfs(vector<vector<int>> &adj, vector<bool> &visited, vector<int> nodes, int n, int g, int time){
    if(visited[n]) return {}; 

    visited[n] = true; 
    nodes.push_back(n);
    
    time--;

    if(time<0) return {}; 

    if(n==g){
        if(n==1){
            if(!time || !(adj[n].size()))
                return nodes;
        }else{
            if(!time || !(adj[n].size()-1))
                return nodes;
        }
        return {}; 
    }

    vector<int> v;
    for(int i:adj[n]){
        if(!visited[i]){
            v = dfs(adj, visited, nodes, i, g, time);
            if(v.size()) return v; 
        }
    }
    return {}; 
}


double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
    
    if(!edges.size()) return 1; 
    
    vector<vector<int>> adj(n+1); 
    vector<bool> visited(n+1, false); 
    
    for(vector<int> v:edges){
        adj[v[0]].push_back(v[1]);
        adj[v[1]].push_back(v[0]); 
    }
    
    vector<int> path = dfs(adj, visited, {}, 1, target, t+1);
    
    if(!(path.size())) return 0; 
    
    double chance=1; 
    for(int i=0;i<path.size()-1;i++){
        if(!i) chance *= ((double) 1)/((double) adj[path[i]].size());
        else chance *= ((double) 1)/((double) adj[path[i]].size()-1);
    }
    return chance; 
}
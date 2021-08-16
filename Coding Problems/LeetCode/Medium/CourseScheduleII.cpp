void addEdge(vector<int> adj[], int u, int v){
    adj[u].push_back(v);
}

void dfs(vector<int> adj[], vector<bool> &visited, queue<int> &top, int n){
    
    if(visited[n]) return; 
    
    visited[n] = true;
    
    for(int i:adj[n]){
        if(!visited[i]){
            dfs(adj, visited, top, i); 
        }
    }
    
    top.push(n); 
}


vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    const int nc = numCourses; 
    vector<int> adj[nc]; 
    for(vector<int> i:prerequisites){
        addEdge(adj, i[0], i[1]); 
    }
    
    vector<bool> visited(nc, false); 
    queue<int> tops; 
    for(int i=0;i<numCourses;i++){
        if(!visited[i]){
            dfs(adj, visited, tops, i); 
        }
    }

    unordered_map<int, int> pos; 
    
    vector<int> topsort; 
    
    int index=0;
    while(!(tops.empty())){
        pos[tops.front()] = index;
        topsort.push_back(tops.front()); 
        index++;
        tops.pop(); 
    }
    for(int i=0;i<numCourses;i++){
        for(int j:adj[i]){
            if(pos[i]<=pos[j]){
                return {}; 
            }
        }
    }
    return topsort;     
}
void backTrack(vector<vector<int>>& adj, vector<vector<int>> &ans, vector<int> con){
    vector<int> tr=con;  
    for(int n:adj[con[con.size()-1]]){
        tr.push_back(n);
        if(n==adj.size()-1){
            ans.push_back(tr);
        }else{
            backTrack(adj, ans, tr); 
        }
        tr.pop_back();
    }
}

vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
    backTrack(graph,ans,{0});
    return ans;
}
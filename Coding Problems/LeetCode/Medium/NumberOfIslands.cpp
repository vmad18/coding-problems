bool isSafe(vector<vector<char>> &grid, int x, int y){
    if(x<0 || y<0) return false;
    else if(x>=grid[0].size() || y>=grid.size()) return false;
    else if(grid[y][x]=='0') return false;
    return true; 
}

void dfs(vector<vector<char>> &grid, int x, int y){
    
    if(!isSafe(grid, x, y)) return; 
    
    grid[y][x] = '0'; 
    
    vector<int> ax={1,-1,0,0}; 
    vector<int> ay={0,0,1,-1}; 
    
    for(int i=0;i<ax.size();i++){
        if(isSafe(grid,x+ax[i],y+ay[i])) dfs(grid, x+ax[i], y+ay[i]); 
    }
    
}

//slower
//     void bfs(vector<vector<char>> &grid, int x, int y){
//         queue<pair<int, int>> q; 
//         q.push(make_pair(x,y)); 
    
//         vector<int> ax={1,-1,0,0}; 
//         vector<int> ay={0,0,1,-1}; 
    
//         while(!(q.empty())){
//             pair<int, int> n = q.front();
//             q.pop(); 
//             grid[n.second][n.first] = '0'; 
//             for(int i=0;i<ax.size();i++){
//                 if(isSafe(grid,n.first+ax[i],n.second+ay[i])){
//                     q.push(make_pair(n.first+ax[i],n.second+ay[i])); 
//                 }
//             }   
//         }
//     }

int numIslands(vector<vector<char>>& grid) {
    int c=0; 
    for(int y=0;y<grid.size();y++){
        for(int x=0;x<grid[y].size();x++){
            if(isSafe(grid, x, y)){
                dfs(grid,x,y);
                c++; 
            }
        }
    }
    return c; 
}
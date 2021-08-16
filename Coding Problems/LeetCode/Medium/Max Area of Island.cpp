bool isSafe(vector<vector<int>> &grid, int x, int y){
    if(y<0 || x<0) return false;
    if(x>=grid[0].size() || y>=grid.size()) return false;
    return grid[y][x];
}

void dfs(vector<vector<int>> &grid, int x, int y, int &v){
    if(!isSafe(grid, x, y)) return; 
    
    grid[y][x] = 0; 
    v++;
    vector<int> ax={1,-1,0,0}; 
    vector<int> ay={0,0,1,-1}; 
    
    for(int i=0;i<ax.size();i++){
        dfs(grid, x+ax[i], y+ay[i], v); 
    }
}

int maxAreaOfIsland(vector<vector<int>>& grid) {

    int ms=0; 
    for(int y=0;y<grid.size();y++){
        for(int x=0;x<grid[y].size();x++){
            if(isSafe(grid, x, y)){
                int c=0; 
                dfs(grid, x, y, c);
                if(c>ms) ms = c; 
            }
        }
    }
    return ms; 
}
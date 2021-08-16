bool isSafe(int x, int y, vector<vector<char>> &board){
    if(x<0 || y<0) return false;
    else if(x>=board[0].size() || y>=board.size()) return false;
    else if(board[y][x] == '.') return false;
    return true;
}


void dfs(vector<vector<char>> &board, int x, int y, int tx, int ty){
    if(!isSafe(x,y,board)) return;
    
    board[y][x] = '.';
    
    dfs(board, x+tx, y+ty, tx, ty);
}

int countBattleships(vector<vector<char>>& board) {
    int count=0;
    
    vector<int> ar = {1, 0};
    vector<int> ac = {0, 1};
    
    int m = board.size();
    int n = board[0].size();
    for(int y=0;y<m;y++){
        for(int x=0;x<n;x++){
            if(isSafe(x,y,board)){
                count++;
                for(int i=0;i<ar.size();i++){
                    int tx = x+ac[i];
                    int ty = y+ar[i]; 
                    if(isSafe(tx,ty,board)){
                        if(isSafe(x,y,board)){
                            dfs(board,x,y,ac[i],ar[i]);
                            break; 
                        }
                    }
                }
            }
        }
    }
    return count;
}
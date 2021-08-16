void setZeroes(vector<vector<int>>& matrix) {
    vector<vector<int>> drain = matrix;
    for(int i=0;i<matrix.size();i++){
        for(int x=0;x<matrix[i].size();x++){
            if(matrix[i][x]==0){
                drain[i]=vector<int>(matrix[0].size(),0);
                for(int j=0;j<matrix.size();j++){
                    drain[j][x] = 0;
                }
            }
        }
    }
    matrix=drain;
}
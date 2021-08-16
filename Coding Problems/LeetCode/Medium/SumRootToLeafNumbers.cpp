int toint(vector<int> v){
    
    int n=v.size();
    int num=0; 
    
    for(int i=0;i<n;i++){
        num+=(v[i]*pow(10,n-(i+1))); 
    }
    return num;
}

void dfs(vector<vector<int>> &nums, vector<int> vals, TreeNode* n){
    
    vals.push_back(n->val); 
    
    if(n->left == NULL && n->right==NULL){
        nums.push_back(vals); 
        return; 
    }
    
    if(n->left!=NULL){
        dfs(nums,vals,n->left);
    }
    
    if(n->right!=NULL){
        dfs(nums,vals,n->right); 
    }
    
}

int sumNumbers(TreeNode* root) {
    vector<vector<int>> nums; 
    dfs(nums, {}, root); 
    int fn=0; 
    for(vector<int> i:nums){
        fn+=toint(i); 
    }
    return fn; 
}
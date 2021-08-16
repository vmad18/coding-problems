void dfs(TreeNode *n, vector<int> &prev_leaves, int level, int &cm, int &sum){
    if(n->left == NULL && n->right == NULL){
        
        if(level==cm){
            prev_leaves.push_back(n->val); 
            sum+=n->val; 
        }else if(level<cm){
            return; 
        }else{
            for(int i:prev_leaves){
                sum-=i; 
            }
            sum+=n->val; 
            prev_leaves = {}; 
            prev_leaves.push_back(n->val);
            cm = level; 
        }
        return; 
    }
    
    
    level++;
    
    if(n->left != NULL){
        dfs(n->left, prev_leaves, level, cm, sum); 
    }
    if(n->right != NULL){
        dfs(n->right, prev_leaves, level, cm, sum); 
    }
}

int deepestLeavesSum(TreeNode* root) {
    int s=0; 
    int cm=0; 
    vector<int> arr; 
    dfs(root, arr, 0, cm, s); 
    return s; 
}
string astr(vector<TreeNode*> p){
    string s; 
    for(int i = p.size()-1; i>=0; i--){
        s+=((char)(p[i]->val+97)); 
    }
    return s;
}

void dfs(string &adj, vector<TreeNode*> arr, TreeNode *n){
    arr.push_back(n); 
    if(n->left == NULL && n->right==NULL){
        string t = astr(arr); 
        if(t<adj || adj==""){
            adj = t;
        }
        return;
    }
    
    if(n->left != NULL){
        dfs(adj, arr, n->left); 
    }
    
    if(n->right != NULL){
        dfs(adj, arr, n->right); 
    }
}

string smallestFromLeaf(TreeNode* root) {
    string path=""; 
    dfs(path, {}, root); 
    return path; 
}
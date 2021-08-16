int maxLevelSum(TreeNode* root) {
    queue<TreeNode*> q; 
    q.push(root);
    int layer=1;
    int mv = INT_MIN;
    int ml=0; 
    while(!q.empty()){
        int sum=0;  
        queue<TreeNode*> t; 
        while(!q.empty()){
            TreeNode *n=q.front();
            q.pop(); 
            sum+=n->val; 
            if(n->left != NULL) t.push(n->left);
            if(n->right != NULL) t.push(n->right); 
        }
        if(sum>mv){
            mv=sum;
            ml = layer; 
        }
        q=t; 
        layer++; 
    }
    return ml; 
}
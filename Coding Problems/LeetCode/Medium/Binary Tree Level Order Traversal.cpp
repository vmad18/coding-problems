vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> split;
    
    if(root==nullptr) return split; 
    
    vector<TreeNode*> hold;
    hold.push_back(root); 
    while(hold.size()!=0){
        vector<int> vals;
        vector<TreeNode*> temp; 
        for(TreeNode *i:hold){
            vals.push_back(i->val);
            if(i->left != nullptr) temp.push_back(i->left);
            if(i->right != nullptr) temp.push_back(i->right);
        }
        hold = temp;
        split.push_back(vals);
    }
    return split; 
}
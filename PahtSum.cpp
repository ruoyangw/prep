    bool hasPathSum(TreeNode *root, int sum) {
        bool find=false;
        searchPath(root,sum,0,find);
        return find;
    }
    void searchPath(TreeNode * root, int sum, int path,bool & find){
        if(!root ){
            return;
        }
        path+=root->val;
        if(path==sum && !root->right && !root->left){
            find=true;
            return;
        }
        if(!find)
        searchPath(root->right,sum,path,find);
        if(!find)
        searchPath(root->left,sum,path,find);
    }
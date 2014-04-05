    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        vector<vector<int> > res;
        if(root==NULL){
            return res;
        }
        vector<int> path;
        int pathsum=0;
        DFSps(root,sum,pathsum,path,res);
        return res;
    }
    
    void DFSps(TreeNode *root,int sum, int pathsum,vector<int> path,vector<vector<int> > &res){
        if(root==NULL){
            return;
        }
        pathsum+=root->val;
        path.push_back(root->val);
        if(pathsum==sum && !root->right && !root->left){
            res.push_back(path);
        }
        DFSps(root->right,sum,pathsum,path,res);
        DFSps(root->left,sum,pathsum,path,res);
        
    }
    
    
  
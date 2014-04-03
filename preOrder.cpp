    vector<int> preorderTraversal(TreeNode *root) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        vector<int> result;
        if(root==NULL){
            return result;
        }
        stack<TreeNode*> mystack;
        TreeNode* cur;
        mystack.push(root);
        while(!mystack.empty()){
            cur=mystack.top();
            result.push_back(cur->val);
            mystack.pop();
            if(cur->right){
                mystack.push(cur->right);
            }
            if(cur->left){
                mystack.push(cur->left);
            }
        }
            
        return result;
    }
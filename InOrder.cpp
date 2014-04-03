    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> result;
        if(root==NULL){
            return result;
        }
        stack<TreeNode*> mystack;
        TreeNode * cur;

        while(! (mystack.empty()&& root == NULL)){
            if(root!=NULL){
                mystack.push(root);
                root=root->left;
            }else{
                cur=mystack.top();
                mystack.pop();
                result.push_back(cur->val);
                root=cur->right;
            }
            
        }
        return result;
    }
    void connect(TreeLinkNode *root) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if(root==NULL)
        return;
        TreeLinkNode * nextLevel=NULL;
        while(root){
            if(root->left){
                root->left->next=root->right;
                if(!nextLevel)
                nextLevel=root->left;
            }
            if(root->next && root->right){
                root->right->next=root->next->left;
            }
            if(!root->next){
                root=nextLevel;
                nextLevel=NULL;
            }else{
            root=root->next;
            }
            
        }
    }
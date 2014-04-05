    void connect(TreeLinkNode *root) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
       if(root==NULL)
       return;
       TreeLinkNode * nextLevel=NULL;
       TreeLinkNode * last=NULL;
       
       while(root){
           if(root->left){
               if(last!=NULL)
               last->next=root->left;
               
               last=root->left;
               if(nextLevel==NULL)
               nextLevel=root->left;
               
           }
           if(root->right){
               if(last!=NULL)
               last->next=root->right;
               last=root->right;
               if(nextLevel==NULL)
               nextLevel=root->right;
           }
           if(root->next){
               root=root->next;
           }else{
               root=nextLevel;
               nextLevel=NULL;
               last=NULL;
           }
           
       }
 
    }
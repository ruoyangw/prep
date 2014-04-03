    struct nodeLife{
        TreeNode * node;
        int life;
        nodeLife(TreeNode * r, int x) : node(r),life(x){}
    };
    vector<int> postorderTraversal(TreeNode *root) {
          vector<int> result;
          if(root==NULL)
          return result;
          stack<nodeLife *> mystack;
          nodeLife * curr;
          mystack.push(new nodeLife(root,2));
          while(!mystack.empty()){
              curr=mystack.top();
              if(curr->life==2){
                  curr->life-=1;
                  if(curr->node->left){
                  mystack.push(new nodeLife(curr->node->left,2));
                  }
              }else if(curr->life==1){
                  curr->life-=1;
                  if(curr->node->right){
                  mystack.push(new nodeLife(curr->node->right,2));
                  }
              }else{
                  mystack.pop();
                  result.push_back(curr->node->val);
              }
          }
          
        return result;
    }

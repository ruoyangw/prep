    int max_num;
    int cur_size;
 struct ListNode {
      int key;
      int value;
      ListNode *next;
      ListNode(int x,int y) : key(x), next(NULL),value(y) {}
  };
    ListNode *head;
    ListNode *tail;
    LRUCache(int capacity) {
        max_num=capacity;
        cur_size=0;
        head=NULL;
        tail=NULL;
    }
    
    int get(int key) {
        if(head==NULL)
        return -1;
        ListNode * temp=head;
        if(head->key==key){
            int val=head->value;
             tail->next=new ListNode(key,head->value);
             tail=tail->next;
             head=head->next;
             delete temp;
             return val;
        }
          while(temp!=NULL){
              if(temp->next!=NULL && temp->next->key==key){
                  ListNode * n=temp->next;
                  if(n!=tail){
                  temp->next=n->next;
                  tail->next=new ListNode(n->key,n->value);
                  tail=tail->next;
                  }
                  return n->value;
              }
              temp=temp->next;
          }
          return -1;
    }
    
    void set(int key, int value) {
        if(head==NULL){
            head=new ListNode(key,value);
            tail=head;
            cur_size++;
        }else{
            if(updateValue(key,value)==-1){  //could not find
              if(cur_size<max_num){
                tail->next=new ListNode(key,value);
                tail=tail->next; 
                cur_size++;
              }else{
                 ListNode * temp=head;
                 tail->next=new ListNode(key,value);
                 tail=tail->next;
                 head=head->next;
                 delete temp;
              }
            }
    }
    }
    
    int updateValue(int key,int value){
         ListNode * temp=head;
         if(head->key==key){
             temp=head;
             tail->next=new ListNode(key,value);
             tail=tail->next;
             head=head->next;

             delete temp;
             return 1;
         }
          while(temp!=NULL){
              if(temp->next!=NULL && temp->next->key==key){
                  if(temp->next!=tail){
                  temp->next=temp->next->next;
                  tail->next=new ListNode(key,value);
                  tail=tail->next;
                  }else{
                      tail->value=value;
                  }
                  return 1;
              }
              temp=temp->next;
         }
          return -1;
    }
    
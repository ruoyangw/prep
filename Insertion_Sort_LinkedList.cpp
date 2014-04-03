    ListNode *insertionSortList(ListNode *head) {
        if(head==NULL || head->next ==NULL)
        return head;
        ListNode * cur=head;
        ListNode * temp;
        ListNode * prev=NULL;
        ListNode * thead;
        while(cur!=NULL){
          temp=cur;

          if(temp==head){
             head=head->next;
             prev=NULL;
          }else{
             if(prev==NULL)
             prev=head;                //*********//
          }
          cur=cur->next;
          
          if(prev!=NULL)
          prev->next=cur;
          
          thead=head;
          if(temp->val<=thead->val){
              temp->next=thead;
              head=temp;
          }else{
             while(thead!=NULL){
                  if(thead->next==NULL){
                      thead->next=temp;
                      temp->next=NULL;
                      
                      break;
                  }else if(thead->next->val>temp->val){
                      temp->next=thead->next;
                      thead->next=temp;
                      if(temp->next==cur)
                      prev=temp;                        //**********//
                      break;
                  }
                  thead=thead->next;
            }
            }
        }
        return head;
    }
    
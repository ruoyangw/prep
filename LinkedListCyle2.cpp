    ListNode *detectCycle(ListNode *head) {
        if(head==NULL)
        return NULL;
        ListNode * slow=head;
        ListNode * fast=head;
        while(fast!=NULL){
            fast=fast->next;
            if(fast!=NULL){
                fast=fast->next;
                slow=slow->next;
            }
            if(fast==slow){         //detects 
                fast=head;
                while(fast!=slow){
                    fast=fast->next;
                    slow=slow->next;
                }
                return fast;
            }
        }
     return NULL;   
    }
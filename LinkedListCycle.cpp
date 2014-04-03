    bool hasCycle(ListNode *head) {
        if(head==NULL)
        return false;
        ListNode * slow=head;
        ListNode * fast=head;
        while(fast!=NULL){
            fast=fast->next;
            if(fast!=NULL){
            fast=fast->next;
            slow=slow->next;
            }
            if(fast==slow)
            return true;
        }
        return false;
    }
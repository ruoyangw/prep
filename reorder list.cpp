    void reorderList(ListNode *head) {
        if(head==NULL)
        return;
        ListNode * slow=head;
        ListNode * fast=head;
        while(fast!=NULL){
            fast=fast->next;
            if(fast!=NULL){
                fast=fast->next;
                if(fast!=NULL)
                slow=slow->next;
            }
        }
        ListNode * second=slow->next;
        slow->next=NULL;
        second=reverseList(second);
        ListNode * first=head;
        ListNode * temp;
        ListNode * temp2;
        bool connectDown=true;
        while(!(second==NULL)){
                temp=first->next;
                first->next=second;
                temp2=second->next;
                second->next=temp;
                second=temp2;
                first=temp;
        }
    }
    
    ListNode * reverseList(ListNode * head){
        if(head==NULL)
        return NULL;
        
        ListNode * pre=NULL;
        ListNode * cur=head;;
        ListNode * nex=head->next;
        while(cur!=NULL){
            cur->next=pre;
            pre=cur;
            cur=nex;
            if(nex!=NULL)
            nex=nex->next;
            
        }
        return pre;
    }
    
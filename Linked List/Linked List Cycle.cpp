class Solution {
public:
    bool hasCycle(ListNode *head) {
        
        if(!head) return false;
        
        ListNode * slow = head;
        ListNode * fast = head->next;
        
        while(fast != NULL && fast->next != NULL && slow != NULL){
            
            if(fast == slow){
                return true;
            }
            
            slow = slow->next;
            fast = fast->next->next;
            
        }
          
        return false;
        
    }
};

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        if(head == NULL || k == 1) return head;
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        
        ListNode* curr = dummy;
        ListNode* pre = dummy;
        ListNode* next = dummy;
        int len = 0;
        
        while(curr->next != NULL){
            curr = curr->next;
            len++;
        }
        
        while(len >= k){            
            curr= pre->next;
            next = curr->next;
            for(int i = 1 ; i < k ; i++){
                curr->next = next->next;
                next->next = pre->next;
                pre->next = next;
                next= curr->next;
            }
            pre = curr;
            len -= k;
        }
        return dummy->next;

    }
};

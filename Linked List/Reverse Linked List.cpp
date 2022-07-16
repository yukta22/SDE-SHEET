class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* dummy = NULL;
        
        while(head != NULL){
            ListNode* temp = head->next;
            head->next = dummy;
            dummy = head;
            head = temp;
            
        }
        return dummy;
    }
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head) return NULL;
        
        ListNode* temp = head;
        int len = 0;
        
        while(temp != NULL){
            len++;
            temp= temp->next;
        }
        
        if(n > len) return head;
        
        else if(n == len) return head->next;
        
        else{
            
            int diff = len-n;
            
            ListNode* prev = NULL;
            ListNode* curr = head;
            
            for(int i = 0 ; i <diff ; i++){
                prev=curr;
                curr = curr->next;
            }
            prev->next = curr->next;
            return head;
        }    
    }
};

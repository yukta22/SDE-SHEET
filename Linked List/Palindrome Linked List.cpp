class Solution {
public:
    bool isPalindrome(ListNode* head) {        
        ListNode* temp = head;
        stack<int> s;
        
        while(temp != NULL){
            s.push(temp->val);
            temp = temp->next;
        }
        temp = head;
        while(temp != NULL){
            int t = s.top();
            s.pop();
            
            if(temp->val != t)  return false;
            
            temp = temp->next;
            
        }
        return true;
    }
};


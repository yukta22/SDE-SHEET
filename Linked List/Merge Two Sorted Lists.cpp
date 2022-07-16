class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* temp = l1;
        
        if(l1 == NULL)   return l2;
        
        if(l2 == NULL)   return l1;
        
        if(l1->val <= l2->val){
            temp = l1;
            temp->next = mergeTwoLists(l1->next, l2);
        }
        else{
            temp = l2;
            temp->next = mergeTwoLists(l2->next, l1);
        }
        
        return temp;
    }
};

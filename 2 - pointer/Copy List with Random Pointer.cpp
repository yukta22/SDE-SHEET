//https://leetcode.com/problems/copy-list-with-random-pointer/

// T.C. == O(N) 
//S.C. == O(N)
class Solution {
public:
    unordered_map<Node*,Node*>m;   
    Node* copyRandomList(Node* head) {
        if(!head) return NULL;
        
        if(m[head]) return m[head];
        m[head] = new Node(head->val);
        m[head]->next = copyRandomList(head->next);
        m[head]->random = copyRandomList(head->random);
        return m[head];
        
    }
};


//T.C. == O(N) 
//S.C. == O(1)
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return head;
        
        Node* temp = head;
        
        //create a copy node 
        while(temp){
            Node* newNode = new Node(temp->val);
            newNode->next = temp->next;
            temp->next = newNode;
            temp = newNode->next;
        }
        
        //assigning random pointers
        temp = head;
        while(temp){
            if(temp->random){
                temp->next->random = temp->random->next;
            }
            temp = temp->next->next;
        }
        
        //restore the original linked list
        Node* newHead = head->next;
        Node* temp2 = head->next;
        temp = head;
        
        while(temp && temp2){
            Node* currN = temp2->next;
            temp->next = currN;
            if(currN){
                temp2->next = currN->next;
            }
            temp = temp->next;
            temp2 = temp2->next;
        }
        
        return newHead;
    }
};


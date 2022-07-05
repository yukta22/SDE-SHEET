//https://leetcode.com/problems/populating-next-right-pointers-in-each-node/

class Solution {
public:
    Node* connect(Node* root) {
        if(!root) return root;
        queue<Node*> q;
        q.push(root);
        
        while(!q.empty()){
            int n = q.size();
                        
            for(int i=0 ; i<n; i++){
                Node* f = q.front();
                q.pop();
                
                if(i != n-1) f->next = q.front();
                
                if(f->left) q.push(f->left);
                if(f->right) q.push(f->right);
                
            }
            
        }
        
        return root;
    }
};


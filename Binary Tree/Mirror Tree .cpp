//https://practice.geeksforgeeks.org/problems/mirror-tree/1#

class Solution {
  public:
    void mirror(Node* node) {
        // code here
        if (node == NULL) 
            return; 
        else
        {
            Node* temp;
            
            /* do the subtrees */
            mirror(node->left);
            mirror(node->right);
        
            /* swap the pointers in this node */
            temp = node->left;
            node->left = node->right;
            node->right = temp;
        }
    }
    
    void inOrder(Node* node) 
    {
        if (node == NULL) 
            return;
        
        inOrder(node->left);
        cout << node->data << " ";
        inOrder(node->right);
    }
    
};

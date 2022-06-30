//https://leetcode.com/problems/binary-tree-preorder-traversal/

/////////////////////////////////////////////////Iterative//////////////////////////////////////////////////////////////////////////////////////////////////


class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        
        if(root == NULL) return ans;
        
        stack<TreeNode*> st;
        st.push(root);
        
        while(!st.empty()){
            
            TreeNode* curr = st.top();
            st.pop();
            
            ans.push_back(curr->val);
            if(curr->right) st.push(curr->right);
            if(curr->left) st.push(curr->left);
            
        }
        
        return ans;
    }
};


/////////////////////////////////////////////////Recursive/////////////////////////////////////////////////

class Solution {
public:
    
    void preorder(TreeNode* root , vector<int>& nodes){
         if (!root) {
            return;
        }
         nodes.push_back(root -> val);
        preorder(root -> left, nodes);
        preorder(root -> right, nodes);
    }
    
    
    
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> nodes;
        preorder(root,nodes);
        return nodes;
    }
};


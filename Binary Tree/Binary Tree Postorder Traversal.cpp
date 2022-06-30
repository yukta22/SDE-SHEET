//https://leetcode.com/problems/binary-tree-postorder-traversal/

/////////////////////////////////////////////////Iterative//////////////////////////////////////////////////////////////////////////////////////////////////


class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        
        if(root == NULL) return ans;
        
        stack<TreeNode*> st;
        TreeNode* last = NULL;
        while (root || !st.empty()) {
            if (root) {
                st.push(root);
                root = root -> left;
            } 
            else {
                TreeNode* node = st.top();
                if (node -> right && last != node -> right) {
                    root = node -> right;
                } else {
                    ans.push_back(node -> val);
                    last = node;
                    st.pop();
                }
            }
        }
        return ans;
    }
};

/////////////////////////////////////////////////Recursive/////////////////////////////////////////////////

class Solution {
public:
    
    void postorder(TreeNode* root , vector<int> &nodes){
        
        if(!root) return;
        
        postorder(root -> left, nodes);
        postorder(root -> right, nodes);
        nodes.push_back(root -> val);
        
    }
    
    
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> nodes;
        postorder(root, nodes);
        return nodes;
    }
};

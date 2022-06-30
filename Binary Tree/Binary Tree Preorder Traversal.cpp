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
    
    void solve(TreeNode* root, vector<int> &ans){
        if(root){
            
            if(root->left){
                solve(root->left, ans);
            }
            ans.push_back(root -> val);
            if(root->right){
                solve(root->right, ans);
            }
        }
        return;
    }
    
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        solve(root,ans);
        return ans;
    }
};

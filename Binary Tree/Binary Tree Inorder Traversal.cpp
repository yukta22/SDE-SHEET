//https://leetcode.com/problems/binary-tree-inorder-traversal/

/////////////////////////////////////////////////Iterative//////////////////////////////////////////////////////////////////////////////////////////////////


//Time Complexity: O(N).
//Space Complexity: O(N)

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> inOrder;
        stack<TreeNode*> s;
        
        TreeNode* curr = root;
        
        while(true){
            if(curr != NULL){
                s.push(curr);
                curr = curr->left;
            }
            else{
                if(s.empty()) break;
                curr = s.top();
                inOrder.push_back(curr->val);
                s.pop();
                curr = curr->right;                
                
            }
        }
        return inOrder;
        
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



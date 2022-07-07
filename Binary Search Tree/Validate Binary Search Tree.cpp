//https://leetcode.com/problems/validate-binary-search-tree/

class Solution {
public:
    vector<int> ans;
    void inorder(TreeNode* root){
        if(!root) return ;
        
        inorder(root->left);
        ans.push_back(root->val);
        inorder(root->right);
        
    }
    
    bool isValidBST(TreeNode* root) {
        if(!root)  return true;
        inorder(root);
        
        for(int i = 1 ;i < ans.size() ; i++){
            
            if(ans[i-1] >= ans[i]){
                return false;
            }
            
        }
        return true;
    }
};


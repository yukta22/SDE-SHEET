//https://leetcode.com/problems/maximum-depth-of-binary-tree/

class Solution {
public:    
    
    int maxDepth(TreeNode* root) {
        
        if(!root) return NULL;
        
        int ld = maxDepth(root->left);
        int rd = maxDepth(root->right);
        
        int maxi = max(ld,rd);
        
        return maxi+1;
        
    }
};

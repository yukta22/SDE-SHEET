//https://leetcode.com/problems/symmetric-tree/

class Solution {
public:
    
    bool helper(TreeNode* r1 , TreeNode* r2){
        
        if(r1 == NULL && r2 == NULL) return true;
        
        if(r1 == NULL || r2 == NULL) return false;
        
        return (r1 -> val == r2->val) && helper( r1-> right , r2 ->left)
                                      && helper(r1 -> left , r2->right);     
        
        
    }
    
    bool isSymmetric(TreeNode* root) {
        return helper(root,root);
    }
};

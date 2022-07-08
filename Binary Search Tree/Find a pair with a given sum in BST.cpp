//https://leetcode.com/problems/two-sum-iv-input-is-a-bst/

class Solution {
public:
    vector<int> nums;
    void inorder(TreeNode* root){
        if(root == NULL) return;
        inorder(root->left);
        nums.push_back(root->val);
        inorder(root->right);
    }
    
    bool findTarget(TreeNode* root, int k) {
        if(!root)
            return false;
        inorder(root);
        
        int i = 0, j = nums.size()-1;
        while(i < j)
        {
            if(nums[i] + nums[j] == k){
                return true;
            }
            else if(nums[i] + nums[j] < k){
                i++;
            }
            else{
                j--;
            }
        }
        return false;
    }
};

//https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/

class Solution {
public:
    
    TreeNode* helper(vector<int>& nums, int start ,int end){
        
        if(end <= start) return NULL;
        
        int mid = (start+end) /2;
        
        TreeNode* root = new TreeNode(nums[mid]);
        
        root->left = helper(nums,start,mid);
        root->right = helper(nums,mid+1,end);
        
        return root;
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return helper(nums,0,nums.size());
    }
};

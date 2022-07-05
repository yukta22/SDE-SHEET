//https://leetcode.com/problems/search-in-a-binary-search-tree/

class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
            while (root != nullptr && root->val != val) {
              root = (root->val > val) ? root->left : root->right;
            }
            return root;

    }
};

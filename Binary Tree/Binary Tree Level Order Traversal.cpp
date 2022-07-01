//https://leetcode.com/problems/binary-tree-level-order-traversal/

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        vector<int> v;
        
        queue<TreeNode*> q;
        q.push(root);
        
        if(root == NULL) return ans;
        
        while(!q.empty()){
            int n = q.size();
            
            for(int i = 0 ; i < n ; i++){
                TreeNode* f = q.front();
                q.pop();
                
                v.push_back(f->val);
                
                if(f->left) q.push(f->left);
                if(f->right) q.push(f->right);
                
            }
            ans.push_back(v);
            v.clear();
        }
        return ans;
    }
};

//https://leetcode.com/problems/maximum-width-of-binary-tree/

class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        
        int ans = 0;
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});
        
        while(!q.empty()){
            int n = q.size();
            int mini = q.front().second;
            int first , last;
            
            for(int i = 0 ; i < n ; i++){
                int curr_id = q.front().second - mini;
                TreeNode* node = q.front().first;
                q.pop();
                if(i == 0)    first = curr_id;
                if(i == n - 1)  last = curr_id;
                
                if(node->left){
                    q.push({node->left, curr_id*2+1});
                }
                
                if(node->right){
                    q.push({node->right, curr_id*2+2});
                }
                
            }
            ans = max(ans, last - first + 1);
        }
        return ans;
    }
};

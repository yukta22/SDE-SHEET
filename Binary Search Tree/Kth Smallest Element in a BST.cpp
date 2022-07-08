//https://leetcode.com/problems/kth-smallest-element-in-a-bst/

///////////////////////////////////////////////////////////////

class Solution {
public:
    void inorder(TreeNode* root, int k,vector<int> &v) {
        
        if(!root) return;
        inorder(root->left,k,v);
        v.push_back(root->val);
        inorder(root->right,k,v);     
        
    }
    
    int kthSmallest(TreeNode* root, int k){
        if(!root) return 0;
        vector<int> v;
        inorder(root,k,v);
        
        sort(v.begin() , v.end());
        return v[k-1];       
               
    }
};

//////////////////////////////////////////////////////////

class Solution {
public:
    int ans;
    void solve(TreeNode *root, int k, int &count){
        if(!root) return;
        
        solve(root->left, k , count);
        if(k == count){
            ans = root->val;
            count++;
        }
        else count++;
        solve(root->right, k , count);
    }
    
    int kthSmallest(TreeNode* root, int k){
        int count = 1;
        ans = -1;
        solve(root, k, count);
        
        return ans;
               
    }
};

//https://practice.geeksforgeeks.org/problems/left-view-of-binary-tree/1

// Time Complexity: O(N)
// Space Complexity: O(H)       (H -> Height of the Tree)

////////////////////////////////////////////Right view of binary tree////////////////////////////////////////////

class Solution {
public:
    void recursion(TreeNode *root, int level, vector<int> &res)
    {
        if(root==NULL) return ;
        if(res.size()==level) res.push_back(root->val);
        recursion(root->right, level+1, res);
        recursion(root->left, level+1, res);
    }
    
    vector<int> rightSideView(TreeNode *root) {
        vector<int> res;
        recursion(root, 0, res);
        return res;
    }
};


////////////////////////////////////////////Left view of binary tree////////////////////////////////////////////


void leftviewHelper(Node *root , int level, vector<int>& v){
    if(root == NULL) return;
    
    if(v.size()==level){
        v.push_back(root->data);
    
    }
    
    leftviewHelper(root->left , level+1  , v);
    leftviewHelper(root->right , level+1 , v);
    
}

//Function to return a list containing elements of left view of the binary tree.
vector<int> leftView(Node *root)
{
    vector<int> v;
    leftviewHelper(root,0,v);
    return v;

}



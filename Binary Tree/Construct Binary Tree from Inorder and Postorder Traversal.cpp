class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.size() != postorder.size())  return NULL;
        
        map<int,int> mpp;
        for(int i = 0 ; i < inorder.size() ; i++){
            mpp[inorder[i]] = i;
        }
        return buildTreePostIn(inorder, 0, inorder.size()-1, postorder, 0, postorder.size()-1,mpp);
    }
    
    TreeNode* buildTreePostIn(vector<int>& inorder,int is, int ie, vector<int>& postorder,int ps, int pe,map<int,int> &mpp)
    {
        if (ps>pe || is>ie) return NULL;
        TreeNode* root = new TreeNode(postorder[pe]);
        
        int inRoot = mpp[postorder[pe]];
        int numsLeft = inRoot - is;
        
        TreeNode* leftchild = buildTreePostIn(inorder, is, inRoot - 1, postorder, ps,  ps+numsLeft-1,mpp);  
        
        TreeNode* rightchild = buildTreePostIn(inorder,inRoot+1, ie, postorder, ps+numsLeft, pe-1, mpp);

        
        root->left = leftchild;
        root->right = rightchild;


        return root;
    }
    
};


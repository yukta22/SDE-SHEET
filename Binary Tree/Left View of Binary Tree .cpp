//https://practice.geeksforgeeks.org/problems/left-view-of-binary-tree/1

// Time Complexity: O(N)
// Space Complexity: O(H)       (H -> Height of the Tree)



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



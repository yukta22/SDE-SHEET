//https://practice.geeksforgeeks.org/problems/kth-largest-element-in-bst/1#

////////////////////////////////////////////////////////////////////////////

class Solution
{
    public:
    
    void inorder(Node *root, int k, vector<int> &v){
        if(!root) return;
        
        inorder(root->left, k , v);
        v.push_back(root->data);
        inorder(root->right, k, v);
        
    }
    
    int kthLargest(Node *root, int k)
    {
        if(!root) return 0;
        vector<int> v;
        inorder(root,k,v);
        
        sort(v.begin() , v.end());
        
        return v[v.size()-k];
    }
};

//////////////////////////////////////////////////////////////////////////////////

class Solution
{
    public:
    int ans;
    void solve(Node *root, int k, int &count){
        if(!root) return;
        
        solve(root->right, k , count);
        if(k == count){
            ans = root->data;
            count++;
        }
        else count++;
        solve(root->left, k , count);
    }
    
    int kthLargest(Node *root, int K)
    {
        int count = 1;
        ans = -1;
        solve(root, K, count);
        
        return ans;
    }
};


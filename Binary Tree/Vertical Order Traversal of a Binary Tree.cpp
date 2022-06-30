//https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/

class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, multiset<int>>> nodes;
        queue<pair<TreeNode*, pair<int, int>>> q;
        q.push({root, {0, 0}});
        while (!q.empty()) {
            auto f = q.front();
            q.pop();
            TreeNode* node = f.first;
            int x = f.second.first, y = f.second.second;
            nodes[x][y].insert(node -> val);
            if (node -> left) {
                q.push({node -> left, {x - 1, y + 1}});
            }
            if (node -> right) {
                q.push({node -> right, {x + 1, y + 1}});
            }
        }
        
        vector<vector<int>> ans;
        for (auto p : nodes) {
            vector<int> col;
            for (auto q : p.second) {
                col.insert(col.end(), q.second.begin(), q.second.end());
            }
            ans.push_back(col);
        }
        return ans;
    }
};



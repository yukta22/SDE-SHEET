//https://leetcode.com/problems/combination-sum/submissions/
class Solution {
    
    void findCombination(int idx,int target,vector<int>& arr,vector<int>& v,vector<vector<int>>& ans){
        if(idx == arr.size()){
            if(target == 0) {
                ans.push_back(v);
            }
            return;
        }
        
        //pick up the element
        if(arr[idx] <= target){
            v.push_back(arr[idx]);
            findCombination(idx,target - arr[idx],arr,v,ans);
            v.pop_back();
        }
        // not going to pick the element
        findCombination(idx+1,target,arr,v,ans);
        
    }
    
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> v;
        findCombination(0,target,candidates,v,ans);
        return ans;
    }
};

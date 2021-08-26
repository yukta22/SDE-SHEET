//https://leetcode.com/problems/combination-sum-ii/
class Solution {
    
    void findCombination(int idx,int target,vector<int>& arr,vector<int>& v,vector<vector<int>>& ans){
        
        if(target == 0) {
            ans.push_back(v);
            return;
        }
        
        for(int i = idx ; i < arr.size() ; i++){
            if(i>idx && arr[i]==arr[i-1]) continue; 
            if(arr[i]>target) break; 
            v.push_back(arr[i]);
            findCombination(i+1, target - arr[i], arr,v, ans); 
            v.pop_back(); 
        }
        
    }

    
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> v;
        findCombination(0,target,candidates,v,ans);
        return ans;
    }
};

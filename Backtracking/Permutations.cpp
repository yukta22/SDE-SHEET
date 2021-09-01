//https://leetcode.com/problems/permutations/

////////////////////////////////////////////////////////////// Approach - 1 //////////////////////////////////////////////////////////////
//T.C. : n! * n
//S.C. : o(n) + o(n)

class Solution {
public:
    void recurPermute(vector<int>& ds,vector<int>& nums,vector<vector<int>>& ans,int freq[]){
        if(ds.size() == nums.size()) {
            ans.push_back(ds);
            return;
        }
        for(int i =0 ; i < nums.size() ; i++) {
            if(!freq[i]){
                ds.push_back(nums[i]);
                freq[i]=1;
                recurPermute(ds,nums,ans,freq);
                freq[i]=0;
                ds.pop_back();
            }
        }
        
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        int freq[nums.size()];
        for(int i =0 ; i < nums.size() ; i++) freq[i] = 0;
        recurPermute(ds,nums,ans,freq);
        return ans;
    }
};

////////////////////////////////////////////////////////////// Approach - 2 //////////////////////////////////////////////////////////////
//T.C. : n! * n
//S.C. : o(1)

class Solution {
public:
    void recurPermute(int idx ,vector<int>& nums,vector<vector<int>>& ans ){
        if(idx == nums.size()) {
            ans.push_back(nums);
            return;
        }
        for(int i = idx; i < nums.size() ; i++) {
            
            swap(nums[idx] , nums[i]);
            recurPermute(idx+1,nums,ans);
            swap(nums[i],nums[idx]);   
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;        
        recurPermute(0,nums,ans);
        return ans;
    }
};


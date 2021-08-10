//https://leetcode.com/problems/next-permutation/
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int idx = -1;
        int l;
        
        for(int i = n - 2 ; i >= 0 ; i--){
            if(nums[i] < nums[i+1]){
                idx = i;
                break;
            }
        }
        if(idx < 0)  reverse(nums.begin() , nums.end());
        
        else{
            for(l = n -1 ; l > idx ; l--){
                if(nums[l] > nums[idx])  break;
            }
            
            swap(nums[idx] , nums[l]);
            reverse(nums.begin() + idx + 1 , nums.end());
        }
        
    }
};

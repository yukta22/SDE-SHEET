//https://leetcode.com/problems/next-greater-element-ii/

///////////////////////////////////////////////////// Brute-Force /////////////////////////////////////////////////////
// T.C. : O(N^2) 
// S.C. : O(N)

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> ans(n, -1);
       
        for(int i = 0 ; i < nums.size() ; i++){
            int j=i+1;
            if(j==nums.size())
                    j=0;
            while(j!=i){
                if(nums[j]>nums[i]){
                    ans.push_back(nums[j]);
                    break;
                }
                j++;
                if(j==nums.size())
                    j=0;
            }
        
        }
            
         return ans;   
    }
};

///////////////////////////////////////////////////// Brute-Force /////////////////////////////////////////////////////
// T.C. : O(N^2) 
// S.C. : O(N)

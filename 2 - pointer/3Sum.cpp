//https://leetcode.com/problems/3sum/

/////////////////////////////////////////////Brute solution/////////////////////////////////////////////
//T.C. : O(n^3 logm)
//S.C. : O(m)

// using 3 for loop geting sum 0 add it into the set ans then return


/////////////////////////////////////////////Better solution/////////////////////////////////////////////
//T.C. : O(n^2 logm)
//S.C. : O(m) + O(n)

// using 2 for loop with using calculate in hashmap and put ans in set and then return set


/////////////////////////////////////////////Optimal solution/////////////////////////////////////////////
//T.C. : O(n^2)
//S.C. : O(m) 

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        vector<vector<int>> ans;
        
        sort(nums.begin() , nums.end());
        
        for(int i = 0 ; i < (int)(nums.size())-2 ; i++){
            
            if(i == 0 || (i > 0 && nums[i] != nums[i-1])){
                
                int low = i + 1, high = nums.size() - 1 ;
                int sum = 0 - nums[i];
                
                while(low < high){
                    if(nums[low] + nums[high] == sum){
                        
                        vector<int> temp;
                        temp.push_back(nums[i]);
                        temp.push_back(nums[low]);
                        temp.push_back(nums[high]);
                        ans.push_back(temp);
                        
                        while(low < high && nums[low] == nums[low+1])  low++;
                        
                        while(low < high && nums[low] == nums[high-1])  high--;
                        
                        low++; 
                        high--;
                        
                    }
                    else if(nums[low] + nums[high] < sum)  
                        low++;
                    else
                        high--;
               
                } 
            }
        }
        return ans;        
    }
};


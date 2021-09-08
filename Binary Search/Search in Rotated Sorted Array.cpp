//https://leetcode.com/problems/search-in-rotated-sorted-array/

//T.C. : O(logn)
//S.C. : O(1)

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0 , high = nums.size()-1;
        
        while(low<=high){
            int mid = (low+high) >> 1;
            
            if(nums[mid] == target)   return mid;
            
            //the left side is sorted
            if(nums[low] <= nums[mid]){
                //figure out if element is lies on left half or not     
                if(target >= nums[low] && target<= nums[mid]){
                    high = mid - 1;
                }
                else{
                    low = mid + 1;
                }
            
            }
            //the right side is sorted
            else{
                if(target >= nums[mid] && target<= nums[high]){
                    low = mid +1;
                }
                else{
                    high = mid - 1;
                } 
            }
            
        }
        return -1;
        
    }
};

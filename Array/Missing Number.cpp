// T.C.: O(N) 
// S.C : O(1)
///////////////////Gauss' Formula//////////////////////
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int x = n * (n+1)/2;
        int y = 0;
        
        for(int i : nums) y += i;
        
        return x-y;
        
    }
};
// T.C.: O(N) 
// S.C : O(1)
//////////////////////////XOR operation//////////////////////
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int x1 = 0, x2 = 0;
        
        for(int i = 0 ; i < n ; i++){
            x1 = x1^nums[i];
            x2 = x2 ^ (i+1);
        }
        
        return x1^x2;
    }
};

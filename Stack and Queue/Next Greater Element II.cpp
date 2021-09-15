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

///////////////////////////////////////////////////// using stack /////////////////////////////////////////////////////
// T.C. : O(2N + 2N) 
// S.C. : O(N)

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> nge(n, -1);
        stack<int> st;
        
        for(int i = 2*n-1;i>=0;i--){
            while(!st.empty() && st.top() <= nums[i%n]) {
                st.pop(); 
            }
            
            if(i<n) {
                if(!st.empty()) nge[i] = st.top(); 
            }
            st.push(nums[i%n]);
        }
        
        return nge; 
        
    }
};



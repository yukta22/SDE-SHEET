class Solution {
public:
    int distinctSubseqII(string s) {
        int n=s.length();
        int mod=1e9+7;
        
        vector<long >dp(n+1,0);
       
        dp[0]=1; // Empty is also a subsequence
        unordered_map<char,int>mp;
        
         for(int i=1;i<dp.size();i++){
             
             char ch=s[i-1]; // bcz indexing in dp is 1 ahead of s
              
              dp[i]=(2*dp[i-1]) % mod; // total subsequences possible till a char
             
             if(mp.find(ch)!=mp.end()){
                 
                 int j=mp[ch]; // index of the repeated character
                 
                 dp[i]=(dp[i]-dp[j-1])%mod; // subtracting the value with 1 index before j  
                  // dp[i]=dp[i]%mod;
             }
             
             // No need of else already done above
             mp[ch]=i; // index of dp array not of the sting s
                 
         }
          // these are the important edge cases
         if(dp[n]<0) dp[n]+=mod;
        
        return dp[n]-1;
       // return dp[n]-1;  // bcz not including the empty susequence
    }
};


//https://leetcode.com/problems/reverse-words-in-a-string/

////////////////////////////////////////////////////////////////////////////////////////
//Time Complexity: O(N)
//Space Complexity: O(N)

class Solution {
public:
    string reverseWords(string s) {
        
        int n = s.size();
        
        stack<string> st;
        string ans ;
        
        for(int i = 0 ; i < n ; i++){
            
            string word;
            if(s[i] == ' ') continue;
            
            while(i < n && s[i] != ' '){
                word += s[i];
                i++;
            }
            st.push(word);
            
        }
        
        while(!st.empty()){
            ans += st.top();
            st.pop();
            if(!st.empty())   ans += " ";
        }
         return ans;
    }
};








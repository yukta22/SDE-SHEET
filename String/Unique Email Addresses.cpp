//https://leetcode.com/problems/unique-email-addresses/


class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        set<string> st;
        for(string email : emails){
            
            string temp = "";
            int i ;
            for(i=0; email[i] != '@'; i++){
                if(email[i] == '.')
                    continue;
                
                else if(email[i] == '+')
                    break;
                
                else
                    temp += email[i];
               
            }
            
            i = email.find('@');
            temp += email.substr(i , email.length() - 1);
            st.insert(temp);
        }
        
        return st.size();
    }
};

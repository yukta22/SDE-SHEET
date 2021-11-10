//https://www.interviewbit.com/problems/nearest-smaller-element/

vector<int> Solution::prevSmaller(vector<int> &A) {
    int n = A.size();
    vector<int> ans;
    stack<int> s;
    
    for(int i=0;i<A.size();i++){
        while(!s.empty() && A[s.top()]>=A[i]){
            s.pop();
        }
        if(s.empty()){
            ans.push_back(-1);
            s.push(i);
        }
            
        else if(!s.empty()&&A[s.top()]<A[i]){
            ans.push_back(A[s.top()]);
            s.push(i);
        }

    }
    return ans;
}




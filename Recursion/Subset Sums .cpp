//https://practice.geeksforgeeks.org/problems/subset-sums2234/1#

//T.C = O(2^N)+2^Nlog(2^N)
//S.C = O(2^N) 

class Solution
{
void solve(int ind, int sum,vector<int> &arr, int N, vector<int> &sumSubset) {
    if(ind == N) {
        sumSubset.push_back(sum); 
        return; 
    }
    
    // pick the element 
    solve(ind + 1, sum + arr[ind], arr, N, sumSubset); 
    
    // Do-not pick the element
    solve(ind + 1, sum, arr, N, sumSubset);
}
public:
    vector<int> subsetSums(vector<int> arr, int N)
    {
        vector<int> sumSubset; 
        solve(0, 0, arr, N, sumSubset);
        sort(sumSubset.begin(), sumSubset.end());
        return sumSubset;
    }

};

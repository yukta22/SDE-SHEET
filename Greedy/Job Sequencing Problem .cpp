//https://practice.geeksforgeeks.org/problems/job-sequencing-problem-1587115620/1#

struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};

bool compare (Job a , Job b){
    return (a.profit > b.profit);
}

class Solution 
{
    public:
    
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        vector<int> ans;
        sort(arr,arr+n,compare);
        int maxi = arr[0].dead;
        
        for(int i = 1 ; i < n ; i++){
            maxi = max(maxi , arr[i].dead);
        }
        
        int slot[maxi+1];
        for(int i = 0 ; i <= maxi ; i++){
            slot[i] = -1;
        }
        
        int countJobs = 0 , jobProfit = 0;
        
        for(int i = 0 ; i < n ; i++){
            for(int j = arr[i].dead ; j > 0 ; j--){
                if(slot[j] == -1){
                    slot[j] = i;
                    countJobs++;
                    jobProfit += arr[i].profit;
                    break;
                }
            }
        }
        
        ans.push_back(countJobs);
        ans.push_back(jobProfit);
        return ans;
        
    } 
};

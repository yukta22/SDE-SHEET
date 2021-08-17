//https://practice.geeksforgeeks.org/problems/fractional-knapsack-1587115620/1#
//T.C. : O(NlogN) + N
//S.C. : O(1)

bool compare(Item a , Item b){
    double r1 = (double)a.value / (double)a.weight;
    double r2 = (double)b.value / (double)b.weight;
    return r1 > r2;
}

class Solution
{
    public:
  
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        sort(arr , arr+n , compare); 
        int curWeight = 0;
        double finalVal = 0.0;
        
        for(int i = 0 ; i < n ; i++){
            if(curWeight + arr[i].weight <= W){
                curWeight += arr[i].weight;
                finalVal += arr[i].value;
            }
            else{
                int remain = W - curWeight;
                finalVal += (arr[i].value / (double)arr[i].weight ) * remain;
                break;
            }
        }
        return finalVal;
    } 
};




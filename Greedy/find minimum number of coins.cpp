//https://www.geeksforgeeks.org/greedy-algorithm-to-find-minimum-number-of-coins/
// T.C. : O(V)
// S.C. : O(1)

void findmin(int V){
  int arr[] = {1,2,5,10,20,50,100,500,1000};
  
  int n = 9 ;
  vector<int> ans;
  
  for(int i = n-1 ; i >= 0 ; i--){
      while(V >= arr[i]){
        V -= arr[i];
        ans.push_back(arr[i]);
      }
  }
  
  for(int i = 0 ; i < ans.size() ; i++)
     cout<<ans[i]<<" ";
  
}



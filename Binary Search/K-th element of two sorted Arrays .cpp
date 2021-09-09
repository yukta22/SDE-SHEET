//https://practice.geeksforgeeks.org/problems/k-th-element-of-two-sorted-array1317/1#

//////////////////////////////////////////////////////////////Brute Approach//////////////////////////////////////////////////////////////
//T.C.:O(n) 
//S.C.:O(m + n) 

int kth(int arr1[], int arr2[], int m, int n, int k)
{
    int sorted1[m + n];
    int i = 0, j = 0, d = 0;
    while (i < m && j < n)
    {
        if (arr1[i] < arr2[j])
            sorted1[d++] = arr1[i++];
        else
            sorted1[d++] = arr2[j++];
    }
    while (i < m)
        sorted1[d++] = arr1[i++];
    while (j < n)
        sorted1[d++] = arr2[j++];
    return sorted1[k - 1];
}

//////////////////////////////////////////////////Space Optimized Version of above approach//////////////////////////////////////////////////
//T.C.:O(k) 
//S.C.:O(1)

#include <bits/stdc++.h>
using namespace std;
 
int find(int A[], int B[], int m, int n, int k_req)
{
    int k = 0, i = 0, j = 0;
 
    // Keep taking smaller of the current
    // elements of two sorted arrays and
    // keep incrementing k
    while(i < m && j < n)
    {
        if(A[i] < B[j])
        {
            k++;
            if(k == k_req)
                return A[i];
            i++;
        }
        else
        {
            k++;
            if(k == k_req)
                return B[j];
            j++;
        }
    }
 
    // If array B[] is completely traversed
    while(i < m)
    {
        k++;
        if(k == k_req)
            return A[i];
        i++;
    }
 
    // If array A[] is completely traversed
    while(j < n)
    {
        k++;
        if(k == k_req)
            return B[j];
        j++;
    }
}

////////////////////////////////////////////////////////////Binary Search approach////////////////////////////////////////////////////////////
//T.C.: O(log(min(n,m)))
//S.C.:O(1)

int kthElement(int arr1[], int arr2[], int n, int m, int k){
        if(n > m){
            return kthElement(arr2,arr1,m,n,k);
        }
        
        int low = max(0,k-m) , high = min(k,n);
        
        while(low <= high){
            int cut1 = (low + high) >> 1;
            int cut2 = k - cut1;
            
            int l1 = cut1 == 0 ? INT_MIN : arr1[cut1-1];
            int l2 = cut2 == 0 ? INT_MIN : arr2[cut2-1];
            int r1 = cut1 == n ? INT_MAX : arr1[cut1];
            int r2 = cut2 == m ? INT_MAX : arr2[cut2];
            
            if(l1 <= r2 && l2 <= r1){
                return max(l1,l2);
            }
            else if(l1 > l2){
                high = cut1 - 1;
            }
            else{
                low = cut1 + 1;
            }
            
        }
        return 1;
}


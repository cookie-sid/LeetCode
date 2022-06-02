// { Driver Code Starts
//Initial Template for C++

// CPP code to find largest and 
// second largest element in the array

#include <bits/stdc++.h>
using namespace std;



 // } Driver Code Ends
     

class Solution{
  public:
    /* Function to find largest and second largest element
    *sizeOfArray : number of elements in the array
    * arr = input array
    */
    vector<int> largestAndSecondLargest(int sizeOfArray, int arr[]){
        int max = INT_MIN, max2= INT_MIN;
        
        /*********************************
         * Your code here
         * This function should return a
         * vector with first element as
         * max and second element as 
         * second max
         * *******************************/
         vector<int> ans(2);
         if(sizeOfArray == 1) {
             ans[0] = arr[0];
             ans[1] = -1;
             return ans;
         }
         ans[0] = arr[0] > arr[1] ? arr[0] : arr[1];
         if(min(arr[0],arr[1]) == ans[0]) {
             ans[1] = -1;
         }
         else {
             ans[1] = min(arr[0],arr[1]);
         }
         for(int i = 2; i < sizeOfArray; i++) {
             if(arr[i] <= ans[1]) {
                 continue;
             }
             if(arr[i] > ans[1] and arr[i] < ans[0]) {
                 ans[1] = arr[i];
                 continue;
             }
             if(arr[i] > ans[0]) {
                 ans[1] = ans[0];
                 ans[0] = arr[i];
                 continue;
             }
         }
         return ans;
         
    }
};

// { Driver Code Starts.

// Driver Code
int main() {
	
	// Testcase input
	int testcases;
	cin >> testcases;
    
    // Looping through all testcases
	while(testcases--){
	    int sizeOfArray;
	    cin >> sizeOfArray;
	    
	    int arr[sizeOfArray];
	    
	    // Array input
	    for(int index = 0; index < sizeOfArray; index++){
	        cin >> arr[index];
	    }
	    Solution obj;
	    vector<int> ans = obj.largestAndSecondLargest(sizeOfArray, arr);
	    cout<<ans[0]<<' '<<ans[1]<<endl;
	}
	
	return 0;
}  // } Driver Code Ends
// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;



 // } Driver Code Ends
//User function template for C++

class Solution{
  public:
    // nums: given vector
    // return the Product vector P that hold product except self at each index
    vector<long long int> productExceptSelf(vector<long long int>& nums, int n) {
       
        //code here
        int countzeros = 0;
        long long int total = 1, withoutzero = 1;
        for(int i = 0; i < n; i++) {
            if(nums[i] == 0 and countzeros == 0) {
                countzeros++;
                total *= nums[i];
                continue;
            }
            if(nums[i] == 0 and countzeros > 0) {
                countzeros++;
                withoutzero = 0;
                total *= nums[i];
                break;
            }
            withoutzero *= nums[i];
            total *= nums[i];
        }
        vector<long long int> p(n);
        for(int i = 0; i < n; i++) {
            if(nums[i] == 0) {
                p[i] = withoutzero;
            }
            else {
                p[i] = total/nums[i];
            }
        }
        return p;
    }
};


// { Driver Code Starts.
int main()
 {
    int t;  // number of test cases
    cin>>t;
    while(t--)
    {
        int n;  // size of the array
        cin>>n;
        vector<long long int> arr(n),vec(n);
        
        for(int i=0;i<n;i++)    // input the array
        {
            cin>>arr[i];
        }
        Solution obj;
        vec = obj.productExceptSelf(arr,n);   // function call
        
        for(int i=0;i<n;i++)    // print the output
        {
            cout << vec[i] << " ";
        }
        cout<<endl;
    }
	return 0;
}  // } Driver Code Ends
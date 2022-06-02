// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
  public:
    int thirdLargest(int a[], int n)
    {
         //Your code here
         if(n < 3) {
             return -1;
         }
         vector<int> temp;
         for(int i = 0; i < 3; i++) {
             temp.push_back(a[i]);
         }
         sort(temp.begin(),temp.end());
         int highest = temp[2], secondHighest = temp[1], thirdHighest = temp[0];
         for(int i = 3; i < n; i++) {
             if(a[i] < thirdHighest) {
                 continue;
             }
             if(a[i] > thirdHighest and a[i] <= secondHighest) {
                 thirdHighest = a[i];
                 continue;
             }
             if(a[i] > secondHighest and a[i] <= highest) {
                 thirdHighest = secondHighest;
                 secondHighest = a[i];
                 continue;
             } 
             if(a[i] >= highest) {
                 thirdHighest = secondHighest;
                 secondHighest = highest;
                 highest = a[i];
                 continue;
             }
         }
         return thirdHighest;
    }

};

// { Driver Code Starts.
 
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
	    int n;
	    cin>>n;
	    int a[n];
	    for(int i=0;i<n;i++)
	        cin>>a[i];
	   Solution obj;
	    cout<<obj.thirdLargest(a,n)<<endl;
    }
}     // } Driver Code Ends
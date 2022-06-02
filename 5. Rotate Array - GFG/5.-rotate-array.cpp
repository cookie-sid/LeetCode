// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    
    //Function to rotate an array by d elements in counter-clockwise direction. 
    void rotateArr(int arr[], int d, int n){
        // code here
        d = d%n;
        d = n - d;
        int start = 0;
        int stepsDone = 0;
        while(stepsDone < n) {
            int next = start + d;
            int temp, prev = arr[start];
            while(next != start and stepsDone < n) {
                temp = arr[next];
                arr[next] = prev;
                prev = temp;
                next = (next + d)%n;
                stepsDone++;
            }
            if(next == start) {
                arr[next] = temp;
                stepsDone++;
                start = next + 1;
            }
        }
    }
};

// { Driver Code Starts.

int main() {
	int t;
	//taking testcases
	cin >> t;
	
	while(t--){
	    int n, d;
	    
	    //input n and d
	    cin >> n >> d;
	    
	    int arr[n];
	    
	    //inserting elements in the array
	    for(int i = 0; i < n; i++){
	        cin >> arr[i];
	    }
	    Solution ob;
	    //calling rotateArr() function
	    ob.rotateArr(arr, d,n);
	    
	    //printing the elements of the array
	    for(int i =0;i<n;i++){
	        cout << arr[i] << " ";
	    }
	    cout << endl;
	}
	return 0;
}  // } Driver Code Ends
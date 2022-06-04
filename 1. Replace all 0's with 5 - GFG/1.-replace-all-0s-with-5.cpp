// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

int convertFive(int n);

// Driver program to test above function
int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        cout << convertFive(n) << endl;
    }
}// } Driver Code Ends


/*you are required to complete this method*/
int convertFive(int n) {
    // Your code here
    int ans = 0, tens = 1;
    while(n > 0) {
        if(n % 10 == 0) {
            ans += tens*5;
        } 
        else {
            ans += tens*(n%10);
        }
        tens *= 10;
        n /= 10;
    }
    return ans;
}
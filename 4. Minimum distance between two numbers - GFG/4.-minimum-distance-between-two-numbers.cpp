// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution{
  public:
    int minDist(int a[], int n, int x, int y) {
        int lastX = -1, lastY = -1;
        int ans = n;
        for(int i = 0; i < n; i++) {
            if(x == a[i]) {
                
                if(lastY != -1) {
                    ans = min(ans,i - lastY);
                }
                lastX = i;
            }
            if(y == a[i]) {
                
                if(lastX != -1) {
                    ans = min(ans,i - lastX);
                }
                lastY = i;
            }
        }
        ans == n ? ans = -1 : ans = ans;
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        int x, y;
        cin >> x >> y;
        Solution obj;
        cout << obj.minDist(a, n, x, y) << endl;
    }
    return 0;
}
  // } Driver Code Ends
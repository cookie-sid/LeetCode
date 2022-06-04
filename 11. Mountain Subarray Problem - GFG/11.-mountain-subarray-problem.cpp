// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


 // } Driver Code Ends


class Solution{
  public:
    vector<bool> processQueries(int a[], int n, vector<pair<int, int>> &queries,
                                int q) {
        // code here
        vector <bool> res;
    int inc[n+1] = {0}, dec[n+1] = {0};
    dec[n-1] = n-1;
    for(int i=1; i<n; i++)
        inc[i] = (a[i] > a[i-1] ? i : inc[i-1]);
    for(int i=n-2; i>=0; i--)
        dec[i] = (a[i] > a[i+1] ? i : dec[i+1]);
    for(auto i:queries)
        res.push_back(dec[i.first] >= inc[i.second]);
    return res;
    }
};

// { Driver Code Starts.

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, i, q;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        cin >> q;
        vector<pair<int, int>> queries(q);
        for (i = 0; i < q; i++) {
            cin >> queries[i].first >> queries[i].second;
        }
        Solution obj;
        auto v = obj.processQueries(a, n, queries, q);
        for (bool u : v) {
            cout << (u ? "Yes\n" : "No\n");
        }
    }
    return 0;
}  // } Driver Code Ends
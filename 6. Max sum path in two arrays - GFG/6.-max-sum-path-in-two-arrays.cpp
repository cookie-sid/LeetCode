// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



 // } Driver Code Ends
class Solution{
    public:
    /*You are required to complete this method*/
     int max_path_sum(int A[], int B[], int l1, int l2)
    {
        //Your code here
        int startA = 0, startB = 0;
        int sumA = 0, sumB = 0, optSum = 0;
        while(startA < l1 and startB < l2) {
            
            if(A[startA] < B[startB]) {
                while(A[startA] < B[startB] and startA < l1) {
                    sumA += A[startA];
                    startA++;
                }
                continue;
            }
            if(A[startA] > B[startB]) {
                while(A[startA] > B[startB] and startB < l2) {
                    sumB += B[startB];
                    startB++;
                }
                continue;
            }
            if(A[startA] == B[startB]) {
                optSum += max(sumA,sumB) + A[startA];
                startA++;
                startB++;
                sumA = 0;
                sumB = 0;
            }
        }
        while(startA < l1) {
            sumA += A[startA++];
        }
        while(startB < l2) {
            sumB += B[startB++];
        }
        optSum += max(sumA,sumB);
        return optSum;
    }
};

// { Driver Code Starts.

int main()
{
    int T;
    cin>>T;

    while(T--)
    {
        int N,M;
        cin>>N>>M;
        fflush(stdin);
        int a[N],b[M];
        for(int i=0;i<N;i++)
            cin>>a[i];
        for(int i=0;i<M;i++)
            cin>>b[i];
        Solution obj;
        int result = obj.max_path_sum(a,b,N,M);
        cout<<result<<endl;
    }
}

  // } Driver Code Ends
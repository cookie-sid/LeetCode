class Solution:
    def removeDuplicates(self, arr):
        # code here
        res = [arr[0]]
        p = arr[0]
        for i in arr:
            if(p % i != 0):
                p *= i
                res.append(i)
                
        return res

#{ 
#  Driver Code Starts
if __name__=='__main__':
    t = int(input())
    for i in range(t):
        n = int(input())
        arr = list(map(int, input().strip().split()))
        res = Solution().removeDuplicates(arr)
        for i in range(len(res)):
            print(res[i], end=" ")
        print('')


# } Driver Code Ends
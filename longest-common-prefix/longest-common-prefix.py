class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        ans = ""
        for i in range(min([len(s) for s in strs])):
            if (len(set([s[i] for s in strs])) == 1):
                ans += strs[0][i]
            else:
                break
        return ans
            
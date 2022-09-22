class Solution:
    def reverseWords(self, s: str) -> str:
        ls = s.split(" ")
        ls = [x[::-1] for x in ls]
        ls = ' '.join(ls)
        return ls
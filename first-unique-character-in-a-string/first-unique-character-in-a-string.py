class Solution:
    def firstUniqChar(self, s: str) -> int:
        unique = list(filter(lambda x: x != -1,[c if v == 1 else -1 for c,v in Counter(s).items()]))
        return next(x for x in [i if s[i] in unique else -1 for i in range(len(s))] if x != -1) if len(unique) != 0 else -1
        
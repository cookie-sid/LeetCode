class Solution:
    def bagOfTokensScore(self, tokens: List[int], power: int) -> int:
        tokens.sort()
        start = 0
        end = len(tokens) - 1
        score = 0
        ans = 0
        while(start <= end):
            if score == 0:
                if power >= tokens[start]:
                    power -= tokens[start]
                    start += 1
                    score += 1
                else:
                    break
            else:
                if power >= tokens[start]:
                    power -= tokens[start]
                    start += 1
                    score += 1
                else:
                    score -= 1
                    power += tokens[end]
                    end -= 1
            
            ans = max(ans,score)
            
        return ans
                    
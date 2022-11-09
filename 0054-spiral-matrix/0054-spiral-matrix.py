class Solution:
    def spiralOrder(self, L: List[List[int]]) -> List[int]:
        ans = []
        rows = len(L)
        columns = len(L[0])
        top = 0
        start = 0
        end = columns - 1
        down = rows - 1

        while len(ans) != rows * columns:
            for col in range(start, end + 1):
                ans.append(L[top][col])

            for row in range(top + 1, down + 1):
                ans.append(L[row][end])

            if top != down:
                for col in range(end - 1, start - 1, -1):
                    ans.append(L[down][col])

            if start != end:
                for row in range(down - 1, top, -1):
                    ans.append(L[row][start])

            start += 1
            end -= 1
            top += 1
            down -= 1

        return ans
        
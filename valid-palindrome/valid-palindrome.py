class Solution:
    def isPalindrome(self, s: str) -> bool:
        arr = [c for c in s.lower() if ord('a') <= ord(c) <= ord('z') or ord('0') <= ord(c) <= ord('9')]
        return arr == arr[::-1]
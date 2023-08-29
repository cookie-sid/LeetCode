class Solution:
    def reverse(self, x: int) -> int:
        val = int(str(x)[::-1]) if x >= 0 else -int(str(x)[1:][::-1])
        print(-(1<<31),val,((1<<31) - 1))
        return val if (-(1<<31)) <= val < (1<<31) else 0
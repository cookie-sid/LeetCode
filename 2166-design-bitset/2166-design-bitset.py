class Bitset:
    
    size = 1
    p = [0]
    flipped = False
    allSet = False
    oneSet = False
    setBits = 0

    def __init__(self, size: int):
        self.p = self.p * size
        self.size = size

    def fix(self, idx: int) -> None:
        if((self.p[idx] == 0 and not self.flipped) or (self.p[idx] == 1 and self.flipped)):
            self.setBits += 1
        self.p[idx] = 1 if not self.flipped else 0

    def unfix(self, idx: int) -> None:
        if((self.p[idx] == 1 and not self.flipped) or (self.p[idx] == 0 and self.flipped)):
            self.setBits -= 1
        self.p[idx] = 0 if not self.flipped else 1

    def flip(self) -> None:
        self.flipped = not self.flipped
        self.setBits = self.size - self.setBits

    def all(self) -> bool:
        return self.setBits == self.size

    def one(self) -> bool:
        return self.setBits > 0 

    def count(self) -> int:
        return self.setBits

    def toString(self) -> str:
        if not self.flipped:
            x = [str(c) for c in self.p]
        else:
            x = [str(1-c) for c in self.p]
        return ''.join(x)


# Your Bitset object will be instantiated and called as such:
# obj = Bitset(size)
# obj.fix(idx)
# obj.unfix(idx)
# obj.flip()
# param_4 = obj.all()
# param_5 = obj.one()
# param_6 = obj.count()
# param_7 = obj.toString()
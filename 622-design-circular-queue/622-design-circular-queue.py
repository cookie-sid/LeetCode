class MyCircularQueue:
    
    insert = 0
    pop = 0
    front = -1
    end = -1
    size = 0
    ls = []

    def __init__(self, k: int):
        self.ls = [0]*k
        self.size = k

    def enQueue(self, value: int) -> bool:
        if self.isFull():
            return False
        self.insert += 1
        self.end += 1
        self.end %= self.size
        self.ls[self.end] = value
        return True

    def deQueue(self) -> bool:
        if self.isEmpty():
            return False
        self.pop += 1
        self.front += 1
        self.front %= self.size
        return True

    def Front(self) -> int:
        if self.isEmpty():
            return -1
        return self.ls[(self.front + 1)%self.size]

    def Rear(self) -> int:
        if self.isEmpty():
            return -1
        return self.ls[self.end]
        

    def isEmpty(self) -> bool:
        return self.insert == self.pop

    def isFull(self) -> bool:
        return self.insert - self.pop == self.size
        


# Your MyCircularQueue object will be instantiated and called as such:
# obj = MyCircularQueue(k)
# param_1 = obj.enQueue(value)
# param_2 = obj.deQueue()
# param_3 = obj.Front()
# param_4 = obj.Rear()
# param_5 = obj.isEmpty()
# param_6 = obj.isFull()
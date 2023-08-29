# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def hasCycle(self, head: Optional[ListNode]) -> bool:
        fast,slow = head,head
        while fast:
            if fast.next:
                fast = fast.next
            else:
                return False
            if fast == slow:
                return True
            if fast.next:
                fast = fast.next
            else:
                return False
            if fast == slow:
                return True
            slow = slow.next
        return False
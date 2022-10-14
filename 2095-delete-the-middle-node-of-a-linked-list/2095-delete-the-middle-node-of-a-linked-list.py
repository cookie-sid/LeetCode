# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def deleteMiddle(self, head: Optional[ListNode]) -> Optional[ListNode]:
        fast = head
        slow = head
        prev = head
        if not head.next:
            return None
        while fast.next:
            prev = slow
            slow = slow.next
            if fast.next.next:
                fast = fast.next.next
            else:
                fast = fast.next
        prev.next = slow.next
        return head
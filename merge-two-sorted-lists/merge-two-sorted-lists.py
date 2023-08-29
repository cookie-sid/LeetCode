# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeTwoLists(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:
        
        first = list1
        second = list2
        head = None
        newHead = None
        while first and second:
            if not head:
                if first.val < second.val:
                    head = first
                    newHead = head
                    first = first.next
                else:
                    head = second
                    newHead = head
                    second = second.next
            else:
                if first.val < second.val:
                    head.next = first
                    first = first.next
                    head = head.next
                else:
                    head.next = second
                    second = second.next
                    head = head.next
        while first:
            if not head:
                head = first
                newHead = first
            else:
                head.next = first
                head = head.next
            first = first.next
        while second:
            if not head:
                head = second
                newHead = second
            else:
                head.next = second
                head = head.next
            second = second.next
        print(head,newHead)
        return newHead
        
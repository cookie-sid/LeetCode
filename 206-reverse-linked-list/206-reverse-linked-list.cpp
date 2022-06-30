/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == NULL or head->next == NULL) {
            return head;
        }
        ListNode* curr = head;
        ListNode* afterCurr = head -> next;
        curr -> next = NULL;
        while(afterCurr -> next != NULL) {
            ListNode* afterAfterCurr = afterCurr -> next;
            afterCurr -> next = curr;
            curr = afterCurr;
            afterCurr = afterAfterCurr;
        }
        afterCurr -> next = curr;
        return afterCurr;
    }
};
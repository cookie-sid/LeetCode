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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *curr = head, *prev = head, *trav = head;
        int size = 0;
        while(size < n and trav -> next != NULL) {
            trav = trav -> next;
            size += 1;
        }
        if(trav -> next == NULL and size != n) {
            return head -> next;
        }
        if(head -> next == NULL) {
            return NULL;
        }
        while(trav -> next != NULL) {
            trav = trav -> next;
            curr = curr -> next;
        }
        curr -> next = curr -> next -> next == NULL ? NULL : curr -> next -> next;
        return head;
    }
};
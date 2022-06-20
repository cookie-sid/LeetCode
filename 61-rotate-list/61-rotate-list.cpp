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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL) {
            return head;
        }
        int n = 1;
        ListNode* temp = head;
        while(temp -> next != NULL) {
            n++;
            temp = temp -> next;
        }
        k = k % n;
        int tmp = n - k;
        temp = head;
        while(tmp--) {
            if(temp -> next == NULL) {
                temp = head;
                continue;
            }
            temp = temp->next;
        }
        ListNode* newHead = new ListNode(temp -> val);
        ListNode* newTemp = newHead;
        n -= 1;
        while(n--) {
            if(temp -> next != NULL) {
                temp = temp -> next;
            }
            else {
                temp = head;
            }
            ListNode* newTmp = new ListNode(temp -> val);
            newHead -> next = newTmp;
            newHead = newHead -> next;
        }
        return newTemp;
    }
};
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *h1 = list1, *h2 = list2;
        if(h1 == NULL) {
            return h2;
        }
        if(h2 == NULL) {
            return h1;
        }
        
        while(h1 != NULL and h2 != NULL) {
            if(h1 -> val < h2 -> val) {
                while(h1 -> next != NULL and h1 -> next -> val <= h2 -> val) {
                    h1 = h1 -> next;
                }
                if(h1 -> next != NULL) {
                    ListNode *temp = h1;
                    h1 = h1 -> next;
                    temp -> next = h2;
                    temp = h2;
                    h2 = h1;
                    h1 = temp;
                }
                else {
                    h1 -> next = h2;
                    break;
                }
            }
            else {
                while(h2 -> next != NULL and h2 -> next -> val <= h1 -> val) {
                    h2 = h2 -> next;
                }
                if(h2 -> next != NULL) {
                    ListNode *temp = h2;
                    h2 = h2 -> next;
                    temp -> next = h1;
                    temp = h1;
                    h1 = h2;
                    h2 = temp;
                }
                else {
                    h2 -> next = h1;
                    break;
                }
            }
        }
        return list1 -> val < list2 -> val ? list1 : list2;
    }
};
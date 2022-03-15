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
        
        if(list1 == NULL)
            return list2;
        if(list2 == NULL)
            return list1;
        
        if(list1 -> val > list2 -> val) {
            ListNode* temp = list1;
            list1 = list2;
            list2 = temp;
        }
        ListNode* currhead = list1;
        while(list1 -> next != NULL and list1 -> next -> val <= list2 -> val) {
            list1 = list1 -> next; 
            cout<<list1->val<<endl;
        }
        
        ListNode* temp = list1 -> next;
        ListNode* temp2 = list2;
        list1 -> next = list2;
        if(temp2 -> next == NULL) {
            list2 -> next = temp;
            return currhead;
        }
        list2 -> next = mergeTwoLists(temp, temp2 -> next);
        
        return currhead;
        
    }
};
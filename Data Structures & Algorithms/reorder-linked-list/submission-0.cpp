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
    void reorderList(ListNode* head) {
        if (!head || !head->next) return;
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* sec = slow->next;
        slow->next = NULL;
        ListNode* prev = NULL;
        while (sec) {
            ListNode* next = sec->next;
            sec->next = prev;
            prev = sec;
            sec = next;
        }
        sec = prev;

        ListNode* first = head;
        while(sec){
            ListNode* temp1= first->next;
            ListNode* temp2=sec->next;


            first->next=sec;
            sec->next=temp1;

            first= temp1;
            sec = temp2;
        }
    }
};

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
        ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head || left == right) return head;
        
        // Dummy node to simplify edge cases (like left=1)
        ListNode dummy(0);
        dummy.next = head;

        // 1) Move 'prev' just before the sublist
        ListNode* prev = &dummy;
        for (int i = 1; i < left; i++) {
            prev = prev->next;  // after this loop, prev is node BEFORE 'left'
        }

        // 2) 'start' is the first node of the sublist we want to reverse
        //    'then' is the node after 'start'
        ListNode* start = prev->next;
        ListNode* then = start->next;

        // 3) Reverse sublist [left..right]
        //    We iteratively move 'then' to the front
        for (int i = 0; i < (right - left); i++) {
            start->next = then->next;  // remove 'then' from its place
            then->next = prev->next;   // insert 'then' at the front
            prev->next = then;         // re-link 'prev' to 'then'
            then = start->next;        // advance 'then'
        }

        return dummy.next;
    }
};
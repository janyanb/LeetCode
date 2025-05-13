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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head) return nullptr;

        ListNode* slow = head;
        ListNode* dummy = new ListNode(-101, head);
        ListNode* prev = dummy;
        int value = -101;

        while(slow){
            if(slow -> next && slow -> val == slow -> next -> val){
                value = slow -> val;
                while(slow && slow -> val == value){
                    slow = slow -> next;
                }
                prev -> next = slow;
            }else {
                prev = slow;
                slow = slow -> next;
            }

        }

        return dummy -> next;
    }
};
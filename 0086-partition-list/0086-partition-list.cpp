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
    ListNode* partition(ListNode* head, int x) {
        ListNode* lessthan = new ListNode();
        ListNode* lstart = lessthan;
        ListNode* greaterthan = new ListNode();
        ListNode* gstart = greaterthan;
        ListNode* curr = head;

        while(curr){
            if(curr -> val < x){
                lessthan -> next = curr;
                lessthan = lessthan -> next;
            } else {
                greaterthan -> next = curr;
                greaterthan = greaterthan -> next;
            }
            curr = curr-> next;
        }

        greaterthan -> next = nullptr;
        lessthan -> next = gstart -> next;

        return lstart -> next;
    }
};
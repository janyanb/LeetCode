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
        if(left == right || !head->next) return head;
        if(!head) return nullptr;

        ListNode *dummy = new ListNode(0, head);       
        ListNode *beforeLeft = dummy;              //to handle edge cases of left = 1
        ListNode *curr = head;
        //traverse the linked list until left
        for(int i = 1; i<left; i++){
            curr = curr->next;
            beforeLeft = beforeLeft->next;
        }

        ListNode  *prev = curr, *temp;
        ListNode *lNode = prev->next;
        for(int j = left; j<right; j++){
            temp = lNode->next;
            lNode->next = prev;
            prev = lNode;
            lNode = temp;
        }

        curr->next = temp;
        beforeLeft->next = prev;

        return dummy->next;
    }
};
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
        if(!head) return nullptr;
        if(!k) return head;

        int length = 1;
        ListNode *temp = head, *temp2 = head;

        while(temp->next){
            length++;
            temp = temp->next;            //stops at last node  
        }
       
        k = k%length;                     //to remove extra rotations
        if(k == 0) return head;
        int End = length - k;
        temp->next = head;                //form a circular linked list

        for(int i = 1; i < End; i++){
            temp2 = temp2->next;
        }

        ListNode* newHead = temp2->next;
        temp2->next = nullptr;

    return newHead;
    }
};
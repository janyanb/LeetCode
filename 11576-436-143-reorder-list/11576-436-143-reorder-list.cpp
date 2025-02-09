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

        //find the center of list
        ListNode *slow = head, *fast = head->next;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }

        //reverse the second half of list
        ListNode *second = slow->next;
        ListNode *temp, *prev = nullptr;
        slow->next = nullptr;
        while(second){
            temp = second->next;
            second->next = prev;
            prev = second;
            second = temp;
        };

        //merge two lists together
        ListNode *pt1, *pt2, *first = head, *last = prev;
        while(last){
            pt1 = first->next;
            pt2 = last->next;
            first->next = last;
            last->next= pt1;
            first = pt1;
            last = pt2;
        };

        
    }
};
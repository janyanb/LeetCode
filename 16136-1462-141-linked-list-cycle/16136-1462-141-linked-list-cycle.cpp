/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        /*unordered_set<ListNode*> visited; 
        ListNode* curr = head;
        while(curr != nullptr){
            if(visited.find(curr) != visited.end()){
                return true;
            }

            visited.insert(curr);
            curr = curr->next;
        }
        return false; */
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast != nullptr && fast->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast){
                return true;
            }
        }
        return false;    
    }
};
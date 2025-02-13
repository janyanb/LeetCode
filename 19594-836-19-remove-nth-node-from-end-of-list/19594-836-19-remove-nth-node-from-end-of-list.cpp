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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        //reverse the entire linked list
        //remove nth node from the last
        //continue the link

        ListNode *current = head;
        ListNode *temp, *prev = nullptr;
        while(current){
            temp = current->next;
            current->next = prev;
            prev = current;
            current = temp;
        }

        ListNode *end = prev;          
        if(n == 1){
            prev = prev->next;
            end = prev;
        }else {
            current = prev;
            for(int i = 1; i < n-1 && current; i++){
                current= current->next;
            };
            if(current && current-> next){
                current->next = current->next->next; 
            }      
        }

        
        ListNode *prev1 = nullptr;
        while(end){
            temp = end->next;
            end->next = prev1;
            prev1 = end;
            end = temp;            
        }

        return prev1;                    
        
    }
};
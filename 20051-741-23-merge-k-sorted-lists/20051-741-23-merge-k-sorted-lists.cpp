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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()) return nullptr;

        ListNode *merged = lists[0];
        for(int i = 1; i< lists.size(); i++){
            merged = merge2lists(merged, lists[i]);
        }
        return merged;        
    };

    ListNode* merge2lists(ListNode* list1, ListNode* list2){
        ListNode *dummy = new ListNode();
        ListNode *tail = dummy;

        while(list1 && list2){
            if(list1->val>list2->val){
                tail->next = list2;
                list2=list2->next;
            } else {
                tail->next=list1;
                list1=list1->next;
            }
            tail=tail->next;
        };

        if(list1){
            tail->next=list1;
        } else if(list2){
            tail->next=list2;
        }

        return dummy->next;
    }
};
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
                // if(!l1) return l2;
        // if(!l2) return l1;
        // if(!l1 && !l2) return nullptr;

        // string num1;
        // string num2;

        // while(l1){
        //     int value1 = l1->val;
        //     num1 += to_string(value1);   //num1 = 243
        //     l1 = l1->next;                 
        // }

        // while(l2){
        //     int value2 = l2->val;
        //     num2 += to_string(value2);        //num2 = 564
        //     l2 = l2->next;
        // }

        // reverse(num1.begin(), num1.end());
        // reverse(num2.begin(), num2.end());

        // int number1 = stoi(num1);
        // int number2 = stoi(num2);

        // int totalInt = number1+ number2;
        // string totalStr = to_string(totalInt);

        // ListNode* dummy = new ListNode();
        // ListNode* tail = dummy; 
        // for(int i = totalStr.size() - 1; i>=0; i--){
        //     ListNode* curr = new ListNode(stoi(string(1,totalStr[i])));
        //     cout<<curr->val;
        //     tail->next = curr;
        //     tail = tail->next;            
        // }
        
        // return dummy->next;
        ListNode* dummy = new ListNode();
        ListNode* tail = dummy;
        int carry = 0;

        while(l1|| l2|| carry){
            int dig1 = (l1!= nullptr)? l1->val : 0;
            int dig2 = (l2!= nullptr)? l2->val : 0;

            int sum = dig1 + dig2 + carry;
            carry = sum/10;              //if sum = 18, 18/10 = 1, 18%10 = 8
            int digit = sum%10;

            tail->next = new ListNode(digit);
            tail = tail->next;

            if(l1) l1 = l1->next;
            if(l2) l2 = l2->next;
        }

        return dummy->next;
    }
};
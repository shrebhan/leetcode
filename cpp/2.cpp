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
        
        ListNode *res = new ListNode();
        ListNode *trav = res;
        int carry;
        while(l1 && l2) //make this || and shorten - TODO
        {
            int x = (trav->val + l1->val + l2->val);
            trav->val = x%10;
            carry = x/10;
            if(l1->next || l2->next || carry)trav->next = new ListNode(carry);
            trav = trav->next;
            l1=l1->next;
            l2=l2->next;
        }
        
        while(l1)
        {
            int x = (trav->val + l1->val);
            trav->val = x%10;
            carry = x/10;
            if(carry)
            {
                trav->next = new ListNode(carry);
                trav = trav->next;
            }
            else
            {
                trav->next = l1->next;
                break;
            }
            l1=l1->next;
        }
        
        while(l2)
        {
            int x = (trav->val + l2->val);
            trav->val = x%10;
            carry = x/10;
            if(carry)
            {
                trav->next = new ListNode(carry);
                trav = trav->next;
            }
            else
            {
                trav->next = l2->next;
                break;
            }
            l2=l2->next;
        }
        
        return res;
    }
};
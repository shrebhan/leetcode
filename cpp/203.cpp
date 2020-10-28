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
       
    ListNode* removeElements(ListNode* head, int val) {
               
        ListNode* node = head;
        ListNode* prev = head;
        
        if(!head) return NULL;
        if(head->val == val && !head->next) return NULL;
 
        while(node)
        {
            if(node->val == val)
            {
                if(node->next)
                {
                    node->val = node->next->val;
                    node->next = node->next->next;                   
                }
                else
                {
                    //cout<<node->val<<endl;
                    if(node == head) return NULL;                 
                    //cout<<prev->val<<endl;
                    prev->next = NULL;
                    node = prev->next;
                }               
            }
            else
            {
                //cout<<node->val<<endl;
                prev = node;
                node = node->next;
            }
        }        
        return head;
    }
};
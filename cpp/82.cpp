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
    ListNode* deleteDuplicates(ListNode* head) {
        
        if(!head) return head;
        if(!head->next) return head;
        
        ListNode *node1=head;
        ListNode *prev=head;
        bool flag=false;
        while(node1 && node1->next)
        {
            if(node1->val == node1->next->val)
            {
                //cout<<node1->val;
                if(node1==head) flag=true;
                while(node1 && node1->next && node1->val == node1->next->val)
                {
                    node1=node1->next;
                }
                if(flag)
                {
                    node1=node1->next;
                    prev=node1;
                    head=node1;
                    flag=false;
                }
                else
                {
                    prev->next=node1->next;
                    node1=node1->next;
                }
                
            }
            else
            {
                prev=node1;
                node1=node1->next;
            }
        }
        return head;
    }
};
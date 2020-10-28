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
    
    ListNode* reverse(ListNode* head)
    {
        if(!head || !head->next) return head;
        
        //else
        
        ListNode* node = reverse(head->next);
        head->next->next = head;
        head->next = NULL;
        return node;
    }
    
    ListNode* rotateRight(ListNode* head, int k) {
        
        if(!head) return head;
        
        ListNode *node1 = head, *node2 = head;
        int cnt=1;
        
        while(node1->next)
        {
            cnt++;
            node1=node1->next;
        }
        
        if(k >= cnt)
        {
            k=k%cnt;
        }
        
        node1 = head;
        while(node1->next)
        {
            if(!k)
            {
                node2=node2->next;
            }
            else
            {
                k--;
            }
            node1=node1->next;
        }
        
        node1->next = head;
        head = node2->next;
        node2->next = NULL;
         
        return head;
    }
};
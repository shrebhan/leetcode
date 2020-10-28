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
    ListNode* reverseList(ListNode* node)
    {
        if(node == NULL || node->next == NULL) return node;
        
        ListNode *head = reverseList(node->next);
        node->next->next = node;
        node->next = NULL;
        return head;
    }
    
    ListNode* getMiddle(ListNode* node)
    {
        ListNode *ponce=node, *ptwice=node->next;
        while(ptwice != NULL && ptwice->next != NULL)
        {
            ponce = ponce->next;
            ptwice = ptwice->next->next;
        }
        
        return ponce;
    }
    
    void reorderList(ListNode* head) {
        // 1. store reversed ll & then make required ll
        
        if(!head) return;
        
        ListNode *h = getMiddle(head);
        //cout<<p->val<<endl;
        
        //divide list and make 2 lists
        ListNode* head2 = h->next;
        h->next = NULL;
        
        // reverse second part of list
        head2 = reverseList(head2);
        
        // now merge both lists
        h = head;
        ListNode *temp = head;
        while(h->next)
        {
            temp = h->next;
            h->next = head2;
            head2 = head2->next;
            h->next->next = temp;
            h = h->next->next;
        }
        h->next = head2;
    }
};
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
    ListNode* reverseList(ListNode* head)
    {
        if(!head || head->next == NULL) return head;
        
        //cout<<head->val<<endl;
        ListNode *ret = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        //cout<<head->val<<" ";
        return ret;
    }
    bool isPalindrome(ListNode* head) {
        if(!head) return true;
        if(!head->next) return true;
        ListNode* start=head, *end=head, *mid=head, *mprev = head;
        
        while(end->next)
        {
            mprev = mid;
            mid = mid->next;
            
            end=end->next;
            if(end->next) end=end->next;
        }
        mprev->next = NULL;
        end = reverseList(mid);
        //cout<<end->val;
        #if 1
        while(head && end)
        {
            if(head->val != end->val) return false;
            if(head->next)
            {
                if(end->next)
                {
                    head=head->next;
                    end=end->next;
                }
                else return false;
            }
            else break;
        }
        #endif
        
        return true;
    }
};
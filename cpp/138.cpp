/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        
        if(!head) return head;
        
        Node *l = head;
        Node *newhead = NULL;
        Node *n  = NULL;
    
        
        while(l)
        {
            n = new Node(l->val);
            n->next = l->next;
            l->next = n;
            l = l->next->next;
            
            //n = new_node;
        }
        n = head;
        newhead = head->next;
        while(n)
        {
            //cout<<n->val<<endl;
            //n=n->next;
            if(!n->random) 
            {
                n->next->random = NULL;
            }
            else
            {
                n->next->random = n->random->next;
            }
            if(n->next)
            { n = n->next->next;}
        }
        
        l = head;
        n = head->next;
        while(l && l->next && n && n->next)
        {
            //cout<<"l = "<<l->val<<"  ";
            //cout<<"n = "<<n->val<<"  ";
            
            l->next = l->next->next;
            l = l->next;
            
            n->next = n->next->next;
            n = n->next;
        }
        l->next = NULL;
        n->next = NULL;
        
        
        return newhead;
    }
};
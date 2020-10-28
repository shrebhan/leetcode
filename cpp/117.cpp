/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/
class Solution {
public:
    Node* connect(Node* root) {
                      
        if(!root) return NULL;
        
        if(root->left)
        {
            if(root->right) root->left->next = root->right;
            else
            {
                Node *temp = root;
                while(temp->next)
                {
                    if(temp->next->left) {
                        root->left->next = temp->next->left;
                        break;
                    }
                    else if(temp->next->right) {
                        root->left->next = temp->next->right;
                        break;
                    }
                    temp = temp->next;
                }
            }
            
        }
        if(root->right)
        {
            Node *temp = root;
            while(temp->next)
            {
                if(temp->next->left) {
                    //cout<<temp->next->val<<endl;
                    //cout<<temp->next->left->val<<endl;
                    root->right->next = temp->next->left;
                    break;
                }
                else if(temp->next->right) {
                    root->right->next = temp->next->right;
                    break;
                }
                temp = temp->next;
                //cout<<temp->val;
            }
        }
        
        connect(root->right);
        connect(root->left);
        return root;

        
    }
};
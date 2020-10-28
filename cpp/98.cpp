/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
   bool isValidBST(TreeNode* root) {
    return isValidBST(root, NULL, NULL);
}

bool isValidBST(TreeNode* root, TreeNode* min, TreeNode* max) {
    if(!root) return true;
    
    cout<<root->val<<" ";
    if(min) cout<<"min-"<<min->val;
    if(max) cout<<"max-"<<max->val;
    cout<<endl;
    
    if(min && root->val <= min->val || max && root->val >= max->val)
        return false;
    
    return isValidBST(root->left, min, root) && isValidBST(root->right, root, max);
}
    
};
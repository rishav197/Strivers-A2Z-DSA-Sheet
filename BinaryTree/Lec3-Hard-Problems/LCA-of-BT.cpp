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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        //base cases
        if(root==NULL){
            return NULL;
        }

        if(root->val==p->val or root->val==q->val){
            return root;
        }

        TreeNode* ltAns = lowestCommonAncestor(root->left,p,q);
        TreeNode* rtAns = lowestCommonAncestor(root->right,p,q);

        //conditions
        if(ltAns!=NULL and rtAns!=NULL){
            return root;
        }
        else if(ltAns==NULL and rtAns!=NULL){
            return rtAns;
        }
        else if(ltAns!=NULL and rtAns==NULL){
            return ltAns;
        }
        else{
            return NULL;
        }
    }
};
/*
approach : Recursive 
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        //base case
        if(root==NULL){
            return NULL;
        }

        if(root->val>p->val and root->val>q->val){
            return lowestCommonAncestor(root->left, p, q); //go to LST
        }
        if(root->val<p->val and root->val<q->val){
            return lowestCommonAncestor(root->right, p, q); //go to RST
        }

        return root;
    }
};


/*approach: Iterative */


class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        //base case
        if(root==NULL){
            return NULL;
        }

        while(root!=NULL){
            if(root->val>p->val and root->val>q->val){
                root=root->left;
            }
            else if(root->val<p->val and root->val<q->val){
                root=root->right;
            }
            else{
                break;
            }
        }

        return root;
    }
};
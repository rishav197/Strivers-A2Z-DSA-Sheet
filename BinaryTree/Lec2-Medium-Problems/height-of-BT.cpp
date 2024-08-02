/* 
TC -> O(N), SC -> O(height)
*/

class Solution {
public:
    int height(TreeNode* root){
        //base case
        if(root==NULL){
            return 0;
        }

        int ht_lt = height(root->left); //calc ht for left subtree
        int ht_rt = height(root->right); //calc ht for right subtree

        return max(ht_lt, ht_rt)+1;
    }

    int maxDepth(TreeNode* root) {
        int ht = height(root);    

        return ht;
    }
};
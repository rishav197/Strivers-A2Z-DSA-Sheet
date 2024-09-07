
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        //base case
        if(root==NULL){
            root = new TreeNode(val);
            return root;
        }

        if(root->val>val){
            //insert in left part
            root->left = insertIntoBST(root->left, val);
        }
        else{
            //insert in right part
            root->right = insertIntoBST(root->right, val);
        }

        return root;
    }
};
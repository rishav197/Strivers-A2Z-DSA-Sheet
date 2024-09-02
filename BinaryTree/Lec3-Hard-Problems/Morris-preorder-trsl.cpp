
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> preorder;
        TreeNode* cur = root;

        while(cur!=NULL){
            if(cur->left == NULL){
                preorder.push_back(cur->val);
                cur=cur->right;
            }
            else{
                TreeNode* prev = cur->left;
                //here we're going to rightmost node in the subtree
                while(prev->right and  prev->right!=cur){
                    prev=prev->right;
                }

                //make right most node on left Subtree connected to current node then go left
                if(prev->right == NULL){
                    prev->right = cur;
                    preorder.push_back(cur->val);
                    cur=cur->left;
                }
                else{ //if thread is already pointed to current node then remove the thread
                    prev->right=NULL;
                    cur=cur->right;
                }
            }
        }

        return preorder;
    }
};

class Solution {
public:
    bool solve(TreeNode* root1, TreeNode* root2){
        //base cases
        if(root1==NULL and root2==NULL){
            return true;
        }
        if(root1!=NULL and root2==NULL){
            return false;
        }
        if(root1==NULL and root2!=NULL){
            return false;
        }

        bool val1 = solve(root1->left, root2->right);
        bool val2 = solve(root1->right, root2->left);

        bool cond = (root1->val==root2->val);

        if(val1 and val2 and cond){
            return true;
        }
        else{
            return false;
        }
    }

    bool isSymmetric(TreeNode* root) {
        if(root==NULL){
            return true;
        }
        if(root->left==NULL and root->right==NULL){
            return true;
        }

        bool ans = solve(root->left, root->right);
        return ans;
    }
};
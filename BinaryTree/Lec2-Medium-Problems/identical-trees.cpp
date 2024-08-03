/* 
tc -> O(N), sc -> 
*/
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==NULL and q==NULL){
            return true;
        }

        if(p!=NULL and q==NULL){
            return false;
        }

        if(p==NULL and q!=NULL){
            return false;
        }

        bool left = isSameTree(p->left, q->left);
        bool right = isSameTree(p->right, q->right);

        bool condition = p->val == q->val;
        if(left and right and condition){
            return true;
        }

        return false;
    }
};
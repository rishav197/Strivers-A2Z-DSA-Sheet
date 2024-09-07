/* tc -> O(Ht), sc->O(1)
*/
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        
        TreeNode* temp = root;
        while(temp!=NULL){
            if(temp->val==val){
                return temp;
            }
            if(temp->val>val){
                //search in left part
                temp=temp->left;
            }
            else{
                //search in right part
                temp=temp->right;
            }
        }

        return NULL;
    }
};
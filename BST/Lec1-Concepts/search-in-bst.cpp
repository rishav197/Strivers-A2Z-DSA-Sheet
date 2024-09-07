/* tc -> O(Ht), sc->O(1)
approach-1: Iterative approach
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


/*
approach-2 : Recursive approach
*/

class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        //base cases
        if(root==NULL){
            return NULL;
        }

        if(root->val==val){
            return root;
        }

        if(root->val>val){
            //search in left part
            return searchBST(root->left, val);
        }
        else{
            //search in right part
            return searchBST(root->right, val);
        }
    }
};
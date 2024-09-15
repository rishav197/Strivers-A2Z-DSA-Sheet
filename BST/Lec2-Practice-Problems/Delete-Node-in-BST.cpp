
class Solution {
public:
    TreeNode* minVal(TreeNode* root){
        if(root==NULL){
            return NULL;
        }

        TreeNode* tmp = root;
        while(tmp->left!=NULL){
            tmp = tmp->left;
        }
        return tmp;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        //base case
        if(root==NULL){
            return root;
        }        

        //algo starts here
        if(root->val==key){
            // 0 Child case
            if(root->left==NULL and root->right==NULL){
                return NULL;
            }

            // 1 Child case
            //if it has only leftchild
            if(root->left!=NULL and root->right==NULL){
                TreeNode* temp = root->left;
                delete root;
                return temp;
            }

            //if it has only rightchild
            if(root->left==NULL and root->right!=NULL){
                TreeNode* temp = root->right;
                delete root;
                return temp;
            }

            // 2 Child case
            if(root->left!=NULL and root->right!=NULL){
                int mini = minVal(root->right)->val;
                root->val = mini;

                root->right = deleteNode(root->right, mini);
                return root;
            }
        }
        else if(root->val>key){
            //search in LST
            root->left = deleteNode(root->left, key);
            return root;
        }
        else{
            //search in RST
            root->right = deleteNode(root->right, key);
            return root;
        }

        return root;
    }
};
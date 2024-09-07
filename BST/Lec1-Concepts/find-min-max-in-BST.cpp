/*Find Min in BST */

class Solution {
  public:
    int minValue(Node* root) {
        Node* tmp = root;
        
        while(tmp->left!=NULL){
            //update (move in left subtree)
            tmp = tmp->left;
        }
        
        return tmp->data;
    }
};


/*Find Max in BST */

class Solution {
  public:
    int maxValue(Node* root) {
        Node* tmp = root;
        
        while(tmp->right!=NULL){
            //update (move in left subtree)
            tmp = tmp->right;
        }
        
        return tmp->data;
    }
};
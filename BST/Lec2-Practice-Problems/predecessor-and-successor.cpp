
class Solution
{
    public:
    void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
    {
        //find the key
        Node* tmp = root;

        if(root==NULL){
            return;
        }

        
        while(tmp!=NULL){
            if(tmp->key==key){
                break;
            }
            else if(tmp->key>key){ //go to lST
                suc=tmp;
                tmp=tmp->left;
            }
            else{ //go to RST
                pre=tmp;
                tmp=tmp->right;
            }
        }
        
        if(tmp==NULL){
            return;
        }
        
        //for pre
        Node* leftTree = tmp->left;
        while(leftTree!=NULL){
            pre=leftTree;
            leftTree=leftTree->right;
        }

        
        //for suc
        Node* rightTree = tmp->right;
        while(rightTree!=NULL){
            suc=rightTree;
            rightTree=rightTree->left;
        }

        
    }
};
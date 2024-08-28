class Solution{
    public:
    //Function to check whether all nodes of a tree have the value 
    //equal to the sum of their child nodes.
    bool isSum(Node* root){
        //base cases
        if(root==NULL){
            return true;
        }
        
        if(root->left==NULL and root->right==NULL){
            return true;
        }
        
        int ltData = (root->left) ? root->left->data : 0;
        int rtData = (root->right) ? root->right->data : 0;
        
        bool ltAns = isSum(root->left);
        bool rtAns = isSum(root->right);
        
        //Check for sum property 
        if((root->data==ltData+rtData) and ltAns and rtAns){
            return true;
        }
        
        return false;
    }
    
    int isSumProperty(Node *root)
    {
        return isSum(root);
    }
};
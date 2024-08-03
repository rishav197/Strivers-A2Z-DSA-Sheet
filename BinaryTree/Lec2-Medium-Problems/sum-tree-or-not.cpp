struct Node
{
    int data;
    Node* left, * right;
}; */

// Should return true if tree is Sum Tree, else false

class Solution {
  public:
    pair<bool,int> isSumFast(Node* root){
        //base cases 
        if(root==NULL){
            pair<bool,int> p = {true,0};
            return p;
        }
        
        if(root->left==NULL and root->right==NULL){
            pair<bool,int> p = {true,root->data};
            return p;
        }
        
        pair<bool,int> left = isSumFast(root->left);
        pair<bool,int> right = isSumFast(root->right);
        
        bool ltAns = left.first;
        bool rtAns = right.first;
        
        bool cond = root->data == left.second + right.second;
        
        pair<bool,int> ans;
        ans.second = root->data + left.second + right.second;
        
        if(ltAns and rtAns and cond){
            ans.first = true;
        }
        else{
            ans.first = false;
        }
        
        return ans;
    }
    
    bool isSumTree(Node* root) {
        
        return isSumFast(root).first;
    }
};
class Solution {
public:

    void traverseLt(Node* root, vector<int> &ans){
        //base case 
        if(root==NULL){
            return;
        }
        
        if(root->left==NULL and root->right==NULL){
            return;
        }
        
        
        ans.push_back(root->data);
        if(root->left)
            traverseLt(root->left, ans);
        else
            traverseLt(root->right, ans);
    }
    
    void traverseRt(Node* root, vector<int> &ans){
        //base case 
        if(root==NULL){
            return;
        }
        
        if(root->left==NULL and root->right==NULL){
            return;
        }
        
        
        if(root->right)
            traverseRt(root->right, ans);
        else
            traverseRt(root->left, ans);
        
        ans.push_back(root->data);
    }
    
    void traverseLeaf(Node* root, vector<int> &ans){
        //base case
        if(root==NULL){
            return;
        }
        
        //storing leaf nodes
        if(root->left==NULL and root->right==NULL){
            ans.push_back(root->data);
        }
        
        
        traverseLeaf(root->left, ans);
        traverseLeaf(root->right, ans);
    }
    
    
    vector <int> boundary(Node *root)
    {
        vector<int> ans;
        
        //base case 
        if(root==NULL){
            return ans;
        }
        
        ans.push_back(root->data);
        
        //traverse left
        traverseLt(root->left, ans);
        
        //traverse Leaf nodes
        traverseLeaf(root->left, ans);
        traverseLeaf(root->right, ans);
        
        //traverse Right (reverse direction)
        traverseRt(root->right, ans);
        
        
        return ans;
    }
};
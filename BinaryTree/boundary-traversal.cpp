class Solution {
public:
    void traverseLt(Node* root, vector<int> &ans){
        //base cases
        if(root==NULL or (root->left==NULL and root->right==NULL)){
            return;
        }
        
        ans.push_back(root->data);
        
        if(root->left){
            traverseLt(root->left, ans);
        }
        else{
            traverseLt(root->right, ans);
        }
    }
    
    
    void traverseLeaf(Node* root, vector<int> &ans){
        if(root==NULL){
            return;
        }
        
        if(root->left==NULL and root->right==NULL){
            ans.push_back(root->data);
        }
        
        traverseLeaf(root->left, ans);
        traverseLeaf(root->right, ans);
    }
    
    void traverseRt(Node* root, vector<int> &ans){
        
        //base cases
        if(root==NULL or (root->left==NULL and root->right==NULL)){
            return;
        }
        
        
        if(root->right){
            traverseRt(root->right, ans);
        }
        else{
            traverseRt(root->left, ans);
        }
        
        ans.push_back(root->data); //moving back towards the root node
    }
    
    vector <int> boundary(Node *root)
    {
        vector<int> ans;
        if(root==NULL){
            return ans;
        }
        
        ans.push_back(root->data);
        
        //left part
        traverseLt(root->left, ans);
        
        //Leaf nodes
        traverseLeaf(root->left, ans); //Call Left subtree
        traverseLeaf(root->right, ans); //Call Right subtree
        
        //right part
        traverseRt(root->right, ans);
        
        return ans;
    }
};

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root==NULL){
            return "";
        }        

        string s = "";
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            TreeNode* topNode = q.front();
            q.pop();

            if(topNode==NULL){
                s.append("#,");
            }
            else{
                s.append(to_string(topNode->val)+',');
            }
            if(topNode!=NULL){
                q.push(topNode->left);
                q.push(topNode->right);
            }
        }

        cout<<s;
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size()==0){
            return NULL;
        }

        stringstream s(data);
        string str;
        getline(s,str,',');
        TreeNode* root = new TreeNode(stoi(str));
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            TreeNode* topNode = q.front();
            q.pop();

            //for left 
            getline(s, str, ',');
            if(str=="#"){
                topNode->left = NULL;
            }
            else{
                TreeNode* ltNode = new TreeNode(stoi(str));
                topNode->left = ltNode;
                q.push(ltNode);
            }
            
            //for right
            getline(s, str, ',');
            if(str=="#"){
                topNode->right=NULL;
            }
            else{
                TreeNode* rtNode = new TreeNode(stoi(str));
                topNode->right=rtNode;
                q.push(rtNode);
            }

        }

        return root;
    }
};


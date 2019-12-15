#include"iostream"
#include"vector"
#include"stack"

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution{
    vector<int> inorderTraversalRec(TreeNode* root){
        vector<int> res;
        inorder(root,res);
        return res;
    }
    void inorder(TreeNode* root, vector<int> &res){
        if(!root) return ;
        if(root->left) inorder(root->left,res);
        res.push_back(root->val);
        if(root->right) inorder(root->right,res);
    }

    vector<int> inorderTraversalIte(TreeNode* root){
        vector<int> res;
        TreeNode *p=root;
        stack<TreeNode*> st;
        while(p||!st.empty())
        {
            while(p)
            {
                st.push(p);
                p=p->left;
            }
            p=st.top();
            st.pop();
            res.push_back(p->val);
            p=p->right;
        }
        return res;
    }
}; 
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
class Solution {
public:
/*递归版*/
    vector<int> postorderTraversalRec(TreeNode* root) {
        vector<int> res;
        postorder(root,res);
        return res;
    }
    void postorder(TreeNode* root, vector<int> &res){
        if(!root) return;
        if(root->left) postorder(root->left, res);
        if(root->right) postorder(root->right, res);
        res.push_back(root->val);
    }
/*迭代版*/
    vector<int> postorderTraversalIte(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> st;
        TreeNode* p=root;
        while(p||!st.empty())
        {
            if(p)
            {
                st.push(p);
                res.insert(res.begin(),p->val);
                p=p->right;
            }else{
                TreeNode* t=st.top();st.pop();
                p=t->left;
            }
        }
        
        return res;
    }
};
#include"iostream"
#include"vector"
#include"queue"

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
/*先序遍历*/
/*迭代法
*/
class SolutionPre{
public:
    vector<int> preorderTraversalIte(TreeNode* root)
    {
        vector<int> res;
        stack<TreeNode*> st;
        TreeNode* p=root;
        while(p||!st.empty())
        {
            if(p)
            {
                st.push(p);
                res.push_back(p->val);
                p=p->left;
            }else{
                TreeNode* t=st.top();st.pop();
                p=t->right;
            }
        }
        return res;
    }
    /*递归法*/

    vector<int> preorderTraversalRec(TreeNode* root)
    {
        vector<int> res;
        preorder(root,res);
        return res;
    }
    void preorder(TreeNode* root,vector<int> &res)
    {
        if(!root) return;
        res.push_back(root->val);
        if(root->left) root=root->left;
        if(root->right) root=root->right;
    }
}
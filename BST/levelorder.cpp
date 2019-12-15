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
/*层次遍历
关键在于建立了一个queue，初始化时将根节点存入，然后建立一个单层的vector，保存每一层的val；
保存时，取出当前queue的头部，将其值放入，然后检查其左右节点，存入queue；
如此遍历，直到其q为空；
*/
class Solutionlevel{
public:
    vector<vector<int>> levelOrder(TreeNode* root){
        if(!root) return{};
        vector<vector<int>> res;
        queue<TreeNode*> q{{root}};
        while(!q.empty())
        {   
            vector<int> OneLevel;
            for(int i=q.size();i>0;--i)
            {
                TreeNode* t=q.front();q.pop();
                OneLevel.push_back(t->val);
                if(t->left) q.push(t->left);
                if(t->right) q.push(t->right);   
            }
            res.push_back(OneLevel);
        }
        return res;
    }
};

/*Z字形层次遍历
与普通层次遍历的区别在于设立一个cnt计数，每到奇数行保存单行时使用vector的insert（begin，val）
*/
class SolutionZigZagLevel {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root) return{};
        vector<vector<int>> res;
        queue<TreeNode*> q{{root}};
        int cnt=0;
        while(!q.empty())
        {
            vector<int> OneLevel;
            for(int i=q.size();i>0;--i)
            {
                TreeNode* p=q.front();q.pop();
                if(cnt%2==0)
                    OneLevel.push_back(p->val);
                else
                    OneLevel.insert(OneLevel.begin(),p->val);
                if(p->left) q.push(p->left);
                if(p->right) q.push(p->right);
            }
            ++cnt;
            res.push_back(OneLevel);
        }
        return res;
    }
};
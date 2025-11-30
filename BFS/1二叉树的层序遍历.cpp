//二叉树的层序遍历
#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
int val;
TreeNode *left;
TreeNode *right;
TreeNode() : val(0), left(nullptr), right(nullptr) {}
TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    public:
        vector<vector<int>> levelOrder(TreeNode* root) {
            if(!root) return {};
            queue<TreeNode*> q;
            q.push(root);
            vector<vector<int>> res;
            while(!q.empty()){
                //每次循环一层，记录好每层数量，添加结果层
                int size = q.size();
                res.push_back(vector<int>());

                for(int i = 0; i < size; i++){
                    //取出一个节点，添加并出栈
                    TreeNode* node = q.front();
                    q.pop();
                    res.back().push_back(node->val);
                    //将左右子节点入栈
                    if(node->left) q.push(node->left);
                    if(node->right) q.push(node->right);
                }
            }
            return res;
        }
};

//锯齿形层序遍历 。（即先从左往右，再从右往左进行下一层遍历，以此类推，层与层之间交替进行）。
//if(res.size() % 2) reverse(vals.begin(),vals.end());
//只改变输出

//给定一个二叉树的 根节点 root，请找出该二叉树的 最底层 最左边 节点的值。
//if(i == 0) ans = node->val;
//或者先右后左最后一个就是最左边的
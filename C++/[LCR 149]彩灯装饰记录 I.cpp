//一棵圣诞树记作根节点为 root 的二叉树，节点值为该位置装饰彩灯的颜色编号。请按照从 左 到 右 的顺序返回每一层彩灯编号。 
//
// 
//
// 示例 1： 
//
// 
//
// 
//输入：root = [8,17,21,18,null,null,6]
//输出：[8,17,21,18,6]
// 
//
// 
//
// 提示： 
//
// 
// 节点总数 <= 1000 
// 
//
// 
//
// Related Topics 树 广度优先搜索 二叉树 👍 311 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> decorateRecord(TreeNode* root) {    //中序遍历法
    vector<int> res;
    queue<TreeNode*> q;    //TreeNode*这个结构体，也是一种类型
    if (root != NULL) q.push(root);
    while(!q.empty()) {    /* 开始层序遍历 */
    for(int i = 0; i < q.size(); i++){
      TreeNode* node = q.front();
      res.push_back(node->val);
      if(node->left!=NULL) q.push(node->left);
      if(node->right!=NULL) q.push(node->right);
      q.pop();
    }
    }
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */


class Solution {
public:
    vector<int> decorateRecord(TreeNode* root) {
        /* 根据函数返回值定义存储结果的变量 */
        vector<int> res;
        /* 定义一个队列用于存储节点的数据 */
        queue<TreeNode*> que;    //TreeNode*这个结构体，也是一种类型
        /* 判空 */
        if(root != NULL)
          que.push(root);

        /* 开始层序遍历 */
        while(!que.empty()) {
            /* 计算队列的大小也即有多少个孩子 */
            int size = que.size();
            /* 层序遍历 */
            for(int i = 0; i < size; i++) {
                /* 获取第一个节点数据 */
                TreeNode* node = que.front();
                que.pop();

                res.push_back(node->val);
                if(node->left != NULL) que.push(node->left);
                if(node->right != NULL) que.push(node->right);

            }
        }
        return res;
    }
};
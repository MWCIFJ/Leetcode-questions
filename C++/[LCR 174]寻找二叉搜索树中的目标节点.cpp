//某公司组织架构以二叉搜索树形式记录，节点值为处于该职位的员工编号。请返回第 cnt 大的员工编号。 
//
// 
//
// 示例 1： 
//
// 
//
// 
//输入：root = [7, 3, 9, 1, 5], cnt = 2
//       7
//      / \
//     3   9
//    / \
//   1   5
//输出：7
// 
//
// 示例 2： 
//
// 
//
// 
//输入: root = [10, 5, 15, 2, 7, null, 20, 1, null, 6, 8], cnt = 4
//       10
//      / \
//     5   15
//    / \    \
//   2   7    20
//  /   / \ 
// 1   6   8
//输出: 8 
//
// 
//
// 提示： 
//
// 
// 1 ≤ cnt ≤ 二叉搜索树元素个数 
// 
//
// 
//
// Related Topics 树 深度优先搜索 二叉搜索树 二叉树 👍 423 👎 0


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
  int findTargetNode(TreeNode* root, int cnt) {
    dfs(root); // 填充dp向量
      return dp[dp.size()-cnt]; // 确保cnt在有效范围内
  }
private:
  TreeNode *head = nullptr, *pre = nullptr;
  vector<int> dp;
  void dfs(TreeNode* cur) {
    if (cur == nullptr)
      return;
    dfs(cur->left); // 先访问左子树
    dp.push_back(cur->val); // 将当前节点的值添加到dp中
    dfs(cur->right); // 再访问右子树
  }//二叉搜索树是面对中序遍历时，会排序的特定树型
};
//leetcode submit region end(Prohibit modification and deletion)

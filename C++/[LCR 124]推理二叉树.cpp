//某二叉树的先序遍历结果记录于整数数组 preorder，它的中序遍历结果记录于整数数组 inorder。请根据 preorder 和 inorder 的提示
//构造出这棵二叉树并返回其根节点。 
//
// 
//
// 注意：preorder 和 inorder 中均不含重复数字。 
//
// 
//
// 示例 1： 
//
// 
//
// 
//输入: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
//
//输出: [3,9,20,null,null,15,7]
// 
//
// 
//
// 示例 2: 
//
// 
//输入: preorder = [-1], inorder = [-1]
//
//输出: [-1]
// 
//
// 
//
// 提示: 
//
// 
// 1 <= preorder.length <= 3000 
// inorder.length == preorder.length 
// -3000 <= preorder[i], inorder[i] <= 3000 
// inorder 均出现在 preorder 
// preorder 保证 为二叉树的前序遍历序列 
// inorder 保证 为二叉树的中序遍历序列 
// 
//
// 
//
// 注意：本题与主站 105 题重复：https://leetcode-cn.com/problems/construct-binary-tree-from-
//preorder-and-inorder-traversal/ 
//
// 
//
// Related Topics 树 数组 哈希表 分治 二叉树 👍 1146 👎 0


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
    TreeNode* deduceTree(vector<int>& preorder, vector<int>& inorder) {
        
    }
};
//leetcode submit region end(Prohibit modification and deletion)

//给定两棵二叉树 tree1 和 tree2，判断 tree2 是否以 tree1 的某个节点为根的子树具有 相同的结构和节点值 。 注意，空树 不会是以 
//tree1 的某个节点为根的子树具有 相同的结构和节点值 。 
//
// 
//
// 示例 1： 
//
// 
//
// 
//
// 
//
// 
//输入：tree1 = [1,7,5], tree2 = [6,1]
//输出：false
//解释：tree2 与 tree1 的一个子树没有相同的结构和节点值。
// 
//
// 示例 2： 
//
// 
//
// 
//输入：tree1 = [3,6,7,1,8], tree2 = [6,1]
//输出：true
//解释：tree2 与 tree1 的一个子树拥有相同的结构和节点值。即 6 - > 1。 
//
// 
//
// 提示： 
//
// 0 <= 节点个数 <= 10000 
//
// Related Topics 树 深度优先搜索 二叉树 👍 821 👎 0


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
    bool isSubStructure(TreeNode* A, TreeNode* B) {
    if (A == NULL || B == NULL) return false;
    return isSame(A,B) || isSubStructure(A->left,B) || isSubStructure(A->right,B);
    }
    bool isSame(TreeNode* A, TreeNode* B) {
    if (B == NULL) return true;
    if (A == NULL && B != NULL) return false;
    if (A->val != B->val) return false;
    return isSame(A->left,B->left) && isSame(A->right,B->right);
    }
};
//leetcode submit region end(Prohibit modification and deletion)

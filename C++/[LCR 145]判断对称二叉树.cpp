//请设计一个函数判断一棵二叉树是否 轴对称 。 
//
// 
//
// 示例 1： 
//
// 
//
// 
//输入：root = [6,7,7,8,9,9,8]
//输出：true
//解释：从图中可看出树是轴对称的。 
//
// 示例 2： 
//
// 
//
// 
//输入：root = [1,2,2,null,3,null,3]
//输出：false
//解释：从图中可看出最后一层的节点不对称。 
//
// 
//
// 提示： 
//
// 0 <= 节点个数 <= 1000 
//
// 注意：本题与主站 101 题相同：https://leetcode-cn.com/problems/symmetric-tree/ 
//
// 
//
// Related Topics 树 深度优先搜索 广度优先搜索 二叉树 👍 483 👎 0


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
    bool checkSymmetricTree(TreeNode* root) {
        return root == nullptr || recur(root->left, root->right);
    }
private:
    bool recur(TreeNode* L, TreeNode* R) {
      if(L == nullptr && R == nullptr) return true;
      if(L == nullptr || R == nullptr || L->val != R->val) return false;
//如果 L 或 R 中的任何一个为 nullptr，访问 L->val 或 R->val 将导致运行时错误，因为你在尝试通过空指针访问成员变量。
//所以LR的空指针判断必须置前
      return recur(L->left,R->right) && recur(L->right,R->left);
//执行下来是前序遍历，但一个是先遍历左子树，后遍历右子树；另一个是先遍历右子树，后遍历左子树。
    }
};
//leetcode submit region end(Prohibit modification and deletion)

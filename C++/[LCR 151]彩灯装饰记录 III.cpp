//一棵圣诞树记作根节点为 root 的二叉树，节点值为该位置装饰彩灯的颜色编号。请按照如下规则记录彩灯装饰结果： 
//
// 
// 第一层按照从左到右的顺序记录 
// 除第一层外每一层的记录顺序均与上一层相反。即第一层为从左到右，第二层为从右到左。 
// 
//
// 
//
// 示例 1： 
//
// 
//
// 
//输入：root = [8,17,21,18,null,null,6]
//输出：[[8],[21,17],[18,6]]
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
// Related Topics 树 广度优先搜索 二叉树 👍 315 👎 0


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
    vector<vector<int>> decorateRecord(TreeNode* root) {
    vector<vector<int>> res;
    deque<TreeNode*> q;
    bool leftToRight = true;
    if(root != NULL)
      q.push_back(root);
    while(!q.empty()) {
      int size = q.size();
      res.push_back(vector<int>());  //添加一个新的空向量
      for(int i = 0;i < size;i++)
      {
        TreeNode* node = NULL;
        if(leftToRight)  //行
          {
          node = q.front();
          q.pop_front();
          //res.back().push_back(node->val);  //二维化
          if(node->left != NULL) q.push_back(node->left);
          if(node->right != NULL) q.push_back(node->right);
          }else{
          node = q.back();
          q.pop_back();
          //res.back().push_back(node->val);  //二维化
//现在先添加 node->right 再添加 node->left 到队列的前端。这样，在偶数层时，子节点将会按照从右到左的顺序被遍历。
          if(node->right != NULL) q.push_front(node->right);
          if(node->left != NULL) q.push_front(node->left);
          }
          res.back().push_back(node->val);  //二维化，将当前节点的值添加到 res 中，与left与right无关
      }
      leftToRight = !leftToRight;
    }
    return res;
  }
};
//leetcode submit region end(Prohibit modification and deletion)

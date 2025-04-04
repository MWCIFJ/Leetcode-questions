//给定两个整数数组 preorder 和 inorder ，其中 preorder 是二叉树的先序遍历， inorder 是同一棵树的中序遍历，请构造二叉树并
//返回其根节点。 
//
// 
//
// 示例 1: 
// 
// 
//输入: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
//输出: [3,9,20,null,null,15,7]
// 
//
// 示例 2: 
//
// 
//输入: preorder = [-1], inorder = [-1]
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
// preorder 和 inorder 均 无重复 元素 
// inorder 均出现在 preorder 
// preorder 保证 为二叉树的前序遍历序列 
// inorder 保证 为二叉树的中序遍历序列 
// 
//
// Related Topics 树 数组 哈希表 分治 二叉树 👍 2480 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/*l1: 前序遍历数组的起始索引。
r1: 前序遍历数组的结束索引。
l2: 中序遍历数组的起始索引。
r2: 中序遍历数组的结束索引。*/
struct TreeNode* build(int *preorder, int l1, int r1, int *inorder, int l2, int r2) {//递归构建二叉树
    int i, llen, rlen;
    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));// 分配内存并初始化根节点
    root->val = preorder[l1]; // 根节点的值为前序遍历的第一个元素，之后做好根-左-右即可
    for (i = l2; i < r2 && inorder[i] != root->val; i++);/* 找到根节点在中序序列的位置i */
    llen = i - l2;// 计算左子树的长度
    rlen = r2 - i;// 计算右子树的长度
    if (llen)/* 构造左子树 */
        root->left = build(preorder, l1 + 1, l1 + llen, inorder, l2, l2 + llen - 1);
    //左子树的开始索引l1是：表示从前序遍历中取出l1 + 1个元素作为左子树开始端，也就会逐渐增加以向左。
    //左子树的结束索引r1是：表示从前序遍历中取出l1 + llen个元素作为左子树结束端，也就是树的根的左后右位置。
    //左子树的结束索引r2是：表示从中序遍历中取出l2 + llen - 1个元素作为左子树结束端，也就是根的左后右位置。
    //而每递归一次，l1,r1,l2,r2[都会变]，且数值会是下一次递归的初始值
    //但是无论左右子树还是前序中序，l1到r1的长度肯定与l2到r2的长度相同
    //就是递归时建立的点同时符合前序遍历的第几值和中序遍历的第几值
    else
        root->left = NULL;

    if (rlen)/* 构造右子树 */
        root->right = build(preorder, r1 - rlen + 1, r1, inorder, r2 - rlen + 1, r2);
    //右子树的开始索引l1是：表示从前序遍历中取出r1 - rlen + 1个元素作为右子树，也就是根的右1位置。
    //右子树的开始索引l2是：表示从中序遍历中取出r2 - rlen + 1个元素作为右子树，也就是根的右1位置。
    else
        root->right = NULL;

    return root; // 返回构建好的子树的根节点
}


struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize) {//构建二叉树
    if (preorderSize == 0 || inorderSize == 0)
        return NULL; // 如果前序或中序遍历为空，返回空指针
    return build(preorder, 0, preorderSize - 1, inorder, 0, inorderSize - 1); // 调用辅助函数进行构建
}

//leetcode submit region end(Prohibit modification and deletion)

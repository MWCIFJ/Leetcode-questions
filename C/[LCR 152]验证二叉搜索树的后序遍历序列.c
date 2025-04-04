//请实现一个函数来判断整数数组 postorder 是否为二叉搜索树的后序遍历结果。 
//
// 
//
// 示例 1： 
//
// 
//
// 
//输入: postorder = [4,9,6,5,8]
//输出: false 
//解释：从上图可以看出这不是一颗二叉搜索树
// 
//
// 示例 2： 
//
// 
//
// 
//输入: postorder = [4,6,5,9,8]
//输出: true 
//解释：可构建的二叉搜索树如上图
// 
//
// 
//
// 提示： 
//
// 
// 数组长度 <= 1000 
// postorder 中无重复数字 
// 
//
// 
//
// Related Topics 栈 树 二叉搜索树 递归 数组 二叉树 单调栈 👍 784 👎 0


//leetcode submit region begin(Prohibit modification and deletion)

bool recur(int* postorder, int i, int j) {
    if (i >= j) return true;// 如果子数组只有一个元素或为空，则认为是有效的后序遍历
    int p = i;
    while (postorder[p] < postorder[j]) p++;// 找到左子树的所有节点
    int m = p;// m记录左子树的结束位置
    while (postorder[p] > postorder[j]) p++;// 确保右子树的所有节点都大于根节点
    return(p == j && recur(postorder,i,m-1) && recur(postorder,m,j-1));
    // p == j: 确保从 m 到 j-1 的所有节点都大于根节点 postorder[j]。其余的是递归验证左右子树都是有效的后序遍历
}
bool verifyTreeOrder(int* postorder, int postorderSize) {
    return recur(postorder, 0, postorderSize - 1);    //毕竟是postorderSize个
}
//leetcode submit region end(Prohibit modification and deletion)
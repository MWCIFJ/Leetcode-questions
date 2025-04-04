//给你二叉树的根节点 root 和一个整数目标和 targetSum ，找出所有 从根节点到叶子节点 路径总和等于给定目标和的路径。 
//
// 叶子节点 是指没有子节点的节点。 
//
// 
// 
// 
// 
// 
//
// 示例 1： 
// 
// 
//输入：root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
//输出：[[5,4,11,2],[5,8,4,5]]
// 
//
// 示例 2： 
// 
// 
//输入：root = [1,2,3], targetSum = 5
//输出：[]
// 
//
// 示例 3： 
//
// 
//输入：root = [1,2], targetSum = 0
//输出：[]
// 
//
// 
//
// 提示： 
//
// 
// 树中节点总数在范围 [0, 5000] 内 
// -1000 <= Node.val <= 1000 
// -1000 <= targetSum <= 1000 
// 
//
// Related Topics 树 深度优先搜索 回溯 二叉树 👍 1170 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
void dfs(struct TreeNode* root, int targetSum, int* returnSize,
         int** returnColumnSizes,int **returnNums,int *stack,int top,int sum){
/*    returnNums 是一个指针数组，用于存储所有符合条件的路径。
      *returnSize 是当前找到的路径数量
      *returnColumnSizes 是一个指针，指向*returnSize，*returnSize存储每条路径的长度。*/
    if(root == NULL)
        return;
    sum += root->val;
    stack[top] = root->val;    //*stack就是暗示是数组
    if(root->left == NULL && root->right == NULL)    //当前节点是叶子结点
    {
        if(sum == targetSum)
        {
            returnNums[*returnSize] = (int *)malloc(sizeof(int) * (top + 1));//申请空间，第几路
            memcpy(returnNums[*returnSize] , stack, sizeof(int) * (top + 1));//第几路写进去路径各值
            (*returnColumnSizes)[*returnSize] = top + 1;//更新存储每条路径长度的数组，确保每条路径的长度被正确记录。
//()的作用是先解引用，不加()的话是先将指针值作为数组的索引，而加了()的话就是先解引成指针，再把这个指针作为数组索引。
//本质上就是()让*的区域变窄
//当了数组的头，肯定是要少去一个*，因为数组头已经是具备一个指针了。
            (*returnSize)++;    //寻得路径+1
        }
    }
    dfs(root->left,targetSum,returnSize,returnColumnSizes,returnNums,stack,top+1,sum);//遍历左子树
    dfs(root->right,targetSum,returnSize,returnColumnSizes,returnNums,stack,top+1,sum);//遍历右子树
}
int** pathSum(struct TreeNode* root, int targetSum, int* returnSize, int** returnColumnSizes) {
    int **returnNums = (int **)malloc(sizeof(int*) * 50000);//双重指针的模板
    *returnColumnSizes = (int *)malloc(sizeof(int) * 50000);//指针的模板
    *returnSize = 0;
    int stack[5000] = {0};
    dfs(root,targetSum,returnSize,returnColumnSizes,returnNums,stack,0,0);//只有后三才是新参数
    return returnNums;
}
//这个不够好，不要再看了
//leetcode submit region end(Prohibit modification and deletion)

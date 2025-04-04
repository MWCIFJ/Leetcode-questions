//在股票交易中，如果前一天的股价高于后一天的股价，则可以认为存在一个「交易逆序对」。请设计一个程序，输入一段时间内的股票交易记录 record，返回其中存在的
//「交易逆序对」总数。 
//
// 
//
// 示例 1： 
//
// 
//输入：record = [9, 7, 5, 4, 6]
//输出：8
//解释：交易中的逆序对为 (9, 7), (9, 5), (9, 4), (9, 6), (7, 5), (7, 4), (7, 6), (5, 4)。
// 
//
// 
//
// 提示： 
//
// 0 <= record.length <= 50000 
//
// Related Topics 树状数组 线段树 数组 二分查找 分治 有序集合 归并排序 👍 1125 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
int mergeSort(int l, int r, int *nums, int *tmp)
{
    if (l >= r)
        return 0;
    // 递归划分至单
    int m = (l + r) / 2;
    int res = mergeSort(l, m, nums, tmp) + mergeSort(m + 1, r, nums, tmp);
    // 开始逐渐合并
    int i = l, j = m + 1;
    for (int k = l; k <= r; k++) // 注意k的边界 <=
    {
        tmp[k] = nums[k];
    }
    for (int k = l; k <= r; k++) // 注意k的边界 <=
    {
        if (i == m + 1)	//左子数组合并结束时，i由下方的i++来自增判断
        { //将右边剩余元素加入数组
            nums[k] = tmp[j++];
        }
        else if (j == r + 1 || tmp[i] <= tmp[j])//右边数组合并结束时或右边>左边
        { //将元素加入结果数组
            nums[k] = tmp[i++];
        }
        else
        { //左边元素>右边元素，此时将贡献逆序对
            nums[k] = tmp[j++];
            res += m - i + 1;
            //每个左子数组中的剩余元素与刚刚从右子数组中取出的元素都构成一个逆序对,逆序对的数量就是左子数组剩余元素的数量，即m-i+1。
        }
    }
    return res;
}
int reversePairs(int *nums, int numsSize)
{
	int *tmp = (int*)malloc(sizeof(int) * numsSize);
    return mergeSort(0, numsSize - 1,nums,tmp);
}
//leetcode submit region end(Prohibit modification and deletion)
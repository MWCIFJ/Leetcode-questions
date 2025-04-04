//某店铺将用于组成套餐的商品记作字符串 goods，其中 goods[i] 表示对应商品。请返回该套餐内所含商品的 全部排列方式 。 
//
// 返回结果 无顺序要求，但不能含有重复的元素。 
//
// 
//
// 示例 1： 
//
// 
//输入：goods = "agew"
//输出：["aegw","aewg","agew","agwe","aweg","awge","eagw","eawg","egaw","egwa",
//"ewag","ewga","gaew","gawe","geaw","gewa","gwae","gwea","waeg","wage","weag","wega",
//"wgae","wgea"]
// 
//
// 
//
// 提示： 
//
// 
// 1 <= goods.length <= 8 
// 
//
// 
//
// Related Topics 字符串 回溯 👍 729 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** goodsOrder(char* goods, int* returnSize) {
    Source = goods;
    Source_Size = strlen(goods);

    Result = (char**)malloc(sizeof(char*) * 20160);
    Result_Index = 0;

    Path = (char*)malloc(sizeof(char) * Source_Size);
    Path_Index = 0;

    Used = (bool*)malloc(sizeof(bool) * Source_Size);
    for(int i = 0; i < Source_Size; i++){
        Used[i] = false;
    }
    qsort(goods, Source_Size, sizeof(char), cmp);
    Back_Track();
    *returnSize = Result_Index;
    return Result;
}
//leetcode submit region end(Prohibit modification and deletion)

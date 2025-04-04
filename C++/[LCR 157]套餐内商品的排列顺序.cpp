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
class Solution {
public:
    vector<string> goodsOrder(string goods) {
        vector<string> res;
        dfs(goods, res, 0);    //初始的depth为0
        return res;
    }

    void dfs(string &s, vector<string> &res, int depth)
    {
        if(depth >= s.size()-1)    // 如果当前深度达到字符串长度减1，就是已经到达字符串的最后一个字符
        {
            res.push_back(s);       // 将当前排列的字符串添加到结果向量中,无论是直添还是结束递归，这样都是少些开销与设立终止条件
            return;                 // 结束当前递归调用
        }
        unordered_set<char> used;  // 创建一个unordered_set来存储已经使用过的字符，用于去重
        for(int i = depth; i < s.size(); ++i) // 从当前深度开始遍历字符串的剩余部分
        {
            if(used.find(s[i]) != used.end())  // 这是函数特性，背下来就行
/*used.find(s[i]) 尝试在集合 used 中查找字符 s[i]。
如果找到了该字符，则返回一个指向该字符的迭代器；如果没有找到，则返回 used.end()。
因此，通过比较 used.find(s[i]) 和 used.end()，可以判断字符 s[i] 是否存在于集合 used 中。*/
                    continue;                        // 跳过当前字符，继续下一个字符
            used.insert(s[i]);                 // 将当前字符插入到used中，标记为已使用，不参与新排列中
            swap(s[depth],s[i]);               // 交换当前深度字符和遍历到的字符，生成新的排列，且因递归而遍历所有可能
            dfs(s, res, depth+1);             // 递归调用dfs，深度加1，继续生成下一个字符的排列
            swap(s[depth],s[i]);               // 回溯，撤销之前的所有交换操作，恢复字符串到交换前的状态
        }
    }
};
//leetcode submit region end(Prohibit modification and deletion)



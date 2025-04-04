//给定一个整数 n，计算所有小于等于 n 的非负整数中数字 1 出现的个数。 
//
// 
//
// 示例 1： 
//
// 
//输入：n = 13
//输出：6
// 
//
// 示例 2： 
//
// 
//输入：n = 0
//输出：0
// 
//
// 
//
// 提示： 
//
// 
// 0 <= n <= 10⁹ 
// 
//
// Related Topics 递归 数学 动态规划 👍 602 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int countDigitOne(int n) {
    int cnt = 0;
    for(long long m = 1; m <= n; m*=10) {
      long long d = m*10;
      cnt+=(n/d)*m+fmin(fmax(n%d-m+1,0),m);//前面是前面所有位出现1的次数，后面是当前位及其后面位出现1的次数
    }
    return cnt;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

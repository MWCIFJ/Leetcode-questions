//给你一个整数 n ，请你在无限的整数序列 [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ...] 中找出并返回第 n 位上的数字。
// 
//
// 
//
// 示例 1： 
//
// 
//输入：n = 3
//输出：3
// 
//
// 示例 2： 
//
// 
//输入：n = 11
//输出：0
//解释：第 11 位数字在序列 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ... 里是 0 ，它是 10 的一部分。
// 
//
// 
//
// 提示： 
//
// 
// 1 <= n <= 2³¹ - 1 
// 
//
// Related Topics 数学 二分查找 👍 424 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int findNthDigit(long long n) {
    int k = 1;
    while(k*pow(10,k) < n)//前面的k是每一个低位都要补k个0
      {
          n+=pow(10,k);//往前面元素的当前位都补上0，让n扫过的数字中，自动补上缺失的所有位0的数字
          k++;
      }
      return to_string(n/k)[n%k]-'0';//设n为15，则这里12[1]即为2，而'2' - '0'是转回整数值的意思
    }
};
//leetcode submit region end(Prohibit modification and deletion)
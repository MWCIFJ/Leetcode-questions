//给定一个正整数 n ，将其拆分为 k 个 正整数 的和（ k >= 2 ），并使这些整数的乘积最大化。 
//
// 返回 你可以获得的最大乘积 。 
//
// 
//
// 示例 1: 
//
// 
//输入: n = 2
//输出: 1
//解释: 2 = 1 + 1, 1 × 1 = 1。 
//
// 示例 2: 
//
// 
//输入: n = 10
//输出: 36
//解释: 10 = 3 + 3 + 4, 3 × 3 × 4 = 36。 
//
// 
//
// 提示: 
//
// 
// 2 <= n <= 58 
// 
//
// Related Topics 数学 动态规划 👍 1453 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n + 1);
        dp[2] = 1;//当 n≥2 时，可以拆分成至少两个正整数的和。所以d[2]固定为1
        for (int i = 3; i <= n ; i++)
            for (int j = 1; j < i - 1; j++) //j必须要留个1才能够乘
                dp[i] = max(dp[i], max((i - j) * j, dp[i - j] * j));//状态转移方程
        //将 i 拆分成 j 和 i−j 的和后，分两种情况： i−j 不再拆分成多个正整数 or  i−j 继续拆分成多个正整数
        return dp[n];
    }
};
//leetcode submit region end(Prohibit modification and deletion)

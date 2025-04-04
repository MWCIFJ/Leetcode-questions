//你选择掷出 num 个色子，请返回所有点数总和的概率。 
//
// 你需要用一个浮点数数组返回答案，其中第 i 个元素代表这 num 个骰子所能掷出的点数集合中第 i 小的那个的概率。 
//
// 
//
// 示例 1： 
//
// 
//输入：num = 3
//输出：[0.00463,0.01389,0.02778,0.04630,0.06944,0.09722,0.11574,0.12500,0.12500,0.
//11574,0.09722,0.06944,0.04630,0.02778,0.01389,0.00463]
// 
//
// 示例 2： 
//
// 
//输入：num = 5
//输出:[0.00013,0.00064,0.00193,0.00450,0.00900,0.01620,0.02636,0.03922,0.05401,0.
//06944,0.08372,0.09452,0.10031,0.10031,0.09452,0.08372,0.06944,0.05401,0.03922,0.
//02636,0.01620,0.00900,0.00450,0.00193,0.00064,0.00013]
// 
//
// 
//
// 提示： 
//
// 
// 1 <= num <= 11 
// 
//
// 
//
// Related Topics 数学 动态规划 概率与统计 👍 594 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<double> statisticsProbability(int num) {
		vector<double> res;
        vector<vector<int>> dp(num+1,vector<int>(6*num+1,0));	//num+1是为了让dp从1开始，方便计数
        for(int i = 1;i <= 6;i++)	// 初始化只有一个骰子的情况，点数和为1到6的次数都是1
          dp[1][i] = 1;
        for(int i = 2;i <= num;i++)	// 遍历从2个到num个骰子的情况
          for(int sum = i;sum <= 6*num;sum++)	// 遍历所有可能的点数和
            for(int k = 1;k <= 6;k++)	// 遍历一个骰子可能投掷出的点数
              if(sum-k>0)	// 这次投掷的骰子会存在这个点数的可能性
                dp[i][sum] += dp[i-1][sum-k];// 状态转移方程，累加得到当前点数和的次数
              else
                break;// 如果点数和减去当前骰子的点数小于等于0，则停止内层循环
        int probability = pow(6,num);
        for (int i = num; i <= 6*num; i++)
        	res.push_back((double)dp[num][i]/probability);	// 计算每个点数和的概率，并添加到结果数组中
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)




//现有一个记作二维矩阵 frame 的珠宝架，其中 frame[i][j] 为该位置珠宝的价值。拿取珠宝的规则为： 
//
// 
// 只能从架子的左上角开始拿珠宝 
// 每次可以移动到右侧或下侧的相邻位置 
// 到达珠宝架子的右下角时，停止拿取 
// 
//
// 注意：珠宝的价值都是大于 0 的。除非这个架子上没有任何珠宝，比如 frame = [[0]]。 
//
// 
//
// 示例 1： 
//
// 
//输入：frame = [[1,3,1],[1,5,1],[4,2,1]]
//输出：12
//解释：路径 1→3→5→2→1 可以拿到最高价值的珠宝 
//
// 
//
// 提示： 
//
// 
// 0 < frame.length <= 200 
// 0 < frame[0].length <= 200 
// 
//
// 
//
// Related Topics 数组 动态规划 矩阵 👍 551 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int jewelleryValue(vector<vector<int>>& frame) {//动态规划+贪心
        int m = frame.size(),n=frame[0].size(),f[2][n+1];
// f是一个二维数组，用于动态规划，所以是存储步骤的数组。2是向下和向右两种可能，n+1是检测边界
        memset(f,0,sizeof(f));
// 更新f数组，使用动态规划的方法
// max(f[(i + 1) % 2][j], f[i % 2][j + 1])表示从下方或右方到达当前位置的最大价值
// frame[i][j]是当前位置的珠宝价值
        for(int i=0;i<m;++i)
          for(int j=0;j<n;++j)
            f[(i+1)%2][j+1] = max(f[(i+1)%2][j],f[i%2][j+1])+frame[i][j];
        // 返回最大珠宝价值
        return f[m%2][n];
    }
};
//leetcode submit region end(Prohibit modification and deletion)

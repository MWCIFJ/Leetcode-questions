//家居整理师将待整理衣橱划分为 m x n 的二维矩阵 grid，其中 grid[i][j] 代表一个需要整理的格子。整理师自 grid[0][0] 开始 逐
//行逐列 地整理每个格子。 
//
// 整理规则为：在整理过程中，可以选择 向右移动一格 或 向下移动一格，但不能移动到衣柜之外。同时，不需要整理 digit(i) + digit(j) > 
//cnt 的格子，其中 digit(x) 表示数字 x 的各数位之和。 
//
// 请返回整理师 总共需要整理多少个格子。 
//
// 
//
// 示例 1： 
//
// 
//输入：m = 4, n = 7, cnt = 5
//输出：18
// 
//
// 
//
// 提示： 
//
// 
// 1 <= n, m <= 100 
// 0 <= cnt <= 20 
// 
//
// 
//
// Related Topics 深度优先搜索 广度优先搜索 动态规划 👍 686 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
// 回溯法，五维攻击
class Solution {
public:
    // wardrobeFinishing函数用于计算在m*n的衣柜中，可以完成装修的格子数
    // m和n分别代表衣柜的行数和列数，cnt代表每个格子装修所需的最大数字和
    int wardrobeFinishing(int m, int n, int cnt) {
        vector<vector<bool>> visited(m, vector<bool>(n, false));// 二维向量，用于记录每个格子是否已经被访问过
        /*(m, vector<bool>(n, false)): 这是向量的初始化部分。
        m: 外层向量的尺寸，表示网格的行数。
        vector<bool>(n, false): 内层向量的初始化，为每一行创建一个布尔向量。
        n: 内层向量的尺寸，表示网格的列数。
        false: [初始化]每个布尔元素的值，这里将所有单元格的访问状态初始化为 false，表示开始时没有任何单元格被访问过。
        这四个参数都是模板化的，直接背下来，后面眼熟即可。以后读出源码就不用背了*/
        return dfs(0, 0, m, n, cnt, visited);// 从左上角(0,0)开始进行深度优先搜索
        //在函数调用中，不需要显式写出&是因为在函数定义中已经指定了 visited 是通过引用传递的。
        //引用的话，函数调用时，只需提供变量名即可
    }
private:
    // dfs函数用于执行深度优先搜索
    // i和j代表当前格子的行号和列号，m和n代表衣柜的行数和列数
    // cnt代表每个格子装修所需的最大数字和，visited记录每个格子的访问状态
    int dfs(int i, int j, int m, int n, int cnt, vector<vector<bool>>& visited) {
        // 如果当前格子超出边界、格子的数字和大于cnt(这是题目特性，算是禁止区)、或者已经被访问过，则返回0
        //由此避免移动到衣柜外，利用if直接把边界外一律当0使就好
        if (i >= m || j >= n || i / 10 + i % 10 + j / 10 + j % 10 > cnt || visited[i][j])
            return false;
        visited[i][j] = true;    // 标记当前格子为已访问
        // 返回1（代表当前格子）+右侧格子的可装修数+下方格子的可装修数
        //将这三个部分相加，就是从当前格子开始，[同时]向右和向下探索的所有可能路径的数量，就是各自的可能性相叠加而已。
        return 1 + dfs(i + 1, j, m, n, cnt, visited) + dfs(i, j + 1, m, n, cnt, visited);
    }
};

//leetcode submit region end(Prohibit modification and deletion)

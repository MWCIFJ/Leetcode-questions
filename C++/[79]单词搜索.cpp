//给定一个 m x n 二维字符网格 board 和一个字符串单词 word 。如果 word 存在于网格中，返回 true ；否则，返回 false 。 
//
// 单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母不允许被重复使用。 
//
// 
//
// 示例 1： 
// 
// 
//输入：board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = 
//"ABCCED"
//输出：true
// 
//
// 示例 2： 
// 
// 
//输入：board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = 
//"SEE"
//输出：true
// 
//
// 示例 3： 
// 
// 
//输入：board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = 
//"ABCB"
//输出：false
// 
//
// 
//
// 提示： 
//
// 
// m == board.length 
// n = board[i].length 
// 1 <= m, n <= 6 
// 1 <= word.length <= 15 
// board 和 word 仅由大小写英文字母组成 
// 
//
// 
//
// 进阶：你可以使用搜索剪枝的技术来优化解决方案，使其在 board 更大的情况下可以更快解决问题？ 
//
// Related Topics 深度优先搜索 数组 字符串 回溯 矩阵 👍 1935 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
    static constexpr int DIRS[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    // DIRS是一个静态常量表达式数组，表示四个方向的移动：右、左、下、上

  public:
    bool exist(vector<vector<char>>& board, string word) {//exist函数用于判断单词word是否存在于二维字符数组board中
      int m = board.size(), n = board[0].size();

               //[capture list] (parameter list) -> return type { function body }
      auto dfs = [&](this auto&& dfs, int i, int j, int k) -> bool {
        // 定义一个lambda表达式dfs，用于深度优先搜索
        // this auto&& dfs允许lambda表达式递归调用自身
        // i和j是当前在board中的位置，k是当前在word中的字符索引
//[]的捕获列表可以为空，表示不访问任何外部变量，也可以使用默认捕获模式 & 或 = 来表示按“引用”或按“值”捕获所有外部变量
//外部变量就是整个程序的非此lambda表达式的所有变量
//auto&& dfs：它用于递归调用自身时保持类型安全。&&为左右值都可以引用，即可以递归。this为避免在捕获列表中捕获自身，从而简化代码。
/*Lambda表达式相比于普通函数和普通类，有以下几个优点：
简洁：Lambda表达式可以省略函数名和类名，直接定义和使用，使得代码更加简洁和清晰。
灵活：Lambda表达式可以捕获外部变量，可以作为函数参数，也可以作为函数返回值，使得代码更加灵活和方便。
安全：Lambda表达式可以控制外部变量的访问方式，可以避免全局变量的定义，可以避免悬空指针和无效引用的产生，使得代码更加安全和稳定。*/
        if (board[i][j] != word[k])  // 匹配失败
          return false;// 如果当前字符不匹配，返回false
        if (k + 1 == word.length())  // 匹配成功！
          return true;// 如果已经匹配到word的最后一个字符，返回最后一次的true
        board[i][j] = 0; // 标记访问过
        // 将当前字符标记为已访问，避免重复访问
        for (auto& [dx, dy] : DIRS) {  // 遍历四个方向
//[dx, dy]：这是结构化绑定的部分，它表示将容器中的每个元素（假设是一个结构体或元组）的成员绑定到 dx 和 dy 这两个变量上。
//:是范围推导运算符，用于指定要遍历的容器。
          int x = i + dx, y = j + dy; // 相邻格子
          if (0 <= x && x < m && 0 <= y && y < n && dfs(x, y, k + 1))
            // 如果相邻格子坐标有效且递归调用dfs成功，即全部都找到
            return true; // 这一次搜到了！
        }
        board[i][j] = word[k]; // 恢复当前字符，以便其他路径的搜索
        return false; // 如果所有路径都失败，返回false
      };

      for (int i = 0; i < m; i++)  //如果从某个位置开始成功找到单词，那么会立即返回true
        for (int j = 0; j < n; j++)
          if (dfs(i, j, 0)) // 如果从当前位置开始搜索成功
            return true; // 返回整体的true
      return false; // 如果所有起始位置都失败，返回整体的false
    }
  };

//leetcode submit region end(Prohibit modification and deletion)

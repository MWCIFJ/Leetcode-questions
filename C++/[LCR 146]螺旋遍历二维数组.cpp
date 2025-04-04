//给定一个二维数组 array，请返回「螺旋遍历」该数组的结果。 
//
// 螺旋遍历：从左上角开始，按照 向右、向下、向左、向上 的顺序 依次 提取元素，然后再进入内部一层重复相同的步骤，直到提取完所有元素。 
//
// 
//
// 示例 1： 
//
// 
//输入：array = [[1,2,3],[8,9,4],[7,6,5]]
//输出：[1,2,3,4,5,6,7,8,9]
// 
//
// 示例 2： 
//
// 
//输入：array  = [[1,2,3,4],[12,13,14,5],[11,16,15,6],[10,9,8,7]]
//输出：[1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16]
// 
//
// 
//
// 限制： 
//
// 
// 0 <= array.length <= 100 
// 0 <= array[i].length <= 100 
// 
//
// 注意：本题与主站 54 题相同：https://leetcode-cn.com/problems/spiral-matrix/ 
//
// 
//
// Related Topics 数组 矩阵 模拟 👍 608 👎 0


//leetcode submit region begin(Prohibit modification and deletion)

class Solution {
  #define INT_MAX 10000
    static constexpr int DIRS[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
public:
    vector<int> spiralArray(vector<vector<int>>& array) {
        if(array.empty()){
              return {};
          }
        int m = array.size(),n = array[0].size();
        vector<int> ans(m * n);
        int i = 0,j = 0,di = 0;
        for(int k = 0;k<m*n;k++){
           int x = i + DIRS[di][0];
           int y = j + DIRS[di][1];
           ans[k] = array[i][j];
           array[i][j] = INT_MAX;
           if(x<0 || x>=m || y<0 || y>=n || array[x][y] == INT_MAX){
             di = (di+1)%4;
             }
            i += DIRS[di][0];
            j += DIRS[di][1];
         }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)



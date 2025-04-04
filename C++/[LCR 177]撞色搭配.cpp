//整数数组 sockets 记录了一个袜子礼盒的颜色分布情况，其中 sockets[i] 表示该袜子的颜色编号。礼盒中除了一款撞色搭配的袜子，每种颜色的袜子均
//有两只。请设计一个程序，在时间复杂度 O(n)，空间复杂度O(1) 内找到这双撞色搭配袜子的两个颜色编号。 
//
// 
//
// 示例 1： 
//
// 
//输入：sockets = [4, 5, 2, 4, 6, 6]
//输出：[2,5] 或 [5,2]
// 
//
// 示例 2： 
//
// 
//输入：sockets = [1, 2, 4, 1, 4, 3, 12, 3]
//输出：[2,12] 或 [12,2] 
//
// 
//
// 提示： 
//
// 
// 2 <= sockets.length <= 10000 
// 
//
// Related Topics 位运算 数组 👍 889 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
	vector<int> sockCollocation(vector<int>& sockets) {
	int x = 0,y = 0,n = 0,m = 1;//n是xor后的数
        for(int num : sockets)//n = x^y
          n ^= num;
        while((n&m) == 0)//因为x与y是不同的数字，所以二进制至少有1位不同，而m的那一位就是不同的位数
          m<<=1;
		for(int num : sockets)//单入而得值，双入会抵消
          {
          	if(num & m)
              x ^= num;
            else
              y ^= num;
          }
    return vector<int>{x,y};
	}
};
//leetcode submit region end(Prohibit modification and deletion)

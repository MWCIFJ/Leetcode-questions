//教学过程中，教练示范一次，学员跟做三次。该过程被混乱剪辑后，记录于数组 actions，其中 actions[i] 表示做出该动作的人员编号。请返回教练的编
//号。 
//
// 
//
// 示例 1： 
//
// 
//输入：actions = [5, 7, 5, 5]
//输出：7
// 
//
// 示例 2： 
//
// 
//输入：actions = [12, 1, 6, 12, 6, 12, 6]
//输出：1
// 
//
// 
//
// 提示： 
//
// 
// 1 <= actions.length <= 10000 
// 1 <= actions[i] < 2^31 
// 
//
// Related Topics 位运算 数组 👍 479 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int trainingPlan(vector<int>& actions) {

    }
};
//leetcode submit region end(Prohibit modification and deletion)
class Solution {
public:
    int singleNumber(vector<int>& actions) {
        int res = 0;
        for (int i = 0, sub = 0; i < 32; ++i, sub = 0) {
            for (auto &n : actions)
              sub += ((n >> i) & 1);// 将数字n右移i位，然后与1进行按位与操作，得到唯一的第i位的值（0或1），累加到sub中。
            if (sub % 3)      // 如果sub的位数(结果值的第i位)对3取余不为0，说明只出现一次的数字在第i位上是1。
              res |= (1 << i);// 将res的第i位设置为1。
        }
        return res;
    }
};
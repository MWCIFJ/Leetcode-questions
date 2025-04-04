//请设计一个机械累加器，计算从 1、2... 一直累加到目标数值 target 的总和。注意这是一个只能进行加法操作的程序，不具备乘除、if-else、
//switch-case、for 循环、while 循环，及条件判断语句等高级功能。 
//
// 
//
// 示例 1： 
//
// 
//输入: target = 5
//输出: 15
// 
//
// 示例 2： 
//
// 
//输入: target = 7
//输出: 28
// 
//
// 
//
// 提示： 
//
// 
// 1 <= target <= 10000 
// 
//
// 
//
// Related Topics 位运算 递归 脑筋急转弯 👍 656 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int mechanicalAccumulator(int target) {
        bool arr[target][target+1];
        return sizeof(arr)>>1;
/*这里定义了一个二维布尔数组arr，其第一维的大小是target，第二维的大小是target + 1。
  由于布尔类型在大多数系统上占用1个字节，这个数组的总字节大小将是target * (target + 1)。
  sizeof(arr)会返回数组arr的总字节大小，即target * (target + 1)字节。
  >>1是对sizeof(arr)的结果进行右移一位的位运算，这相当于将大小除以2。*/
    }
};

//leetcode submit region end(Prohibit modification and deletion)

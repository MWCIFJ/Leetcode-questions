//给你一个整数数组 nums ，请你找出一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。 
//
// 子数组 是数组中的一个连续部分。 
//
// 
//
// 示例 1： 
//
// 
//输入：nums = [-2,1,-3,4,-1,2,1,-5,4]
//输出：6
//解释：连续子数组 [4,-1,2,1] 的和最大，为 6 。
// 
//
// 示例 2： 
//
// 
//输入：nums = [1]
//输出：1
// 
//
// 示例 3： 
//
// 
//输入：nums = [5,4,-1,7,8]
//输出：23
// 
//
// 
//
// 提示： 
//
// 
// 1 <= nums.length <= 10⁵ 
// -10⁴ <= nums[i] <= 10⁴ 
// 
//
// 
//
// 进阶：如果你已经实现复杂度为 O(n) 的解法，尝试使用更为精妙的 分治法 求解。 
//
// Related Topics 数组 分治 动态规划 👍 6948 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
int maxSubArray(int* nums, int numsSize) {
    int dp[numsSize] = {};
    dp[0] = nums[0];
    int result = dp[0];
    for(int i = 1;i<numsSize;i++){
    dp[i] = nums[i] > dp[i-1] + nums[i] ? nums[i] : dp[i-1] + nums[i];
//这样dp[i]都会储存了，而且max会让后一比前一dp大的时候直接从后一开始计dp
    result = result > dp[i] ? result : dp[i];
//result就是不断更新动态规划数组内最大值
    }
    return result;
}
//leetcode submit region end(Prohibit modification and deletion)
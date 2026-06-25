# 给你一个整数数组 nums 和一个整数 k ，请你统计并返回 该数组中和为 k 的子数组的个数 。 
# 
#  子数组是数组中元素的连续非空序列。 
# 
#  
# 
#  示例 1： 
# 
#  
# 输入：nums = [1,1,1], k = 2
# 输出：2
#  
# 
#  示例 2： 
# 
#  
# 输入：nums = [1,2,3], k = 3
# 输出：2
#  
# 
#  
# 
#  提示： 
# 
#  
#  1 <= nums.length <= 2 * 10⁴ 
#  -1000 <= nums[i] <= 1000 
#  -10⁷ <= k <= 10⁷ 
#  
# 
#  Related Topics 数组 哈希表 前缀和 👍 2846 👎 0


# leetcode submit region begin(Prohibit modification and deletion)
class Solution:
    def subarraySum(self,nums: List[int], k: int) -> int:
        count, cur_sum = 0, 0  # 初始化计数器count和当前前缀和cur_sum为0
        cache = {0: 1}  # 创建字典cache：key是前缀和，value是该前缀和出现的次数。初始{0:1}表示空数组前缀和为0出现1次
        for num in nums:  # 遍历数组中的每个数字
            cur_sum += num  # 更新当前前缀和（从数组开头到当前位置的元素和）
            count += cache.get(cur_sum - k, 0)  # 在字典中查找键 cur_sum - k
            # 如果存在(>=0)则+1。 如果不存在，返回默认值 0。
            cache[cur_sum] = cache.get(cur_sum, 0)+1  # 如果cur_sum已存在则+1，否则初始化为1
        return count  # 返回最终满足条件的子数组总数
#子数组 [i..j] 的和 = cur_sum[j] - cur_sum[i-1]。因为子数组是连续的，不用考虑断续情况
#我们需要 cur_sum[j] - cur_sum[i-1] = k。即 cur_sum[i-1] = cur_sum[j] - k
# leetcode submit region end(Prohibit modification and deletion)



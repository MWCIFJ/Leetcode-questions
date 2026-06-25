# 给你一个仅由整数组成的有序数组，其中每个元素都会出现两次，唯有一个数只会出现一次。 
# 
#  请你找出并返回只出现一次的那个数。 
# 
#  你设计的解决方案必须满足 O(log n) 时间复杂度和 O(1) 空间复杂度。 
# 
#  
# 
#  示例 1: 
# 
#  
# 输入: nums = [1,1,2,3,3,4,4,8,8]
# 输出: 2
#  
# 
#  示例 2: 
# 
#  
# 输入: nums =  [3,3,7,7,10,11,11]
# 输出: 10
#  
# 
#  
# 
#  
#  
# 
#  提示: 
# 
#  
#  1 <= nums.length <= 10⁵ 
#  0 <= nums[i] <= 10⁵ 
#  
# 
#  Related Topics 数组 二分查找 👍 744 👎 0


# leetcode submit region begin(Prohibit modification and deletion)
class Solution:
    def singleNonDuplicate(self, nums: List[int]) -> int:
        l, r = 0, len(nums) - 1
        while l < r:
            mid = (l + r) >> 1  # 计算中间索引，使用位运算符右移以避免溢出
            if nums[mid] != nums[mid ^ 1]:  # 检查中间元素是否与其对称位置的元素不同
                '''^1后得到相同时，则证明为前列偶数，则左边开始收缩。^1后不同则前列奇数，右边要收缩
                本质上是位运算符 ^ 1 将 mid 的最低位翻转。如果 mid 是偶数，那么
                mid ^ 1 将是 mid + 1；如果 mid 是奇数，那么 mid ^ 1 将是 mid - 1'''
                r = mid  # 如果不同，唯一的元素在mid及其左侧，因此将右指针移动到mid
            else:
                l = mid + 1  # 如果相同，唯一的元素在mid及其右侧，因此将左指针移动到mid+1
        return nums[l]  # 循环结束时，l应该等于r，且指向唯一的元素，返回这个元素
# leetcode submit region end(Prohibit modification and deletion)

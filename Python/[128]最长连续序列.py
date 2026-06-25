# 给定一个未排序的整数数组 nums ，找出数字连续的最长序列（不要求序列元素在原数组中连续）的长度。 
# 
#  请你设计并实现时间复杂度为 O(n) 的算法解决此问题。 
# 
#  
# 
#  示例 1： 
# 
#  
# 输入：nums = [100,4,200,1,3,2]
# 输出：4
# 解释：最长数字连续序列是 [1, 2, 3, 4]。它的长度为 4。 
# 
#  示例 2： 
# 
#  
# 输入：nums = [0,3,7,2,5,8,4,6,0,1]
# 输出：9
#  
# 
#  示例 3： 
# 
#  
# 输入：nums = [1,0,1,2]
# 输出：3
#  
# 
#  
# 
#  提示： 
# 
#  
#  0 <= nums.length <= 10⁵ 
#  -10⁹ <= nums[i] <= 10⁹ 
#  
# 
#  Related Topics 并查集 数组 哈希表 👍 2555 👎 0


# leetcode submit region begin(Prohibit modification and deletion)
class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        if not nums:
            return 0
        nums.sort()# 对列表进行升序排序，使连续的数字相邻
        res, cnt = 1, 1# 初始化结果变量res=1，初始化当前连续序列长度计数器cnt=1
        for i in range(1, len(nums)):# 从第二个元素开始遍历（索引1到末尾）
            if nums[i] == nums[i - 1] + 1:# 情况1：当前元素比前一个元素大1（连续递增）
                cnt += 1  # 当前连续序列长度+1
            elif nums[i] == nums[i - 1]:# 情况2：当前元素等于前一个元素（重复元素）
                continue  # 跳过重复元素，不改变cnt
            else:# 情况3：当前元素与前一个元素不连续且不相等
                cnt = 1  # 重置当前连续序列长度为1
            if cnt > res:# 更新最长连续序列长度
                res = cnt

        return res  # 返回最终结果
# leetcode submit region end(Prohibit modification and deletion)

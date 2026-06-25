# 给定一个循环数组 nums （ nums[nums.length - 1] 的下一个元素是 nums[0] ），返回 nums 中每个元素的 下一个更大元素
#  。 
# 
#  数字 x 的 下一个更大的元素 是按数组遍历顺序，这个数字之后的第一个比它更大的数，这意味着你应该循环地搜索它的下一个更大的数。如果不存在，则输出 -1 
# 。 
# 
#  
# 
#  示例 1: 
# 
#  
# 输入: nums = [1,2,1]
# 输出: [2,-1,2]
# 解释: 第一个 1 的下一个更大的数是 2；
# 数字 2 找不到下一个更大的数； 
# 第二个 1 的下一个最大的数需要循环搜索，结果也是 2。
#  
# 
#  示例 2: 
# 
#  
# 输入: nums = [1,2,3,4,3]
# 输出: [2,3,4,-1,4]
#  
# 
#  
# 
#  提示: 
# 
#  
#  1 <= nums.length <= 10⁴ 
#  -10⁹ <= nums[i] <= 10⁹ 
#  
# 
#  Related Topics 栈 数组 单调栈 👍 1062 👎 0


# leetcode submit region begin(Prohibit modification and deletion)
class Solution:
    def nextGreaterElements(self, nums: List[int]) -> List[int]:
        n = len(nums)
        res = [-1] * n  # 初始化为-1
        stack = []  # 单调栈存储索引
        for i in range(2 * n):  # 遍历两倍长度模拟循环数组，为的就是比最后一个值
            idx = i % n  # 实际索引，让第二遍的索引自动余成第一遍的样子
            while stack and nums[stack[-1]] < nums[idx]:  # 当栈非空，且当前元素大于栈顶元素
                res[stack.pop()] = nums[idx]  # 更新栈顶元素的下一个更大元素
            if i < n:  # 只在第一轮遍历时入栈，避免第二次遍历时重复再入
                stack.append(idx)
        return res
# leetcode submit region end(Prohibit modification and deletion)

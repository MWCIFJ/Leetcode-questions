# 给定一个包含红色、白色和蓝色、共 n 个元素的数组
#  nums ，原地 对它们进行排序，使得相同颜色的元素相邻，并按照红色、白色、蓝色顺序排列。 
# 
#  我们使用整数 0、 1 和 2 分别表示红色、白色和蓝色。 
# 
#  
#  
# 
#  必须在不使用库内置的 sort 函数的情况下解决这个问题。 
# 
#  
# 
#  示例 1： 
# 
#  
# 输入：nums = [2,0,2,1,1,0]
# 输出：[0,0,1,1,2,2]
#  
# 
#  示例 2： 
# 
#  
# 输入：nums = [2,0,1]
# 输出：[0,1,2]
#  
# 
#  
# 
#  提示： 
# 
#  
#  n == nums.length 
#  1 <= n <= 300 
#  nums[i] 为 0、1 或 2 
#  
# 
#  
# 
#  进阶： 
# 
#  
#  你能想出一个仅使用常数空间的一趟扫描算法吗？ 
#  
# 
#  Related Topics 数组 双指针 排序 👍 1946 👎 0


# leetcode submit region begin(Prohibit modification and deletion)
class Solution:
    def sortColors(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
# 初始化三个指针：
# i: 指向当前已排序的0的末尾（初始为-1，表示尚未找到0）
# j: 指向当前未处理的2的起始位置（初始为len(nums)，表示尚未找到2）
# k: 当前遍历的指针（从0开始）
        i,j,k = -1,len(nums),0
        while k < j:
            if nums[k] == 0:
                # 将i指针右移（表示已找到一个0）
                i+=1
                # 交换nums[i]和nums[k]，将0放到前面
                nums[i],nums[k] = nums[k],nums[i]
                k+=1
            elif nums[k] == 2:
                # 将j指针左移（表示已找到一个2）
                j-=1
                # 交换nums[k]和nums[j]，将2放到后面
                nums[k], nums[j] = nums[j], nums[k]
            elif nums[k] == 1:
                k+=1   # 直接右移k（1保持原位，无需交换）
# leetcode submit region end(Prohibit modification and deletion)

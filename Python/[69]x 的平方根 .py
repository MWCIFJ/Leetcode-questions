# 给你一个非负整数 x ，计算并返回 x 的 算术平方根 。 
# 
#  由于返回类型是整数，结果只保留 整数部分 ，小数部分将被 舍去 。 
# 
#  注意：不允许使用任何内置指数函数和算符，例如 pow(x, 0.5) 或者 x ** 0.5 。 
# 
#  
# 
#  示例 1： 
# 
#  
# 输入：x = 4
# 输出：2
#  
# 
#  示例 2： 
# 
#  
# 输入：x = 8
# 输出：2
# 解释：8 的算术平方根是 2.82842..., 由于返回类型是整数，小数部分将被舍去。
#  
# 
#  
# 
#  提示： 
# 
#  
#  0 <= x <= 2³¹ - 1 
#  
# 
#  Related Topics 数学 二分查找 👍 1655 👎 0


# leetcode submit region begin(Prohibit modification and deletion)
class Solution:
    def mySqrt(self, x: int) -> int:
        t = x
        while t * t > x:
            t = (t + (x / t)) / 2
        return int(t)
"""牛顿迭代公式，tn+1 = tn-(f(tn)/f'(tn))
而这里可以简化为f(t)=t^2-x=0
所以f'(t)=2t
状态转移方程为t = 1/2(t + (x/t))
然而这题用python超时，同样的写法在C++里就可以"""
# leetcode submit region end(Prohibit modification and deletion)
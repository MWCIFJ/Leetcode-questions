//给你一个长度为 n 的整数数组
// nums ，请你判断在 最多 改变 1 个元素的情况下，该数组能否变成一个非递减数列。 
//
// 我们是这样定义一个非递减数列的： 对于数组中任意的 i (0 <= i <= n-2)，总满足 nums[i] <= nums[i + 1]。 
//
// 
//
// 示例 1: 
//
// 
//输入: nums = [4,2,3]
//输出: true
//解释: 你可以通过把第一个 4 变成 1 来使得它成为一个非递减数列。
// 
//
// 示例 2: 
//
// 
//输入: nums = [4,2,1]
//输出: false
//解释: 你不能在只改变一个元素的情况下将其变为非递减数列。
// 
//
// 
//
// 提示： 
// 
//
// 
// n == nums.length 
// 1 <= n <= 10⁴ 
// -10⁵ <= nums[i] <= 10⁵ 
// 
//
// Related Topics 数组 👍 806 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
      if(nums.size()==1)
        return true;
      bool repair = nums[0]<=nums[1]?true:false;
        for(int i = 1;i<nums.size()-1;i++){
          if(nums[i]>nums[i+1]){
            if(repair){
              if(nums[i+1]>=nums[i-1])
                nums[i] = nums[i+1];//当前的缩小至与后续第一个等同，以免后续又乱
              else
                nums[i+1] = nums[i];//后续的第一个直接与当前同化，消除突兀点
            repair = false;
            }else
              return false;
          }
        }
        return true;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
class Solution {
public:
    bool checkPossibility(vector<int>& nums)
    {
        if (nums.size() == 1)   return true;
        bool flag = nums[0] <= nums[1] ? true : false; // 标识是否还能修改
        // 遍历时，每次需要看连续的三个元素
        for (int i = 1; i < nums.size() - 1; i++)
        {
            if (nums[i] > nums[i + 1])  // 出现递减
            {
                if (flag)   // 如果还有修改机会，进行修改
                {
                    if (nums[i + 1] >= nums[ i - 1])// 修改方案1
                        nums[i] = nums[i + 1];
                    else                            // 修改方案2
                        nums[i + 1] = nums[i];
                    flag = false;                   // 用掉唯一的修改机会
                }
                else        // 没有修改机会，直接结束
                    return false;
            }
        }
        return true;
    }
};

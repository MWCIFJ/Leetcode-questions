//科技馆内有一台虚拟观景望远镜，它可以用来观测特定纬度地区的地形情况。该纬度的海拔数据记于数组 heights ，其中 heights[i] 表示对应位置的海
//拔高度。请找出并返回望远镜视野范围 limit 内，可以观测到的最高海拔值。 
//
// 示例 1： 
//
// 
//输入：heights = [14,2,27,-5,28,13,39], limit = 3
//输出：[27,27,28,28,39]
//解释：
//  滑动窗口的位置                最大值
//---------------               -----
//[14 2 27] -5 28 13 39          27
//14 [2 27 -5] 28 13 39          27
//14 2 [27 -5 28] 13 39          28
//14 2 27 [-5 28 13] 39          28
//14 2 27 -5 [28 13 39]          39 
//
// 
//
// 提示： 
//
// 你可以假设输入总是有效的，在输入数组不为空的情况下： 
//
// 
// 1 <= limit <= heights.length 
// -10000 <= heights[i] <= 10000 
// 
//
// 注意：本题与主站 239 题相同：https://leetcode-cn.com/problems/sliding-window-maximum/ 
//
// 
//
// Related Topics 队列 数组 滑动窗口 单调队列 堆（优先队列） 👍 658 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> maxAltitude(vector<int>& heights, int limit) {
    if(heights.size()<limit || limit <= 0 || heights.empty())
      return {};

    vector<int> res;
    deque<int> findMax;
    for(int i = 0;i<heights.size();++i)
    {
        if(i >= limit && !findMax.empty())
             res.push_back(heights[findMax.front()]);
        while(!findMax.empty() && heights[findMax.back()] < heights[i])
             findMax.pop_back();
        if(!findMax.empty() && i-findMax.front() >= limit)
             findMax.pop_front();

        findMax.push_back(i);
    }

        res.push_back(heights[findMax.front()]);
        return res;
}
};
//leetcode submit region end(Prohibit modification and deletion)



//请设计一个自助结账系统，该系统需要通过一个队列来模拟顾客通过购物车的结算过程，需要实现的功能有： 
//
// 
// get_max()：获取结算商品中的最高价格，如果队列为空，则返回 -1 
// add(value)：将价格为 value 的商品加入待结算商品队列的尾部 
// remove()：移除第一个待结算的商品价格，如果队列为空，则返回 -1 
// 
//
// 注意，为保证该系统运转高效性，以上函数的均摊时间复杂度均为 O(1) 
//
// 
//
// 示例 1： 
//
// 
//输入: 
//["Checkout","add","add","get_max","remove","get_max"]
//[[],[4],[7],[],[],[]]
//
//输出: [null,null,null,7,4,7]
// 
//
// 示例 2： 
//
// 
//输入: 
//["Checkout","remove","get_max"]
//[[],[],[]]
//
//输出: [null,-1,-1]
// 
//
// 
//
// 提示： 
//
// 
// 1 <= get_max, add, remove 的总操作数 <= 10000 
// 1 <= value <= 10^5 
// 
//
// 
//
// Related Topics 设计 队列 单调队列 👍 530 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Checkout {
    queue<int> q;
    deque<int> d;
public:
    Checkout() {}
    int get_max() {
      int max = 0;
      queue<int>q2 = q;
      while(!q2.empty()) {
        int cur = q2.front();
        if(cur > max)
          max = cur;
        q2.pop();
      }
        return d.empty() ? -1 : max;
    }
    void add(int value) {
        q.push(value);    //q只是单端队列，所以没有back
        d.push_back(value);  //同步更新双端队列 d
    }
    int remove() {
        if(q.empty())
          return -1;
        int val = q.front();    //val用来保存删除前元素的值
        if(val == d.front())
            d.pop_front();    //同步更新双端队列 d
        q.pop();              //同步更新双端队列 q
        return val;    //所以这里必须val，而不是q.front()
    }
};


/**
 * Your Checkout object will be instantiated and called as such:
 * Checkout* obj = new Checkout();
 * int param_1 = obj->get_max();
 * obj->add(value);
 * int param_3 = obj->remove();
 */
//leetcode submit region end(Prohibit modification and deletion)

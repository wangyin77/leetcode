/*
 * @lc app=leetcode.cn id=282 lang=cpp
 *
 * [282] 给表达式添加运算符
 *
 * https://leetcode-cn.com/problems/expression-add-operators/description/
 *
 * algorithms
 * Hard (33.41%)
 * Likes:    99
 * Dislikes: 0
 * Total Accepted:    2.9K
 * Total Submissions: 8.6K
 * Testcase Example:  '"123"\n6'
 *
 * 给定一个仅包含数字 0-9 的字符串和一个目标值，在数字之间添加二元运算符（不是一元）+、- 或 * ，返回所有能够得到目标值的表达式。
 * 
 * 示例 1:
 * 
 * 输入: num = "123", target = 6
 * 输出: ["1+2+3", "1*2*3"] 
 * 
 * 
 * 示例 2:
 * 
 * 输入: num = "232", target = 8
 * 输出: ["2*3+2", "2+3*2"]
 * 
 * 示例 3:
 * 
 * 输入: num = "105", target = 5
 * 输出: ["1*0+5","10-5"]
 * 
 * 示例 4:
 * 
 * 输入: num = "00", target = 0
 * 输出: ["0+0", "0-0", "0*0"]
 * 
 * 
 * 示例 5:
 * 
 * 输入: num = "3456237490", target = 9191
 * 输出: []
 * 
 * 
 */

// @lc code=start
// class Solution {//超时
// public:
//     vector<string> ans;    
//     int target;

//     vector<string> addOperators(string num, int _target) {
//         if(num.empty()) return ans;
//         target = _target;
//         if(target == -2147483648) return ans;
//         if(target == 2147483648){
//             ans.push_back(num);
//             return ans;
//         }
//         dfs(num, "", 0, 0, 0);
//         return ans;
//     }

//     void dfs(string& num, string path, int pos, long long sum, long long mul){
//         if(pos == num.size()){
//             if(sum == target) ans.push_back(path);
//             return;
//         }
//         for(int i = pos; i < num.size(); i++){
//             if(num[pos] == '0' && i > pos) return;
//             string number = num.substr(pos, i - pos + 1);
//             long long  v = stol(number);
//             if(!pos){
//                 dfs(num, number, i + 1, v, v);
//             }else{
//                 dfs(num, path + '+' + number, i + 1, sum + v, v);
//                 dfs(num, path + '-' + number, i + 1, sum - v, -v);
//                 dfs(num, path + '*' + number, i + 1, sum - mul + mul * v, mul * v);
//             }
//         }
//     }
// };
class Solution {
    inline void checkNext(const char* num, char* expr_pos, int64_t prev, int64_t mul, int64_t cur, char op) {
        if (*num == 0) {
            mul *= cur;
            if ((op == '+' ? prev + mul : prev - mul) == tar) {
                *expr_pos = 0;
                out.emplace_back(expr);
            }
        }
        else dfs(num, expr_pos, prev, mul, cur, op);
    }
    
    /**
    @param num - pointer to current digit in original string.
    @param expr_pos - pointer to the current position in building expression string.
    @param prev - result before last multiply operation sequence.
    @param mul - result of last multiply operation sequence.
    @param cur - current number.
    @param op - operation before last multiply operation sequence.
    */
    void dfs(const char* num, char* expr_pos, int64_t prev, int64_t mul, int64_t cur, char op) {
        int new_cur = *num - '0';
        
        // add digits to current number
        if (cur != 0) {
            *expr_pos = *num;
            checkNext(num + 1, expr_pos + 1, prev, mul, new_cur + cur * 10, op);
        }
        
        // create new number
        expr_pos[1] = *num++;
        
        *expr_pos = '*'; // check multiply operation
        checkNext(num, expr_pos + 2, prev, mul * cur, new_cur, op);
        mul *= cur;
        prev = op == '+' ? prev + mul : prev - mul;
        
        *expr_pos = '+'; // check addition operation
        checkNext(num, expr_pos + 2, prev, 1, new_cur, '+');
        
        *expr_pos = '-'; // check subtraction operation
        checkNext(num, expr_pos + 2, prev, 1, new_cur, '-');
    }
    
    char expr[25];
    int64_t tar;
    vector<string> out;
    
public:
    vector<string> addOperators(string num, int target) {
        if (num.empty()) return out;
        auto num_ = num.data();
        expr[0] = *num_;
        tar = target;
        dfs(num_ + 1, expr + 1, 0, 1, *num_ - '0', '+');
        return out;
    }
};
// @lc code=end

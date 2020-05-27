/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
 *
 * https://leetcode-cn.com/problems/generate-parentheses/description/
 *
 * algorithms
 * Medium (75.42%)
 * Likes:    1043
 * Dislikes: 0
 * Total Accepted:    129.6K
 * Total Submissions: 171.8K
 * Testcase Example:  '3'
 *
 * 数字 n 代表生成括号的对数，请你设计一个函数，用于能够生成所有可能的并且 有效的 括号组合。
 * 
 * 
 * 
 * 示例：
 * 
 * 输入：n = 3
 * 输出：[
 * ⁠      "((()))",
 * ⁠      "(()())",
 * ⁠      "(())()",
 * ⁠      "()(())",
 * ⁠      "()()()"
 * ⁠    ]
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<string> ans;
    int n;
    vector<string> generateParenthesis(int _n) {
        n = _n;
        dfs(0, 0, "");
        return ans;
    }
    void dfs(int l, int r, string path){
        if(l == n && r == n) { // 注意不要写成 l == r == n
            ans.push_back(path);
            return;
        }
        if(l < n) dfs(l + 1, r, path + "(");
        if(r < l) dfs(l, r + 1, path + ")");
    }
};
// @lc code=end


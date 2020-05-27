/*
 * @lc app=leetcode.cn id=216 lang=cpp
 *
 * [216] 组合总和 III
 *
 * https://leetcode-cn.com/problems/combination-sum-iii/description/
 *
 * algorithms
 * Medium (71.04%)
 * Likes:    115
 * Dislikes: 0
 * Total Accepted:    20.9K
 * Total Submissions: 29.4K
 * Testcase Example:  '3\n7'
 *
 * 找出所有相加之和为 n 的 k 个数的组合。组合中只允许含有 1 - 9 的正整数，并且每种组合中不存在重复的数字。
 * 
 * 说明：
 * 
 * 
 * 所有数字都是正整数。
 * 解集不能包含重复的组合。 
 * 
 * 
 * 示例 1:
 * 
 * 输入: k = 3, n = 7
 * 输出: [[1,2,4]]
 * 
 * 
 * 示例 2:
 * 
 * 输入: k = 3, n = 9
 * 输出: [[1,2,6], [1,3,5], [2,3,4]]
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> ans;
    vector<int> path;
    int n;
    vector<vector<int>> combinationSum3(int k, int _n) {
        n = _n;
        dfs(0, k, 0);
        return ans;
    }

    void dfs(int sum, int k, int m){
        if(!k){
            if(sum == n) ans.push_back(path);
            return;
        }
        for(int i = m + 1; i < 10; i++){
            path.push_back(i);
            dfs(sum + i, k - 1, i);
            path.pop_back();
        }
    }
};
// @lc code=end


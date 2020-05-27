/*
 * @lc app=leetcode.cn id=39 lang=cpp
 *
 * [39] 组合总和
 *
 * https://leetcode-cn.com/problems/combination-sum/description/
 *
 * algorithms
 * Medium (68.93%)
 * Likes:    673
 * Dislikes: 0
 * Total Accepted:    95K
 * Total Submissions: 137.9K
 * Testcase Example:  '[2,3,6,7]\n7'
 *
 * 给定一个无重复元素的数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。
 * 
 * candidates 中的数字可以无限制重复被选取。
 * 
 * 说明：
 * 
 * 
 * 所有数字（包括 target）都是正整数。
 * 解集不能包含重复的组合。 
 * 
 * 
 * 示例 1:
 * 
 * 输入: candidates = [2,3,6,7], target = 7,
 * 所求解集为:
 * [
 * ⁠ [7],
 * ⁠ [2,2,3]
 * ]
 * 
 * 
 * 示例 2:
 * 
 * 输入: candidates = [2,3,5], target = 8,
 * 所求解集为:
 * [
 * [2,2,2,2],
 * [2,3,3],
 * [3,5]
 * ]
 * 
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> ans;
    vector<int> path;
    int target;
    vector<vector<int>> combinationSum(vector<int>& candidates, int _target) {
        target = _target;
        dfs(candidates, 0, 0, path);
        return ans;
    }
    void dfs(vector<int>& candidates, int deep, int sum, vector<int>& path){
        if(sum >= target){
            if(sum == target) ans.push_back(path);
            return;
        }
        for(int i = deep; i < candidates.size(); i++){
            path.push_back(candidates[i]);
            dfs(candidates, i, sum + candidates[i], path);
            path.pop_back();
        }
    }

};
// @lc code=end


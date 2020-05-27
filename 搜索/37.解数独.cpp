/*
 * @lc app=leetcode.cn id=37 lang=cpp
 *
 * [37] 解数独
 *
 * https://leetcode-cn.com/problems/sudoku-solver/description/
 *
 * algorithms
 * Hard (61.46%)
 * Likes:    423
 * Dislikes: 0
 * Total Accepted:    28.6K
 * Total Submissions: 46.6K
 * Testcase Example:  '[["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]]'
 *
 * 编写一个程序，通过已填充的空格来解决数独问题。
 * 
 * 一个数独的解法需遵循如下规则：
 * 
 * 
 * 数字 1-9 在每一行只能出现一次。
 * 数字 1-9 在每一列只能出现一次。
 * 数字 1-9 在每一个以粗实线分隔的 3x3 宫内只能出现一次。
 * 
 * 
 * 空白格用 '.' 表示。
 * 
 * 
 * 
 * 一个数独。
 * 
 * 
 * 
 * 答案被标成红色。
 * 
 * Note:
 * 
 * 
 * 给定的数独序列只包含数字 1-9 和字符 '.' 。
 * 你可以假设给定的数独只有唯一解。
 * 给定数独永远是 9x9 形式的。
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    bool x[9][9], y[9][9], sq[3][3][9];
    void solveSudoku(vector<vector<char>>& board) {
        memset(x, false, sizeof x);
        memset(y, false, sizeof y);
        memset(sq, false, sizeof sq);
        for(int i = 0; i < 9; i++)
            for(int j = 0; j < 9; j++)
                if(board[i][j] != '.'){
                    int v = board[i][j] - '1';
                    x[i][v] = y[j][v] = sq[i / 3][j / 3][v] = true;
                }
                    
        
        dfs(board, 0, 0);
    }
    bool dfs(vector<vector<char>>& board, int l, int r){
        if(r == 9) ++l, r = 0;
        if(l == 9) return true;
        if(board[l][r] == '.'){
            for(int v = 0; v < 9; v++)
                if(x[l][v] == true || y[r][v] == true || sq[l / 3][r / 3][v] == true){
                    continue;
                }else{
                    x[l][v] = y[r][v] = sq[l / 3][r / 3][v] = true;                    
                    if(dfs(board, l, r + 1)) {
                        board[l][r] = v + '1';
                        return true;
                    }
                    x[l][v] = y[r][v] = sq[l / 3][r / 3][v] =false;
                }
        }else{
            return dfs(board, l, r + 1);
        }
        return false;
    }
};
// @lc code=end


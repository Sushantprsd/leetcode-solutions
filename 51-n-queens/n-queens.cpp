class Solution {
public:
  bool isSafe(vector<string>& currentSet, int row, int col) {
        // Check the same column
        for (int i = 0; i < row; i++) {
            if (currentSet[i][col] == 'Q') {
                return false;
            }
        }

        // Check upper-left diagonal
        for (int i = row - 1, j = col - 1;
             i >= 0 && j >= 0; i--, j--) {
            if (currentSet[i][j] == 'Q') {
                return false;
            }
        }

        // Check upper-right diagonal
        for (int i = row - 1, j = col + 1;
             i >= 0 && j < currentSet.size(); i--, j++) {
            if (currentSet[i][j] == 'Q') {
                return false;
            }
        }

        return true;
    }
    void prepareSet(int &n, int row, vector<string> &currentSet, vector<vector<string>> &ans) {
        if (row >= n) {
            ans.emplace_back(currentSet);
            return;
        }
        for (int i = 0; i < n; i++) {
            if(isSafe(currentSet, row, i)) {
                currentSet[row][i] = 'Q';
                prepareSet(n, row+1, currentSet, ans);
            }
            currentSet[row][i] = '.';
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> currentSet(n, string(n, '.'));
        prepareSet(n, 0, currentSet, ans);
        return ans;
    }
};
class Solution {
public:
    bool isSafe(int i, int j, vector<vector<char>>& board) {
        return i >= 0 && i < board.size() &&
              j >= 0 && j < board[0].size();
    }
  bool dfs(vector<vector<char>>& board, string &word, int start, int i, int j, vector<vector<bool>> &visited) {
    if (board[i][j] != word[start] || visited[i][j]) {
      return false;
    }
    if (start == word.length() - 1) {
      return true;
    }
    visited[i][j] = true;
    if (isSafe(i, j+1, board)) {
      if (dfs(board, word, start + 1, i, j + 1, visited)) return true;
    }
    if (isSafe(i, j-1, board)) {
      if (dfs(board, word, start + 1, i, j-1, visited)) return true;
    }

    if (isSafe(i + 1,j, board)) {
      if (dfs(board, word, start + 1, i+1, j, visited)) return true;
    }
    if (isSafe(i-1, j, board)) {
      if (dfs(board, word, start + 1, i-1, j, visited)) return true;
    }
    visited[i][j] = false;
    return false;
  }

  bool exist(vector<vector<char>>& board, string word) {
    
    vector<vector<bool>> visited(
      board.size(), 
      vector<bool>(board[0].size(), false)
    );
    for (int i = 0; i < board.size(); i++) {
      for (int j = 0; j < board[0].size(); j++) {
        if (dfs(board, word, 0, i, j, visited)) return true;
      }
    }
    return false;
  }
};
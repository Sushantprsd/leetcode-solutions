class Solution {
public:
  void setZeroes(vector<vector<int>>& matrix) {
    bool setRowZero = false;
    bool setColZero = false;
    for(int i = 0; i < matrix.size(); i++) {
      for (int j = 0; j < matrix[0].size(); j++) {

        if (i == 0 and j == 0 && matrix[i][j] == 0) {
          setRowZero = true;
          setColZero = true;
        } else if (i == 0 && matrix[i][j] == 0){
          setRowZero = true;
        } else if (j == 0 && matrix[i][j] == 0) {
          setColZero = true;
        } else if (matrix[i][j] == 0) {
          matrix[i][0] = 0;
          matrix[0][j] = 0;
        }

      }
    }

    for (int i = 1; i < matrix.size(); i++) {
      for (int j = 1; j < matrix[0].size(); j++) {
        if (matrix[i][0] == 0 || matrix[0][j] == 0) {
          matrix[i][j] = 0;
        }
      }
    }

    if (setColZero) {
      for (int j = 0; j < matrix.size(); j++) {
        matrix[j][0] = 0;
      }
    }


    if (setRowZero) {
      for (int j = 0; j < matrix[0].size(); j++) {
        matrix[0][j] = 0;
      }
    }
    
  }
};
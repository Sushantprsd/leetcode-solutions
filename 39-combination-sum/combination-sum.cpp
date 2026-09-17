class Solution {
public:
  void helper(vector<int>& candidates, int target, vector<vector<int>> &ans, vector<int> &currentPath, int i) {
    if (i == candidates.size() || target < 0) {
      return;
    }
    if (target == 0) {
      ans.push_back(currentPath);
      return;
    }
    helper(candidates, target, ans, currentPath, i+1);
    currentPath.push_back(candidates[i]);
    helper(candidates, target - candidates[i], ans, currentPath, i);
    currentPath.pop_back();
  }
  vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> ans;
    vector<int> currentPath;
    helper(candidates, target, ans, currentPath, 0);
    return ans;
  }
};
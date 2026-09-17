class Solution {
public:
  void helper (vector<int>& candidates, int target, int start, vector<int> &current, vector<vector<int>> &ans) {
    if (target == 0) {
      ans.push_back(current);
      return; 
    }
    if (start >= candidates.size() || target < 0) {
      return;
    }
    // take
    current.push_back(candidates[start]);
    helper(candidates, target - candidates[start], start, current, ans);
    //no take
    current.pop_back();
    helper(candidates, target, start + 1, current, ans);
  }
  vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<int> current = {};
    vector<vector<int>> ans;
    helper(candidates, target, 0, current, ans);
    return ans;
  }
};
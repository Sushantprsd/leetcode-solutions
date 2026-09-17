class Solution {
public:
  bool isPalindrome(string s) {
    int left = 0;
    int right = s.size() - 1;

    while (left < right) {
        if (s[left] != s[right]) {
            return false;
        }

        left++;
        right--;
    }

    return true;
}

  void helper(string &s, int i, vector<vector<string>> &ans, vector<string> &currentPartition) {
    if (i == s.length()) {
      ans.push_back(currentPartition);
      return;
    }
    for(int j = i; j < s.length(); j++) {
      auto subStr = s.substr(i, j - i + 1);
      if (isPalindrome(subStr)) {
        currentPartition.push_back(subStr);
        helper(s, j+1, ans, currentPartition);
        currentPartition.pop_back();
      }
    }
  }

  vector<vector<string>> partition(string s) {
    vector<vector<string>> ans;
    vector<string> currentPartition;
    helper(s, 0, ans, currentPartition);
    return ans;
  }
};
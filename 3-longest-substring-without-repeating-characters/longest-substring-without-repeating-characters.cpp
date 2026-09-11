class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    int ans = 0;
    int currentLength = 0;
    int start = 0;
    vector<int> dict(256, -1);

    for (int i = 0; i < s.length(); i++) {
      if (dict[s[i]] > -1 && dict[s[i]] < start) {
      } else  if (dict[s[i]] > -1 ){
        start = dict[s[i]] + 1;
      }
      dict[s[i]] = i;
      ans = max(ans, i - start + 1);
    }
    return ans;
  }
};
class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    int ans = 0;
    int currentLength = 0;
    int start = 0;
    unordered_map<char, int> dict;

    for (int i = 0; i < s.length(); i++) {
      if (dict.find(s[i]) != dict.end() && dict[s[i]] < start) {
      } else  if (dict.find(s[i]) != dict.end()){
        start = dict[s[i]] + 1;
      }
      dict[s[i]] = i;
      ans = max(ans, i - start + 1);
    }
    return ans;
  }
};
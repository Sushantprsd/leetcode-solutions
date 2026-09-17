class Solution {
public:
  vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    unordered_map<int, int> m;
    stack<int> s;

    vector<int> ans;
    for(int i = 0; i < nums2.size(); i++) {
      if (s.empty()) {
        s.push(nums2[i]);
      } else {
        while (!s.empty() && s.top() < nums2[i]) {
          auto top = s.top();
          s.pop();
          m[top] = nums2[i];
        }
        s.push(nums2[i]);
      }
    }
    for(int i = 0; i < nums1.size(); i++) {
      ans.push_back(m[nums1[i]] ? m[nums1[i]] : -1);
    }
    return ans;
  }
};
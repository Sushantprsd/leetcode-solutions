class Solution {
public:
  int largestRectangleArea(vector<int>& heights) {
    int ans = 0;
    stack<int> s;

    for (int i=0; i < heights.size(); i++) {
      ans = max(ans, heights[i]);
      if (s.empty()) {
        s.push(i);
      } else {
        int newLeftMax = heights[i];
        while (!s.empty() && newLeftMax <= heights[s.top()]) {
          int top = s.top();
          s.pop();
          int leftMin = s.empty() ? -1 : s.top();
          ans = max(ans, heights[top]*(i - leftMin - 1));
        }
        s.push(i);
      }

    }
  int n = heights.size();
    while (!s.empty()) {
      int top = s.top();
      s.pop();
      int leftMin = s.empty() ? -1 : s.top();
      ans = max(ans, heights[top]*( n - leftMin - 1)); 
    }

    return ans;
  }
};
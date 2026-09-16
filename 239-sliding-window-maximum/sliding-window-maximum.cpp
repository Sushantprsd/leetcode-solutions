class Solution {
public:
    void populateDq(deque<int> &dq, vector<int> &nums, int i, int k) {
        while (dq.size() && nums[dq.back()] < nums[i]) {
            dq.pop_back();
        }
        while (dq.size() && dq.front() < i - k + 1) {
            dq.pop_front();
        }
        dq.push_back(i);
    }

    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++) {
            populateDq(dq, nums, i, k);
            if (i < k-1) {
                continue;
            }
            ans.push_back(nums[dq.front()]);
        }
        return ans;
    }
};
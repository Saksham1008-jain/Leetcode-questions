class Solution {
public:
    int mod = 1e9 + 7;
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int> sum;
        for (int i = 0; i < n; i++) {
            int p = 0;
            for (int j = i; j < n; j++) {
                p += nums[j];
                sum.push_back(p);
            }
        }
        int ans = 0;
        sort(sum.begin(), sum.end());
        for (int i = left - 1; i < right; i++) {
            ans = (ans + sum[i]) % mod;
        }
        return ans % mod;
    }
};

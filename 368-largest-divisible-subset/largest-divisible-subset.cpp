class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<int> dp(n, 1), hash(n);
        int maxi = 1;
        int lastindex = 0;

        for (int i = 0; i < n; i++) {
            hash[i] = i;
            for (int prev_ind = 0; prev_ind < i; prev_ind++) {
                if ((nums[i] % nums[prev_ind] == 0) && (1 + dp[prev_ind] > dp[i])) {
                    dp[i] = 1 + dp[prev_ind];
                    hash[i] = prev_ind;
                }
            }
            if (dp[i] > maxi) {
                maxi = dp[i];
                lastindex = i;
            }
        }
        vector<int>temp;
        temp.push_back(nums[lastindex]);
        while(lastindex!=hash[lastindex]){
            lastindex = hash[lastindex];
            temp.push_back(nums[lastindex]);
        }
        reverse(temp.begin(),temp.end());
        return temp;
    }
};
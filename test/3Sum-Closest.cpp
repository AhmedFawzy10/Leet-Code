class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int closest = nums[0] + nums[1] + nums[2], n = nums.size();
        for(int i = 0; i < n; i++)
        {
            int l = i+1, r = n-1;
            while(l < r)
            {
                int sum = nums[i] + nums[l] + nums[r];
                if(sum == target)return sum;
                if(abs(sum - target) < abs(closest - target))closest = sum;
                if(sum < target)l++;
                else r--;
            }
        }
        return closest;
    }
};
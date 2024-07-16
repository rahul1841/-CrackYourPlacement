Q1. Chocolate Distribution Problem

long long findMinDiff(vector<long long> a, long long n, long long m){
    //code
    sort(a.begin(), a.end());
    
    int i = 0, j = m-1;
    
    int mini = INT_MAX;
    
    while(j < n){
        int curr_diff = a[j] - a[i];
        mini = min(mini, curr_diff);
        i++;
        j++;
    }
    return mini;
    }   


Q2. 1. Two Sum

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;
        for(int i = 0; i<nums.size(); i++){
            mp[nums[i]] = i;
        }

        for(int i = 0; i<nums.size(); i++){
            int ele = target - nums[i];
            if(mp.find(ele) != mp.end() && mp[ele] != i){
                return {i, mp[ele]};
            }
        }
        return {};
    }
};


Q3. 122. Best Time to Buy and Sell Stock II

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxP = 0;
        int s = prices[0];

        for(int i = 0; i<prices.size(); i++){
            if(s < prices[i]){
                maxP += prices[i] - s;
            }
            s = prices[i];
        }
        return maxP;
    }
};


Q4. 974. Subarray Sums Divisible by K


giving tle : 
class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int cnt = 0;
        for(int i = 0; i<nums.size(); i++){
            int sum = 0;
            for(int j = i; j<nums.size(); j++){
                sum += nums[j];
                if(sum % k == 0){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};

2nd approach: 

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {

        int prefixSum = 0;
        int cnt = 0;
        unordered_map<int, int> mp;

        mp[0] = 1;
        // Importance of m[0] = 1:

        // In the example, the subarray [4, 5, 0, -2, -3, 1] starting from the beginning has a sum directly divisible by k:

        // When the sum is 5, mod = 0.
        // m[0] = 1 initially indicates that there's one way to have a prefix sum of 0 (from the start), thus detecting subarrays like the entire array [4, 5, 0, -2, -3, 1].
        // Without m[0] = 1, this subarray would be missed, as there would be no initial entry to indicate the possibility of a prefix sum of 0. 

        for(int i = 0; i<nums.size(); i++){
            prefixSum += nums[i];
            int modVal = prefixSum % k;

            if(modVal < 0){
                modVal += k;
            }
            if(mp.find(modVal) != mp.end()){
                cnt += mp[modVal];
            }
            mp[modVal]++;
        }
        return cnt;
    }
};


Q5. 442. Find All Duplicates in an Array

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
       vector<int> ans;
        sort(nums.begin(),nums.end());
        for(int i = 0;i<nums.size()-1;i++){
            if(nums[i]==nums[i+1]){
                ans.push_back(nums[i]);
            }
        }
        return ans;
    }
};

Time Complexity: The most time-consuming operation is sorting the array, which takes O(nlogn) time. 
The subsequent linear scan to find duplicates takes O(n) time but is overshadowed by the sorting step.
Space Complexity: The sorting step may use O(logn) space (for the stack in quicksort, for instance), 
but storing duplicates can take up to O(n) space in the worst case.

approach 2: 
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
       vector<int> ans;
        for(int i = 0;i<nums.size();i++){
            int ele = abs(nums[i]);
            if(nums[ele-1] < 0){
                ans.push_back(ele);
            }
            else{
            nums[ele-1] *= -1;
            }
        }
        return ans;
    }
};  tc : o(n) and sc - o(1) excluding output array


Q6: 11. Container With Most Water

class Solution {
public:
    int maxArea(vector<int>& height) {

        int left = 0;
        int right = height.size()-1;
        int maxi = 0;

        while(left < right){

            int lh = height[left];
            int rh = height[right];

            int mini = min(lh, rh);
            maxi = max(maxi, mini*(right-left));

            if(lh<rh){
                left++;
            }
            else{
                right--;
            }
        }
        return maxi;
    }
};

Time Complexity: 
O(n)
Space Complexity: 
O(1)
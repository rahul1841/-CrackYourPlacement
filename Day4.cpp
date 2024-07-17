Q1. 88. Merge Sorted Array

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

        int i = m-1, j = n-1, k = m+n-1;

        while(i >= 0 && j >= 0){
            if(nums1[i] > nums2[j]){
                nums1[k] = nums1[i];
                i--;
                k--;
            }
            else{
                nums1[k] = nums2[j];
                j--;
                k--;
            }
        }

        while(i >= 0){
            nums1[k] = nums1[i];
            i--;
            k--;
        }

        while(j >= 0){
            nums1[k] = nums2[j];
            j--;
            k--;
        }
    }
};


Q2. 55. Jump Game

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxReach = 0;
        for(int i = 0; i<nums.size(); i++){
            if(i > maxReach){
                return false;
            }
            maxReach = max(maxReach, i + nums[i]);
        }
        return maxReach >= nums.size()-1;
    }
};


Q3. 169. Majority Element

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt = 0;
        int candidate = 0;

        for(auto it : nums){
            if(cnt == 0){
                candidate = it;
            }

            if(it == candidate){
                cnt++;
            }
            else{
                cnt--;
            }
        }
        return candidate;
    }
};


approach2 :
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt = 0;
        int candidate = nums[0];

        for(int i = 0; i<nums.size(); i++){
            if(cnt == 0){
                candidate = nums[i];
            }
            if (candidate == nums[i]){
                cnt++;
            }
            else{
                cnt--;
            }
        }
        return candidate;
    }
};


Q4. 493. Reverse Pairs

class Solution {
public:
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        long long reversePairCnt = 0;
        for(int i = 0; i<n-1; i++){
            for(int j = i+1; j<n; j++){
                if(nums[i] > 2*(long long)nums[j]){
                    reversePairCnt++;
                }
            }
        }
        return reversePairCnt;
    }
};  TC-O(N^2) SC - O(1)  GIVES TLE

approach2:
class Solution {
public:
    void merge(vector<int>& nums, int low, int mid, int high, int& reversePairsCount){
        int j = mid+1;
        for(int i=low; i<=mid; i++){
            while(j<=high && nums[i] > 2*(long long)nums[j]){
                j++;
            }
            reversePairsCount += j-(mid+1);
        }

        int size = high-low+1;
        vector<int> temp(size, 0);
        int left = low, right = mid+1, k=0;
        while(left<=mid && right<=high){
            if(nums[left] < nums[right]){
                temp[k++] = nums[left++];
            }
            else{
                temp[k++] = nums[right++];
            }
        }
        while(left<=mid){
            temp[k++] = nums[left++]; 
        }
        while(right<=high){
            temp[k++] = nums[right++]; 
        }
        int m=0;
        for(int i=low; i<=high; i++){
            nums[i] = temp[m++];
        }
    }

    void mergeSort(vector<int>& nums, int low, int high, int& reversePairsCount){
        if(low >= high){
            return;
        }
        int mid = (low + high) >> 1;
        mergeSort(nums, low, mid, reversePairsCount);
        mergeSort(nums, mid+1, high, reversePairsCount);
        merge(nums, low, mid, high, reversePairsCount);
    }
    int reversePairs(vector<int>& nums) {
        int reversePairsCount = 0;
        mergeSort(nums, 0, nums.size()-1, reversePairsCount);
        return reversePairsCount;
    }
};  Time Complexity : O(NlogN), Each recursive call to performs two recursive calls on subslices of size N/2 and
    One linear scans of length <= N. Therefore, the time complexity of the divide & conquer approach can be
    represented by the following recurrence relation: T(N)=2T(N/2)+N. Where N is the size of the Array(nums).

    Space Complexity : O(N), Recursion Stack Space O(logN) + Array(temp) space O(N).


Q5. All Unique Permutations of an array

class Solution {
  public:
  
    vector<vector<int>> ans;
    unordered_map<int, int> mp;
    
    void solve(vector<int> &arr , set<int> &s, int indx, vector<int> &v){
        
        if(indx >= arr.size()){
            ans.push_back(v);
            return;
        }
        
        for(auto it : s){
            if(mp[it] > 0){
                mp[it]--;
                v.push_back(it);
                solve(arr, s, indx+1, v);
                mp[it]++;
                v.pop_back();
            }
        }
    }
    
    vector<vector<int>> uniquePerms(vector<int> &arr ,int n) {
        // code here
        
        vector<int> v;
        set<int> s;
        
        for(auto it : arr){
            s.insert(it);
            mp[it]++;
        }
        
        solve(arr, s, 0, v);
        return ans;
    }
}; Time Complexity: O(n*n!), Space Complexity: O(n*n!)


Q6. 289. Game of Life

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {

        int n = board.size();
        int m = board[0].size();

        vector<int> dx = {0, 0, 1, 1, 1, -1, -1, -1};
        vector<int> dy = {1, -1, 1, -1, 0, 0, 1, -1};

        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){

                int curr_live_neighbours = 0;

                for(int k = 0; k<8; k++){
                    int currX = i + dx[k];
                    int currY = j + dy[k];
                    if(currX >= 0 && currX < n && currY >= 0 && currY < m
                    && abs(board[currX][currY]) == 1){
                      curr_live_neighbours++;  
                    }
                }

                if(board[i][j] == 1 && (curr_live_neighbours < 2 || 
                curr_live_neighbours > 3)){
                    board[i][j] = -1;
                }

                if(board[i][j] == 0 && (curr_live_neighbours == 3)){
                    board[i][j] = 2;
                }
            }
        }

        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(board[i][j] >= 1){
                    board[i][j] = 1;
                }
                else{
                    board[i][j] = 0;
                }
            }
        }
    }
};   TC- O(M*N), SC- O(1)


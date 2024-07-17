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


Q3.  

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


Q4.


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


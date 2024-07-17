Q1. 15. 3Sum

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        set<vector<int>> s;

        for(int i = 0; i<nums.size(); i++){
            int j = i+1;
            int k = nums.size()-1;

            while(j < k){
            int sum = nums[i] + nums[j] + nums[k];
            if(sum == 0){
                s.insert({nums[i], nums[j], nums[k]});
                j++;
                k--;
            }
            else if(sum < 0){
                j++;
            }
            else{
                k--;
            }
            }
        }

        for(auto triplet : s){
            ans.push_back(triplet);
        }
        return ans;
    }
};    TC- O(n^2) ,Sc- O(K)


Q2. 18. 4Sum

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {

        int n = nums.size();
        sort(nums.begin(), nums.end());
        set<vector<int>> s;
        vector<vector<int>> output;

        for(int i = 0; i<n-3; i++){
            for(int j = i+1; j<n-2; j++){

                long long newTarget = (long long)target - (long long )nums[i]-(long long)nums[j];
                int low = j+1, high = n-1;

                while(low < high){
                    if(nums[low] + nums[high] == newTarget){
                        s.insert({nums[i], nums[j], nums[low], nums[high]});
                        low++;
                        high--;
                    }
                    else if(nums[low] + nums[high] < newTarget){
                        low++;
                    }
                    else{
                        high--;
                    }
                }

            }
        }

        for(auto it : s){
            output.push_back(it);
        }
        return output;
    }
};       Tc - o(N^3), sc - O(k)

approach2 : 
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {

        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> output;

        for(int i = 0; i<n-3; i++){
            for(int j = i+1; j<n-2; j++){

                long long newTarget = (long long)target - (long long )nums[i]-(long long)nums[j];
                int low = j+1, high = n-1;

                while(low < high){
                    if(nums[low] + nums[high] == newTarget){
                        output.push_back({nums[i], nums[j], nums[low], nums[high]});
                        int tempIndx1 = low, tempIndx2 = high;
                        while(low < high && nums[low] == nums[tempIndx1]) low++;
                        while(low < high && nums[high] == nums[tempIndx2]) high--;
                    }
                    else if(nums[low] + nums[high] < newTarget){
                        low++;
                    }
                    else{
                        high--;
                    }
                }
                while(j+1 < n && nums[j] == nums[j+1]) j++;
            }
            while(i+1 < n && nums[i] == nums[i+1]) i++;
        }
        return output;
    }
};        TC-o(n^3) , SC - o(1)


Q3. 560. Subarray Sum Equals K

sliding window : 
class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {

        int n = cardPoints.size();
        int ans = 0;

        for(int i = 0; i<k; i++){
            ans += cardPoints[i];
        }

        if(n == k) return ans;

        int curr = ans;

        for(int i = k-1; i>=0; i--){
            curr -= cardPoints[i];
            curr += cardPoints[n-k+i];
            ans = max(ans, curr);
        }
        return ans;
    }
};    TC-O(K), SC- O(1)


Q4. 560. Subarray Sum Equals K


class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {

        int n = nums.size();
        int prefix[n];

        prefix[0] = nums[0];
        for(int i = 1; i<n; i++){
            prefix[i] = nums[i] + prefix[i-1];
        }

        int cnt = 0;

        unordered_map<int, int> mp;

        for(int i = 0; i<n; i++){
            if(prefix[i] == k) cnt++;

            int rem = prefix[i]-k;
            if(mp.find(rem) != mp.end()){
                cnt += mp[rem];
            }
            mp[prefix[i]]++;
        }
        return cnt;
    }
};  TC-O(N), SC-O(N)


Q5: 54. Spiral Matrix


class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int row = matrix.size();
        int col = matrix[0].size();

        int cnt = 0;
        int total = row*col;

        int startingRow = 0;
        int endingRow = row-1;
        int startingCol = 0;
        int endingCol = col-1;

        while(cnt < total){

            for(int i = startingCol; cnt<total && i<= endingCol; i++){
                ans.push_back(matrix[startingRow][i]);
                cnt++;
            }
            startingRow++;

            for(int i = startingRow;cnt<total && i<= endingRow; i++){
                 ans.push_back(matrix[i][endingCol]);
                cnt++;
            }
            endingCol--;

            for(int i = endingCol;cnt<total && i>= startingCol; i--){
                 ans.push_back(matrix[endingRow][i]);
                cnt++;
            }
            endingRow--;

            for(int i = endingRow;cnt<total && i>= startingRow; i--){
                 ans.push_back(matrix[i][startingCol]);
                cnt++;
            }
            startingCol++;
        }
        return ans;
    }
};  TC-O(M*N),   SC-O(M*N)


Q6. 79. Word Search

class Solution {
public:

    bool find(vector<vector<char>>& board, string &word, vector<vector<int>> &visited, 
              int row, int col, int indx, int n, int m){

                if(word.size() == indx) return true;
                if(row < 0 || row >= n || col < 0 || col>=m || 
                   board[row][col] != word[indx] || visited[row][col]){
                    return false;
                }

                visited[row][col] = true;

                int delr[] = {-1, 0, 1, 0};
                int delc[] = {0, 1, 0, -1};

                for(int i = 0; i<4; i++){
                    int nrow = row + delr[i];
                    int ncol = col + delc[i];

                    if(find(board, word, visited, nrow, ncol, indx+1, n, m) == true){
                        return true;
                    }
                }
                visited[row][col] = false;
                return false;
    }
    bool exist(vector<vector<char>>& board, string word) {

        int n = board.size();
        int m = board[0].size();

        vector<vector<int>> visited (n, vector<int>(m, 0));

        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(board[i][j] == word[0] && find(board, word, visited, i, j, 0, n, m) == true){
                    return true;
                }
            }
        }
        return false;
    }
};   

 Time Complexity: 
𝑂(n*m*4^l)
 where n is the number of rows, m is the number of columns, and l is the length of the word.

Space Complexity: 
𝑂(𝑛×𝑚+𝑙).
visited array:
O(n×m) space to keep track of visited cells.
Recursive Stack:
The recursive calls can go up to 
l in depth, contributing 
O(l) space to the stack






Q1.  287. Find the Duplicate Number

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for(int i = 0; i<nums.size()-1; i++){
            if(nums[i] == nums[i+1]){
                return nums[i];
            }
        }
        return 0;
    }
};


Q2. 75. Sort Colors

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int s = 0;
        int e = nums.size()-1;
        int i = 0;
        while(i <= e){
            if(nums[i] == 0){
                swap(nums[i], nums[s]);
                i++;
                s++;
            }
            else if(nums[i] == 1){
                i++;
            }
            else{
                swap(nums[i], nums[e]);
                e--;
            }
        }
    }
};


Q3. 26. Remove Duplicates from Sorted Array

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int j = 1;
        for(int i = 1; i<nums.size(); i++){
            if(nums[i] != nums[i-1]){
                nums[j] = nums[i];
                j++;
            }
        }
        return j;
    }
};


Q4. 73. Set Matrix Zeroes

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(matrix[i][j] == 0){

                    // row zero
                    for(int k = 0; k<m; k++){
                    if(matrix[i][k] != 0){
                        matrix[i][k] = -99999;
                    }
                    }

                    // col zero
                    for(int k = 0; k<n; k++){
                        if(matrix[k][j] != 0){
                            matrix[k][j] = -99999;
                        }
                    }
                }
            }
        }

        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(matrix[i][j] == -99999){
                    matrix[i][j] = 0;
                }
            }
        }
    }
};


Q5. 283. Move Zeroes

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int start = 0;
        for(int i = 0; i<nums.size(); i++){
            if(nums[i] != 0){
                swap(nums[start], nums[i]);
                start++;
            }
        }
    }
};


Q6. 121. Best Time to Buy and Sell Stock

class Solution {
public:
    int maxProfit(vector<int>& prices) {

        if(prices.empty()){
            return 0;
        }

        int minEle = prices[0];
        int maxProfit = 0;

        for(int i = 0; i<prices.size(); i++){
            minEle = min(minEle, prices[i]);
            maxProfit = max(maxProfit, prices[i]-minEle);
        }
        return maxProfit;
    }
};


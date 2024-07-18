Q1. 1499. Max Value of Equation

class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        int n = points.size();
        int ans = INT_MIN;

        priority_queue<pair<int, int>> q;

        for(int i = 0; i<n; i++){
            while((!q.empty()) && points[i][0]-q.top().second>k) q.pop();

            if(!q.empty()){
                ans = max(ans, (q.top().first + points[i][0] + points[i][1]));
            }
            q.push({points[i][1] - points[i][0], points[i][0]});
        }
        return ans;
    }
};   Time Complexity (TC): O(nlogn), Space Complexity (SC): O(n)


Q2. 381. Insert Delete GetRandom O(1) - Duplicates allowed

class RandomizedCollection {
public:
    unordered_map<int, vector<int>> mp;        // to store indexes
    vector<pair<int, int>> a;                 // to store elements
    RandomizedCollection() {
        
    }
    
    bool insert(int val) {
        if(mp.find(val) == mp.end()){
            mp[val].push_back(a.size());  // first time pusing so indx = a.size()
            a.push_back({val, mp[val].size()-1});
            return true;
        }
        else{
            mp[val].push_back(a.size());  // first time pusing so indx = a.size()
            a.push_back({val, mp[val].size()-1});
            return false;            
        }
    }
    
        bool remove(int val) {
        auto it=mp.find(val);
        if(it != mp.end()){
            auto last = a.back();
            mp[last.first][last.second] = mp[val].back();
            a[mp[val].back()] = last;
            mp[val].pop_back();
            if(mp[val].empty())
                mp.erase(val);
            a.pop_back();
            return true;
        }
        return false;
         
    }

    
    int getRandom() {
        return a[rand()%a.size()].first;
    }
};    Time Complexity (TC):

Insert: O(1), Remove: O(1), GetRandom: o(1), ,Space Complexity (SC): O(n)

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */


 Q3. 84. Largest Rectangle in Histogram

 class Solution {
public:
    vector<int> nextSmallerElement(vector<int> arr,int n){
        stack<int> st;
        st.push(-1);
        vector<int> ans(n);

        for(int i = n-1; i>=0; i--){
            int curr = arr[i];
            while(st.top() != -1 && arr[st.top()] >= curr){
                st.pop();
            }
            ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }

    vector<int> prevSmallerElement(vector<int> arr,int n){
        stack<int> st;
        st.push(-1);
        vector<int> ans(n);

        for(int i = 0; i<n; i++){
            int curr = arr[i];
            while(st.top() != -1 && arr[st.top()] >= curr){
                st.pop();
            }
            ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }

    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();

        vector<int> next(n);
        next = nextSmallerElement(heights, n);

        vector<int> prev(n);
        prev = prevSmallerElement(heights, n);

        int maxArea = INT_MIN;

        for(int i = 0; i<n; i++){
            int l = heights[i];

            if(next[i] == -1){
                next[i] = n;
            }

            int b = next[i] - prev[i] - 1;
            int newArea = l*b;

            maxArea = max(maxArea, newArea);
        }
        return maxArea;
    }
};      Time Complexity (TC): O(n), Space Complexity (SC): O(n)
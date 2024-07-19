Q1. 14. Longest Common Prefix

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {

        sort(strs.begin(), strs.end());

        int minimum = min(strs.front().size(), strs.back().size());

        int i = 0;
        for(i = 0; i<minimum; i++){
            if(strs.front()[i] != strs.back()[i]){
                break;
            }
        }
        return strs[0].substr(0, i);
    }
};


Q2. 680. Valid Palindrome II

class Solution {
public:

    bool check(string s, int i, int j){
        while(i <= j){
            if(s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }

    bool validPalindrome(string s) {
        int i = 0;
        int j = s.size()-1;

        while(i <= j){
            if(s[i] != s[j]){
                return check(s, i+1, j) || check(s, i, j-1);
            }
            else{
                i++;
                j--;
            }
        }
        return true;
    }
};


Q3. 12. Integer to Roman

class Solution {
public:
    string intToRoman(int num) {
        string roman;
        vector<string> notations = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        vector<int> values = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};

        for(int i = 0; num>0; i++){
            while(num >= values[i]){
                roman += notations[i];
                num -= values[i];
            }
        }
        return roman;
    }
};   Time Complexity (TC): O(1), Space Complexity (SC): O(logn)


Q4. 22. Generate Parentheses

class Solution {
public:
    void dfs(int openP, int closeP, string s, int n, vector<string> &ans){
        if(openP == closeP && openP + closeP == 2*n){
            ans.push_back(s);
            return;
        }

        if(openP < n){
            dfs(openP+1, closeP, s + "(", n, ans);
        }

        if(closeP < openP){
            dfs(openP, closeP+1, s + ")", n, ans);
        }
    }

    vector<string> generateParenthesis(int n) {
        vector <string> ans;
        dfs(0, 0, "", n, ans);
        return ans;
    }
};  Time complexity:O(2^2 n), Space complexity: O(n)


Q5. 71. Simplify Path

class Solution {
public:
    string simplifyPath(string path) {
        stack<string> st;
        string ans;

        for(int i = 0; i<path.length(); i++){

            if(path[i] == '/') continue;
            string temp;
            while(i < path.length() && path[i] != '/'){
                temp += path[i];
                i++;
            }

            if(temp == ".") {
                continue;
            }
            else if(temp == ".."){
                if(!st.empty()){
                    st.pop();
                }
            }
            else{
                st.push(temp);
            }
        }

        while(!st.empty()){
            ans = '/' + st.top() + ans;
            st.pop();
        }

        if(ans.size() == 0){
            return "/";
        }

        return ans;
    }
};  Time Complexity (TC): O(n) , Space Complexity (SC): O(n)









Q1. 151. Reverse Words in a String

class Solution {
public:
    string reverseWords(string s) {

        vector<string> storeWords;
        string word = "";

        for(char ch : s){
            if(ch == ' '){
                if(!word.empty()){
                    storeWords.push_back(word);
                    word = "";
                }
            }
            else{
                word += ch;
            }
        }

        if(!word.empty()){
            storeWords.push_back(word);
        }

        reverse(storeWords.begin(), storeWords.end());

        string ans = "";

        for(int i = 0; i < storeWords.size(); i++) {
            if(i > 0){
                ans += ' ';
            }
            ans += storeWords[i];
        }
        return ans;
    }
};    TC and SC - o(n)

approach 2:

class Solution {
public:
    string reverseWords(string s) {

        reverse(s.begin(), s.end());

        int n = s.size();
        int left = 0;
        int right = 0;
        int i = 0;

        while(i < n){
            while(i < n && s[i] == ' ') i++;
            if(i == n) break;
            while(i < n && s[i] != ' '){
                s[right] = s[i];
                right++;
                i++;
            }
            reverse(s.begin()+left, s.begin()+right);
            s[right] = ' ';
            right++;
            left = right;
            i++;
        }
        s.resize(right-1);
        return s;
    }
};  TC - o(n), SC - o(1)


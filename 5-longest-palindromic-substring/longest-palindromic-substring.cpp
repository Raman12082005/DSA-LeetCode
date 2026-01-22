class Solution {
public:
    bool ispalindrome(string& str, int start, int end){
        while(start <= end){
            if(str[start] != str[end]) return false;
            start++;
            end--;
        }
        return true;
    }
    string longestPalindrome(string s) {

        if(s.size() == 1) return s;

        int maxlength = 1;
        int startingidx = 0;

        for(int i=0; i<s.size()-1; i++){
            for(int j=i+1; j<s.size(); j++){
                if(ispalindrome(s, i, j) && (j-i+1)> maxlength){
                    startingidx = i;
                    maxlength = j-i+1;
                }
            }
        }
        return s.substr(startingidx, maxlength);
    }
};
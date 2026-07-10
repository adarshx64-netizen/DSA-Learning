class Solution {
public:

    bool isCapital(char c) {

        if(c >= 'A' && c <= 'Z') return true;
        return false;
    }

    bool detectCapitalUse(string word) {
        bool f = false;
        int cnt = 0;
        
        for(int i = 0; i < word.size(); i++) {
            if(i == 0 && isCapital(word[i])) f = true;
            if(isCapital(word[i])) cnt++;
        }
        if(cnt == word.size() || word.size() == 1 || cnt == 0) return true;
        else if(f && cnt == 1) return true;
        return false;
    }
};
class Solution {
public:
/*
    • Instead of checking every combination (which is slow), we use a greedy technique that tracks the possible number of unmatched opening brackets:
        • We maintain a range [minOpen, maxOpen] to represent the minimum and maximum possible open brackets at each point in the string.
        • If we see a '(', both minOpen and maxOpen increase by 1.
        • If we see a ')', both minOpen and maxOpen decrease by 1.
        • If we see '*', it can behave like '(', ')' or be empty:
            • minOpen decreases by 1 (assuming '*'' acts like ')')
            • maxOpen increases by 1 (assuming '*' acts like '(')
        • If at any point maxOpen becomes negative, return false — too many closing brackets.
        • We also make sure minOpen doesn’t drop below 0 — because you can't have negative opening brackets.
*/

    bool optimal(string &s) {

        int maxOpen = 0, minOpen = 0;

        // Traverse each character in the string
        for (char c : s) {
            if (c == '(') {minOpen++; maxOpen++;}
            else if (c == ')') { minOpen--; maxOpen--;} 
            else {minOpen--; maxOpen++;}    // Treat '*' as '(', ')' or ''

            // If maxOpen goes negative, too many closing brackets
            if (maxOpen < 0) return false;

            // minOpen can't be negative
            minOpen = max(minOpen, 0);
        }

        // String is valid if all opens are closed
        return minOpen == 0;
    }

    // TC -> O(3^n) -> worsr case every no. replace by ' '.
    // SC -> O(n) -> recursive call stack
    // function to check if string is valid by trying all possibilities for '*'
    bool isValid(string& s, int i, int open) {

        // If open becomes negative, the string is invalid
        if (open < 0) return false;

        // If we reach the end, check if all opens are closed
        if (i == s.length()) return open == 0;

        // If current character is '(', treat it as an opening bracket
        if (s[i] == '(') return isValid(s, i + 1, open + 1);

        // If current character is ')', treat it as a closing bracket
        else if (s[i] == ')') return isValid(s, i + 1, open - 1);

        // If character is '*', try all 3 options and any one of those are true then return true
        else {
              // Treat '*' as empty
              // Treat '*' as '('
              // Treat '*' as ')'
            return isValid(s, i + 1, open) ||       
                   isValid(s, i + 1, open + 1) ||    
                   isValid(s, i + 1, open - 1);      
        }
    }

    bool checkValidString(string s) {
        
        return optimal(s);
        return isValid(s, 0, 0);
    }
};





















// // TC -> O(n)
// // SC -> O(1)

// class Solution {
// public:
//     bool checkValidString(string s) {
//         int l = 0, h = 0;

//     // Greedy Range Method: Track a range of possible open brackets:-
//         // low -> minimum open brackets
//         // high -> maximum open brackets

//         for(char c : s){
//             if(c == '('){
//                 l++;
//                 h++;
//             }
//             else if(c == ')'){
//                 l--;
//                 h--;
//             }
//             else{  // for '*'
//                 l--;    // treat as ')'
//                 h++;    // treat as '('
//                 // range from [l ,h] because l may be l-- or l (same) or l++ and h may be h-- or h (same) or h++ so range become [l, h]
//             }

//             if(h < 0) return false;  // too many ')'
//             if(l < 0) l = 0;     // can't go below 0
//         }

//         return l == 0;
//     }
// };
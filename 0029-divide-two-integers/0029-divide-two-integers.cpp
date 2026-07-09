class Solution {
public:

// Better: "Find the largest power every time." → needs an inner loop.
// Optimal: "Check each bit exactly once." → only one loop.

int optimal(int dividend, int divisor) {
    // Overflow case
    if (dividend == INT_MIN && divisor == -1) return INT_MAX;

    // Determine sign
    int sign = ((dividend < 0) ^ (divisor < 0)) ? -1 : 1;

    // Convert to positive
    long long n = llabs((long long)dividend);
    long long d = llabs((long long)divisor);

    long long q = 0;

    for(int i = 31; i >= 0; i--) {

        if(n >= (d << i)) {

            n -= (d << i);
            q += (1LL << i);
        }
    }
    return sign * q;
}


/*
Better :-
    • Idea -> Instead of subtracting ine divisor at a time, Subtract (2^0)*divisor, (2^1)*divisor, (2^2)*divisor, and so on... (using left shift)
    • Example :- 100/3
        3×1 = 3
        3×2 = 6
        3×4 = 12
        3×8 = 24
        3×16 = 48
        3×32 = 96   <-- largest <=100

        Subtract 100 - 96 = 4, 
        Quotient = 32, Now 4/3 and ans += 1
        Final answer will be 32+1
*/
// TC ≈ O((log N)²)
// SC ≈ O(1)
// TC -> O((log N)^2)
// SC -> O(1)

int better(int dividend, int divisor) {

    // Overflow case:
    if (dividend == INT_MIN && divisor == -1) return INT_MAX;

    // Determine the sign of the answer.
    int sign = ((dividend < 0) ^ (divisor < 0)) ? -1 : 1;

    // Convert both numbers to positive.
    // Cast to long long first because abs(INT_MIN) overflows for int.
    long long n = llabs((long long)dividend);
    long long d = llabs((long long)divisor);

    long long quotient = 0;

    // Keep subtracting the largest possible multiple of divisor.
    while (n >= d) {

        int cnt = 0;

        // Find the largest power of 2 such that
        // (divisor * 2^(cnt+1)) <= dividend
        //
        // Example:
        // n = 100, d = 3
        //
        // 3 * 2^0 = 3
        // 3 * 2^1 = 6
        // 3 * 2^2 = 12
        // 3 * 2^3 = 24
        // 3 * 2^4 = 48
        // 3 * 2^5 = 96  <-- largest valid
        while (n >= (d << (cnt + 1))) cnt++;   // d << (cnt+1) = d * (2 ^ (cnt+1))

        // Add 2^cnt to the quotient.
        quotient += (1LL << cnt);

        // Remove this multiple from the dividend.
        n -= (d << cnt);
    }

    // Apply the correct sign.
    return sign * quotient;
}


/*
Brute Force :- 
    • Idea -> Keep subtracting divisor from dividend until the dividend becomes smaller.
    • Example :- 15 / 3
        15 -> 12 -> 9 -> 6 -> 3 -> 0 (Subtracted 5 times)
        Answer = 5
*/
    int divide(int dividend, int divisor) {
        
        // return better(dividend, divisor);
        return optimal(dividend, divisor);
    }
};
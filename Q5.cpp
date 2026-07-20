class Solution {
public:
    string longestPalindrome(string s) {
        
        // DP
        int size = s.length();
        int M[size][size];
        
        int best = -10000;
        int best_i = 0;
        int best_j = 0;

        // init
        for (int i = 0; i < size; i++){
            for (int j = 0; j < size; j++){
                M[i][j] = 1;
            }
        }

        for (int i = size - 1; i >= 0; i--){
            for (int j = size - 1; j >= i; j--){
                //cout << "i:" << i << ", j:" << j << endl;
                if (i == j){
                    M[i][j] = 1;
                }
                else if (s[i] == s[j] && M[i+1][j-1] >= 1){
                    M[i][j] = (j - i) + 1;
                }
                else
                    M[i][j] = 0;
                // sol'n recovery
                if (M[i][j] > best){
                    best = M[i][j];
                    best_i = i;
                    best_j = j;
                }    
            }
        }

        return s.substr(best_i, best);


    }
};
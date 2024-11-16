
class Solution {
public:
    int dp[501][51][2][2];
   
    int solve(int i , int MatchedEvil , bool LeftBound, bool RightBound, int n, string &s1, string &s2, string &evil,vector<int> &lps) {
         if (MatchedEvil==evil.length()) return 0;
         if (i==n) return 1;
         if (dp[i][MatchedEvil][LeftBound][RightBound]!=-1) return dp[i][MatchedEvil][LeftBound][RightBound];
         char from = LeftBound ? s1[i] : 'a';
         char to = RightBound ? s2[i] : 'z';
         int result = 0;
         for (char ch = from ; ch<=to ; ch++) {
            int j = MatchedEvil;
            while (j>0 && ch != evil[j]) j = lps[j-1];
            if (ch==evil[j]) j++;
            result += solve(i+1,j,LeftBound && (ch==from),RightBound && (ch==to),n,s1,s2,evil,lps) ;
            result %= 1000000007;

         }
         return dp[i][MatchedEvil][LeftBound][RightBound] = result;
    }
    int findGoodStrings(int n, string s1, string s2, string evil) {
        vector<int> lps(evil.length());
        
        lps = fillLPS(evil);
        int result =  solve(0,0,true,true,n,s1,s2,evil,lps);
        return result;
    }
    vector<int> fillLPS(const string& str) { // Longest Prefix also Suffix
        int n = str.size();
         memset(dp,-1,sizeof(dp));
        vector<int> lps = vector<int>(n);
        for (int i = 1, j = 0; i < n; i++) {
            while (j > 0 && str[i] != str[j]) j = lps[j - 1];
            if (str[i] == str[j]) lps[i] = ++j;
        }
        return lps;
    }
};

class Solution {
public:

    int f(int i, int j, string s, string t){
        if(i < 0) return j + 1;
        if(j < 0) return i + 1;

        if(s[i] == t[j]) return 0 + f(i-1, j-1, s, t);

        return min( (1 + f(i, j-1, s, t)) , min((1 + f(i-1, j, s, t)),(1 + f(i-1, j-1, s, t))));
    }

    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();

        return f(m-1, n-1, word1, word2);
    }
};

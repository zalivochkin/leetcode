
class Solution {
public:
    int find(vector<int> &p, int x) {
        if (p[x] != x)
            p[x] = find(p, p[x]);
        return p[x];
    }

    string smallestEquivalentString(string s1, string s2, string baseStr) {
        vector<int> p(26);
        for (int i = 0; i < 26; ++i)
            p[i] = i;
        for (int i = 0; i < s1.size(); ++i) {
            int a = s1[i] - 'a';
            int b = s2[i] - 'a';
            int pa = find(p, a);
            int pb = find(p, b);
            if (pa < pb)
                p[pb] = pa;
            else
                p[pa] = pb;
        }
        string res = "";
        for (char a : baseStr) {
            char b = (char) (find(p, a - 'a') + 'a');
            res += b;
        }
        return res;
    }
};

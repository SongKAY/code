class Solution {
public:
    string shiftingLetters(string S, vector<int>& shifts) {
        int n = shifts.size();
        vector<int> sum(n,0);
        sum[n-1] = shifts[n-1];
        for(int i=n-2;i>=0;i--)
            sum[i] = sum[i+1] + shifts[i]%26;
        vector<char> result;
        for(int i=0;i<n;i++){
            result.push_back((S[i]-'a' + sum[i])%26 + 'a');
        }
        string temp;
        for(int i=0;i<n;i++)
            temp += result[i];
        return temp;
    }
};

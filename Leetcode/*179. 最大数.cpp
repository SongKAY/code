class Solution {
public:
    static bool cmp(string a,string b){
        return a+b > b+a;
    }
    string largestNumber(vector<int>& nums) {
        if(nums.empty())
            return "";
        int zero = 0;
        vector<string> temp;
        for(auto i:nums){
            temp.push_back(to_string(i));
            if(i==0)
                zero ++;
        }
        if(zero==nums.size())
            return "0";
        sort(temp.begin(),temp.end(),cmp);
        string result = "";
        for(auto s:temp)
            result += s;
        return result;
    }
};

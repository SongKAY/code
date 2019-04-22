class Solution {
public:
    struct Node{
      vector<int> pos;
        int dis;
    };
    static bool cmp(Node &a,Node &b){
        return a.dis<b.dis;
    }
    vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
       vector<Node> temp;
        for(int i=0;i<R;i++){
            for(int j=0;j<C;j++){
                Node a;
                a.pos.push_back(i);
                a.pos.push_back(j);
                int dis = abs(i-r0) + abs(j-c0);
                a.dis=dis;
                temp.push_back(a);
            }
        }
        sort(temp.begin(),temp.end(),cmp);
        vector<vector<int>> result;
        for(int i=0;i<temp.size();i++){
            result.push_back(temp[i].pos);
        }
        return result;
    }
};

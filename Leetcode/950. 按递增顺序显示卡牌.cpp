class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        vector<int> result;
        if(deck.empty())
            return result;
        sort(deck.begin(),deck.end());
        int n = deck.size();
        deque<int> q;
        q.push_front(deck[deck.size()-1]);
        for(int i=n-2;i>=0;i--){
            q.push_front(q.back());
            q.pop_back();
            q.push_front(deck[i]);
        }
        return vector<int>(q.begin(),q.end());
    }
};

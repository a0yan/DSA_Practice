class Solution {
public:
    void recursion(vector<int> num, int i, int j, vector<vector<int> > &res) {
        if (i == j) {
            res.push_back(num);
            return;
        }
        for (int k = i; k < j; k++) {
            if (i != k && num[i] == num[k]){
                continue;    
            }
            else{
            swap(num[i], num[k]);
            recursion(num, i+1, j, res);

            }
            
            

            
        }
    }
    vector<vector<int> > permuteUnique(vector<int> &num) {
        sort(num.begin(), num.end());
        vector<vector<int> >res;
        recursion(num, 0, num.size(), res);
        return res;
    }
};
// Also refer to
//https://www.youtube.com/watch?v=is_T6uzlTyg&t=219s&ab_channel=Fraz

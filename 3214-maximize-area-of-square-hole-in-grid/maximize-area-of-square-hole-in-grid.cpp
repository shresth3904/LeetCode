class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        sort(hBars.begin(), hBars.end());
        sort(vBars.begin(), vBars.end());
        
        int hseq = 1;
        int max_h = 1;
        for (int i = 1; i < hBars.size(); i++){
            if (hBars[i-1]+1 == hBars[i]) hseq++;
            else {
                hseq = 1;
            }
            max_h = max(hseq, max_h);
        }
        max_h = max(hseq, max_h);

        int vseq = 1;
        int max_v = 1;
        for (int i = 1; i < vBars.size(); i++){
            if (vBars[i-1]+1 == vBars[i]) vseq++;
            else {
                vseq = 1;
            }
            max_v = max(vseq, max_v);
        }

        max_v = max(vseq, max_v);


        return (min(max_h, max_v)+1)*(min(max_h, max_v)+1);
    }
};
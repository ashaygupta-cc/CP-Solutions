class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        
        priority_queue<pair<double , pair<int , int>>> pq; 
        double sum = 0;

        for(auto it: classes){
            sum += (double)it[0] / (double)it[1];
        }

        if(extraStudents == 0) return sum / classes.size();

        double mxGain = 0;
        int idx = 0;
        for(int i=0;i<classes.size();i++){
            double gain = (double)(classes[i][1] - classes[i][0]) / ((double)classes[i][1] * (classes[i][1] + 1));
            if(gain > mxGain){
                mxGain = gain;
                idx = i;
            }
        }

        extraStudents--;
        sum += mxGain;
        classes[idx][0]++;
        classes[idx][1]++;

        for(int i=0;i<classes.size();i++){
            double gain = (double)(classes[i][1] - classes[i][0])/((double)classes[i][1] * (classes[i][1] + 1));
            pq.push({gain , {classes[i][0] , classes[i][1]}});
        }

        while(extraStudents > 0){
            auto it = pq.top();
            pq.pop();
            double curr = it.first;
            int p = it.second.first;
            int q = it.second.second;

            sum += curr;

            p++;
            q++;
            curr = (double)(q - p) / ((double)q * (q + 1));

            pq.push({curr , {p , q}});
            extraStudents--;
        }

        return sum / classes.size();
    }
};
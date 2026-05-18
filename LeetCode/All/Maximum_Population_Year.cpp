class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        vector<int> population(2051, 0);
        int n = logs.size();
        
        for (int i = 0; i < n; ++i) {
            int birth = logs[i][0];
            int death = logs[i][1];
            for (int year = birth; year < death; year++) {
                population[year]++;
            }
        }

        int max_population = 0;
        int max_year = -1;
        for (int year = 1950; year <= 2050; year++) {
            if (population[year] > max_population) {
                max_population = population[year];
                max_year = year;
            }
        }

        return max_year;
    }
};

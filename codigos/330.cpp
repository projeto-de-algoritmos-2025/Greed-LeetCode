#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long long miss = 1;      // menor valor que ainda não podemos formar
        int patches = 0;         // número de patches adicionados
        size_t i = 0;            // índice para percorrer nums
        long long N = (long long)n;

        while (miss <= N) {
            // se o próximo elemento cabe no alcance atual usa
            if (i < nums.size() && nums[i] <= miss) {
                miss += nums[i];
                ++i;
            }
            else {
                // caso contrário, patch de valor 'miss'
                miss += miss;
                ++patches;
            }
        }
        return patches;
    }
};


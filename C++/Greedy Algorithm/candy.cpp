#include <vector>
#include <numeric>

int candy(std::vector<int>& ratings) {
        // Greedy strategy:
        // When traverse through the vector, only consider one side (left/right) rating
        // relationships
        
        int size = ratings.size();
        if (size < 2) return size;
        std::vector<int> num(size, 1);
        
        // traverse from left to right, comparing with LEFT neighbour
        for (int i = 1; i != size; ++i) {
            if (ratings[i] > ratings[i-1]) 
                num[i] = num[i-1] + 1;
        }
        
        // traverse from right to left, comparing with RIGHT neighbour
        for (int i = size-1; i != 0; --i) {
            if (ratings[i-1] > ratings[i]) 
                num[i-1] = std::max(num[i-1], num[i] + 1);
        }
        
        return std::accumulate(num.begin(), num.end(), 0);
        
    }
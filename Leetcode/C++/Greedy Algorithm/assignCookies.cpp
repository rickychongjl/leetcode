#include <vector>
int findContentChildren(std::vector<int>& g, std::vector<int>& s) {
     // In the remaining children, give the child with the least greed factor a cookie 
     // with the smallest size among those that can content the child
    sort(g.begin(), g.end());
    sort(s.begin(), s.end());
    int child = 0, cookie = 0;
        
    while (child < g.size() && cookie < s.size()) {
         if (g[child] <= s[cookie]) ++child;
         ++cookie;
    }
     
    return child;
}

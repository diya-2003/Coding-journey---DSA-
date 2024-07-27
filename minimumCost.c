#include <stdio.h>
#include <string.h>
#include <limits.h>

long long minimumCost(char* source, char* target, char* original, int originalSize, char* changed, int changedSize, int* cost, int costSize) {
    int n = strlen(source);
    int g[27][27];
    long long ans = 0;
    memset(g, -1, sizeof(g));
    
    for (int i = 0; i < costSize; i++) {
        if (g[original[i] - 'a'][changed[i] - 'a'] == -1) {
            g[original[i] - 'a'][changed[i] - 'a'] = cost[i];
        } else {
            g[original[i] - 'a'][changed[i] - 'a'] =
                (g[original[i] - 'a'][changed[i] - 'a'] < cost[i]) ? g[original[i] - 'a'][changed[i] - 'a'] : cost[i];
        }
    }
    
    for (int k = 0; k < 26; k++) {
        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < 26; j++) {
                if (i == j)
                    g[i][j] = 0;
                else if (g[i][k] != -1 && g[k][j] != -1) {
                    if (g[i][j] == -1)
                        g[i][j] = g[i][k] + g[k][j];
                    else
                        g[i][j] = (g[i][j] < g[i][k] + g[k][j]) ? g[i][j] : (g[i][k] + g[k][j]);
                }
            }
        }
    }
    
    for (int i = 0; i < n; i++) {
        if (g[source[i] - 'a'][target[i] - 'a'] == -1)
            return -1;
        ans += g[source[i] - 'a'][target[i] - 'a'];
    }
    return ans;
}

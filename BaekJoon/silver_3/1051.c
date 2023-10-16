#include <stdio.h>

int main() {
    int n, m, map[60][60];
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%1d", &map[i][j]);
    
    int max = n < m ? n : m;
    int ret = 1;
 
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int k = 1; k <= max; k++) {
                if (i + k < n && j + k < m && map[i][j] == map[i + k][j] 
                    && map[i + k][j] == map[i][j + k]
                    && map[i][j + k] == map[i + k][j + k]) {
                    if (ret < (k + 1)*(k + 1)) ret = (k + 1)*(k + 1);
                }
            }
        }
    }
    printf("%d", ret);
    return 0;
}
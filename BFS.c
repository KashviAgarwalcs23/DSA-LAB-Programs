#include <stdio.h>

int n, a[10][10];
int vis[10];
int q[10];
int f = 0, r = 0;

void bfs(int v) {
    int u, j;
    q[r++] = v;
    vis[v] = 1;

    while (f < r) {
        u = q[f++];
        printf("%d ", u);
        for (j = 0; j < n; j++) {
            if (a[u][j] == 1 && !vis[j]) {
                q[r++] = j;
                vis[j] = 1;
            }
        }
    }
}

int main() {
    int i, j, src;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    printf("Enter the adjacency matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    for (i = 0; i < n; i++) {
        vis[i] = 0;
    }
    printf("Enter the source vertex: ");
    scanf("%d", &src);
    printf("The vertices reachable from source %d are: ", src);
    bfs(src);

    return 0;
}

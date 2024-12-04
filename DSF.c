#include <stdio.h>

int n, a[10][10];
int vis[10], in_stack[10];
int dfs(int v) {
    vis[v] = 1;
    in_stack[v] = 1;

    for (int j = 0; j < n; j++) {
        if (a[v][j] == 1) {
            if (!vis[j] && dfs(j)) {
                return 1;
            }
            else if (in_stack[j]) {
                return 1;
            }
        }
    }

    in_stack[v] = 0;
    return 0;
}

int is_connected() {
    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            return 0;
        }
    }
    return 1;
}

int main() {
    int i, j;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    printf("Enter the adjacency matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
        vis[i] = 0;
        in_stack[i] = 0;
    }
    int cycle_found = 0;
    for (i = 0; i < n; i++) {
        if (!vis[i]) {
            if (dfs(i)) {
                cycle_found = 1;
                break;
            }
        }
    }
    if (cycle_found) {
        printf("The graph contains a cycle.\n");
    } else {
        printf("No cycle detected in the graph.\n");
    }

    if (is_connected()) {
        printf("The graph is connected.\n");
    } else {
        printf("The graph is not connected.\n");
    }

    return 0;
}

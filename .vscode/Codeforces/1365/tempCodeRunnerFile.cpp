for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (vis[i][j])
                printf("1 ");
            else
                printf("0 ");
        }
        puts("");
    }
for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= m; j ++)
            if (mp[i][j] == mp[i - 1][j])
                up[i][j] = min(up[i - 1][j], l[i][j - 1], r[i][j + 1]);
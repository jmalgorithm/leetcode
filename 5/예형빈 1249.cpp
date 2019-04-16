#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n;
int arr[100][100];
int dp[100][100];
int main() {
    int test_case;
    void clear();
    int find(int x, int y);
    cin >> test_case;
    for (int test = 1; test <= test_case; test++) {
        cin >> n;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                scanf("%1d", &arr[i][j]);
        clear();
        dp[0][0] = 0;
        find(0, 0);
 
        cout <<"#"<<test<<" " << dp[n - 1][n - 1]<<"\n";
    }
    return 0;
}
 
void clear() {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            dp[i][j] = 10000;
}
 
int find(int x, int y) {
    //printf("%d %d\n", x, y);
    if (x < 0 || y < 0 || x >= n || y >= n)
        return 0;
    if (x == n - 1 && y == n - 1)
    /*{
        if (dp[x - 1][y] != -1)
            if (dp[x][y - 1] != -1)*/
                return dp[x][y] = min(dp[x - 1][y], dp[x][y - 1]);
            /*else
                return dp[x - 1][y];
        else
            if (dp[x][y - 1] != -1)
                return dp[x][y - 1];
    }*/
    int a = 10000, b = 10000, c = 10000, d = 10000;
    if (x - 1 >= 0)
        a = dp[x - 1][y];
    if (y - 1 >= 0)
        b = dp[x][y - 1];
    if (x + 1 < n)
        c = dp[x + 1][y];
    if (y + 1 < n)
        d = dp[x][y + 1];
    //printf("%d %d %d %d\n", a, b, c, d);
    if (a != 10000 || b != 10000 || c != 10000 || d != 10000)
        dp[x][y] = min({ a,b,c,d }) + arr[x][y];
 
    if (a== 10000 || (a != 10000 && a > dp[x][y] + arr[x - 1][y]))
        find(x - 1, y);
    if (b== 10000 ||(b != 10000 && b > dp[x][y] + arr[x][y - 1]))
        find(x, y - 1);
    if (c== 10000 ||(c != 10000 && c > dp[x][y] + arr[x + 1][y]))
        find(x + 1, y);
    if (d== 10000 ||(d != 10000 && d > dp[x][y] + arr[x][y + 1]))
        find(x, y + 1);
}

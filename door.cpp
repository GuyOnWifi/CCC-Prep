# include <bits/stdc++.h>
using namespace std;

int n,m,k;
long long arr[5001][5001];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> n >> m >> k;
    for(int br = 0; br < k; br++){
        int xi, yi, XI,YI;
        cin >> xi >> yi >> XI >> YI;
        for(int i = xi; i <= XI; i++){
            for(int j =yi; j <= YI; j++){
                arr[j][i] += 1;
            }
        }
    }
    for(int i = 1; i <= m; i++){
        for(int j = 0; j <= n; j++){
            arr[i][j] += arr[i-1][j] + arr[i][j-1] - arr[i-1][j-1];
            }
    }
    int q;
    cin >> q;
    for(int br = 0; br < q; br++){
        int a,b,c,d;
        cin >> a >> b >> c >> d;
        int eb;
        eb = arr[d][c]  + arr[b-1][a-1] - arr[d][a-1] - arr[b-1][c];
        cout << eb << "\n";
    }
    return 0;
}

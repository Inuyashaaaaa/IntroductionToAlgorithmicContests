// #include<bits/stdc++.h>
// #define LL long long
// using namespace std;
// const int maxn = 1e5 + 5;

// int main() {
//     freopen("in.txt", "r", stdin);
//     freopen("out.txt", "w", stdout);
//     ios::sync_with_stdio(false);
//     cin.tie(0);
//     int n;
//     cin >> n;
//     int a[maxn];
//     for(int i = 0; i < n; i++) {
//         cin >> a[i];
//     }
//     int cnt = 1;
//     int maxn = cnt;
//     for(int i = 1; i < n; i++) {
//         if(a[i + 1] > a[i]) {
//             cnt++;
//         } else {
//             cnt = 1;
//         }
//         maxn = max(cnt, maxn);
//     }
//     return 0;
// }
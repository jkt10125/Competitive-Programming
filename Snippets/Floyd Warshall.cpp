#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> FloydWarshall(vector<vector<int>> &A) {
    int n = A.size();
    vector<vector<int>> dist = A;
    vector<vector<int>> path(n, vector<int> (n, -1));
    for(int k=0; k<n; k++) {
        for(int i=0; i<n; i++) {
            if(dist[i][k] >= INT_MAX) continue;
            for(int j=0; j<n; j++) {
                if(dist[k][j] >= INT_MAX) continue;
                if(dist[i][j] > dist[i][k] + dist[k][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    path[i][j] = k;
                }
            }
        }
    }
    return dist;
}
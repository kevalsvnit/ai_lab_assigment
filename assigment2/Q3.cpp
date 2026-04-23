#include<bits/stdc++.h>
using namespace std;
int cnt=1;
int cnt1=1;
vector<string> city = {
    "Chicago","Indianapolis","Columbus","Cleveland","Detroit",
    "Buffalo","Pittsburgh","Baltimore","Philadelphia",
    "New York","Boston","Providence","Syracuse","Portland"
};

long long mbfs=0;
long long mdfs=0;

const int INF = 1e9;
int n = 14;
vector<vector<int>> dist(n,vector<int>(n,INF));
vector<vector<pair<int,int>>> adj(n);


void BFS(int src,int dest){
    queue<pair<vector<int>,int>> q;
    q.push({{src},0});

    while(!q.empty()){
        auto path=q.front().first;
        auto cost=q.front().second;
        q.pop();

        int last=path.back();

        if(last==dest){
            cout<<cnt++<<" => ";
            int total = 0;

            for(int i=0;i+1<path.size();i++){
                int u = path[i];
                int v = path[i+1];
                int wt = dist[u][v];

                cout<<city[u]<<"->("<<wt<<") ";
                total += wt;
            }

            cout<<city[dest]<<"   TOTAL = "<<total<<endl;
            continue;
        }
for (int i = 0; i < adj[last].size(); i++) {
    int next = adj[last][i].first;
    int wt   = adj[last][i].second;

    mbfs += wt;

    bool visited = false;
    for (int j = 0; j < path.size(); j++) {
        if (path[j] == next) {
            visited = true;
            break;
        }
    }

    if (!visited) {
        vector<int> newpath = path;
        newpath.push_back(next);
        q.push(make_pair(newpath, cost + wt));
    }
}

    }
}


void DFS(int curr,int dest, vector<int>&path,int cost,vector<bool>&visited){
    if(curr==dest){
        cout<<cnt1++<<" => ";
        int total = 0;

        for(int i=0;i+1<path.size();i++){
            int u = path[i];
            int v = path[i+1];
            int wt = dist[u][v];

            cout<<city[u]<<"->("<<wt<<") ";
            total += wt;
        }

        cout<<city[dest]<<"   TOTAL = "<<total<<endl;
        mdfs+=total;
        return;
    }

    visited[curr]=true;

    for (int i = 0; i < adj[curr].size(); i++) {
    int next = adj[curr][i].first;
    int wt   = adj[curr][i].second;

    if (!visited[next]) {
        path.push_back(next);
        DFS(next, dest, path, cost + wt, visited);
        path.pop_back();   // backtracking
    }
}


    visited[curr]=false;
}

int main() {
    for(int i = 0; i < n; i++)
        dist[i][i] = 0;
    dist[0][4] = dist[4][0] = 283;
    dist[0][3] = dist[3][0] = 345;
    dist[0][1] = dist[1][0] = 182;
    dist[1][2] = dist[2][1] = 176;
    dist[2][3] = dist[3][2] = 144;
    dist[2][6] = dist[6][2] = 185;
    dist[3][4] = dist[4][3] = 169;
    dist[3][6] = dist[6][3] = 134;
    dist[3][5] = dist[5][3] = 189;
    dist[4][5] = dist[5][4] = 256;
    dist[5][12] = dist[12][5] = 150;
    dist[5][6] = dist[6][5] = 215;
    dist[6][8] = dist[8][6] = 305;
    dist[6][7] = dist[7][6] = 247;
    dist[7][8] = dist[8][7] = 101;
    dist[8][9] = dist[9][8] = 97;
    dist[8][12] = dist[12][8] = 253;
    dist[9][10] = dist[10][9] = 215;
    dist[9][11] = dist[11][9] = 181;
    dist[10][11] = dist[11][10] = 50;
    dist[10][13] = dist[13][10] = 107;
    dist[12][10] = dist[10][12] = 312;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(dist[i][j]!=INF && i!=j){
                adj[i].push_back({j,dist[i][j]});
            }
        }
    }
    int src = 12; // Syracuse
    int dest = 0; // Chicago
    cout << "\nBFS Paths from Syracuse to Chicago:\n";

    BFS(src,dest);
    cout<<endl;
    cout << "\nDFS Paths from Syracuse to Chicago:\n";
    vector<bool> visited(n, false);
    vector<int> path = {src};
    DFS(src, dest, path, 0, visited);


    cout<< endl<<endl<<mbfs<<endl<<mdfs;
    return 0;
}
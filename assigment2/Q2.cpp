#include<bits/stdc++.h>
using namespace std;

unordered_set<string> visited;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {-1, 1, 0, 0};

int explored = 0;
bool found = false;
void dfs(string cur, string goal, int depth, int maxDepth) {
    if (found || depth > maxDepth) return;

    visited.insert(cur);
    explored++;

    if (cur == goal) {
        found = true;
        return;
    }

    int pos = cur.find('0');
    int x = pos / 3, y = pos % 3;

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if (nx >= 0 && nx < 3 && ny >= 0 && ny < 3) {
            string next = cur;
            swap(next[x*3 + y], next[nx*3 + ny]);

            if (!visited.count(next)) {
                dfs(next, goal, depth + 1, maxDepth);
            }
        }
    }
}


int main() {
    string start = "724506831";
    string goal  = "012345678";

    visited.clear();
    explored = 0;
    found = false;

    dfs(start, goal,0,30);

    if (found)
        cout << "States explored using DFS: " << explored << endl;
    else
        cout << "Goal not found. States explored: " << explored << endl;

    return 0;
}

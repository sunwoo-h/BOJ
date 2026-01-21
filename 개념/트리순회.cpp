#include <bits/stdc++.h>
using namespace std;

vector<int> adj[1004];
int visited[1004];

void postOrder(int here) {
    if (visited[here] == 0) {
        if (adj[here].size() == 1) // 자식 노드 1개일때
            postOrder(adj[here][0]);

        if (adj[here].size() == 2) { // 자식 노드 2개일때
            postOrder(adj[here][0]);
            postOrder(adj[here][1]);
        }

        visited[here] = 1; // 자기 자신 마지막
        cout << here << ' ';
    }
}

void preOrder(int here) {
    if (visited[here] == 0) {
        visited[here] = 1; // 자기 자신 처음
        cout << here << ' ';

        if (adj[here].size() == 1) // 자식 노드 1개일때
            preOrder(adj[here][0]);

        if (adj[here].size() == 2) { // 자식 노드 2개일때
            preOrder(adj[here][0]);
            preOrder(adj[here][1]);
        }
    }
}

void inOrder(int here) {
    if (visited[here] == 0) {
        if (adj[here].size() == 1) { // 자식 노드 1개일때
            inOrder(adj[here][0]);
            visited[here] = 1; 
            cout << here << ' ';
        }
        else if (adj[here].size() == 2) { // 자식 노드 2개일때
            inOrder(adj[here][0]);
            visited[here] = 1; // 자기 자신 중간
            cout << here << ' ';
            inOrder(adj[here][1]);
        }
        else {
            visited[here] = 1; 
            cout << here << ' ';
        }
    }
}

int main() {
    adj[1].push_back(2);
    adj[1].push_back(3);
    adj[2].push_back(4);
    adj[2].push_back(5);

    int root = 1;

    cout << "\n 트리순회 : postOrder \n";
    postOrder(root);
    memset(visited, 0, sizeof(visited));

    cout << "\n 트리순회 : preOrder \n";
    preOrder(root);
    memset(visited, 0, sizeof(visited));

    cout << "\n 트리순회 : inOrder \n";
    inOrder(root);

    return 0;
}

/*
트리순회 : postOrder
4 5 2 3 1

트리순회 : preOrder
1 2 4 5 3

트리순회 : inOrder
4 2 5 1 3
*/
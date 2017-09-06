#include <bits/stdc++.h>

using namespace std;

void printInOrder(int node, vector<pair<pair<int, int>, int>> nodes)
{
    int leftNode = nodes[node].first.first;
    int rightNode = nodes[node].first.second;

    if (leftNode != -1) {
        printInOrder(leftNode, nodes);
    }

    cout << node + 1 << ' ';

    if (rightNode != -1) {
        printInOrder(rightNode, nodes);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);

    int n;
    cin >> n;

    vector<pair<pair<int, int>, int>> nodes(n);
    for (int i = 0; i < n; i++) {
        cin >> nodes[i].first.first >> nodes[i].first.second;

        if (nodes[i].first.first != -1) {
            nodes[i].first.first--;
        }
        if (nodes[i].first.second != -1) {
            nodes[i].first.second--;
        }
    }
    nodes[0].second = 1;

    queue<int> nodeQueue;
    nodeQueue.push(0);

    while (!nodeQueue.empty()) {
        int node = nodeQueue.front();
        nodeQueue.pop();

        int leftNode = nodes[node].first.first;
        int rightNode = nodes[node].first.second;

        if (leftNode != -1) {
            nodes[leftNode].second = nodes[node].second + 1;
            nodeQueue.push(leftNode);
        }
        if (rightNode != -1) {
            nodes[rightNode].second = nodes[node].second + 1;
            nodeQueue.push(rightNode);
        }
    }

    int t;
    cin >> t;

    while (t--) {
        int k;
        cin >> k;

        nodeQueue.push(0);

        while (!nodeQueue.empty()) {
            int node = nodeQueue.front();
            nodeQueue.pop();

            if (nodes[node].second % k == 0) {
                swap(nodes[node].first.first, nodes[node].first.second);
            }

            int leftNode = nodes[node].first.first;
            int rightNode = nodes[node].first.second;

            if (leftNode != -1) {
                nodeQueue.push(leftNode);
            }
            if (rightNode != -1) {
                nodeQueue.push(rightNode);
            }
        }

        printInOrder(0, nodes);
        cout << '\n';
    }
}

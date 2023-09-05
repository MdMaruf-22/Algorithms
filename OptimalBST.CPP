#include <iostream>
#include <vector>
#include<bits/stdc++.h>
using namespace std;

struct Node {
    int key;
    Node* left;
    Node* right;
};

Node* createNode(int key) {
    Node* newNode = new Node();
    newNode->key = key;
    newNode->left = newNode->right = nullptr;
    return newNode;
}

Node* insertNode(Node* root, int key) {
    if (root == nullptr) {
        return createNode(key);
    }
    if (key < root->key) {
        root->left = insertNode(root->left, key);
    } else if (key > root->key) {
        root->right = insertNode(root->right, key);
    }
    return root;
}

Node* constructBST(int keys[], int n) {
    Node* root = nullptr;
    for (int i = 0; i < n; i++) {
        root = insertNode(root, keys[i]);
    }
    return root;
}
int countBSTs(int n) {
    if (n <= 1) {
        return 1;
    }

    int count = 0;

    for (int i = 1; i <= n; i++) {
        int leftCount = countBSTs(i - 1);
        int rightCount = countBSTs(n - i);
        count += leftCount * rightCount;
    }

    return count;
}
double calculateCost(Node* root, double pi, double qi) {
    if (root == nullptr) {
        return 0;
    }
    double leftCost = calculateCost(root->left, pi, qi);
    double rightCost = calculateCost(root->right, pi, qi);
    return pi + qi + leftCost + rightCost;
}
double optimalBSTCost(const vector<double>& P, const vector<double>& Q) {
    int n = P.size();
    vector<vector<double>> cost(n + 1, vector<double>(n + 1, 0.0));
    for (int i = 0; i < n; i++) {
        cost[i][i] = Q[i];
    }
    vector<double> prefixSum(n + 1, 0.0);
    for (int i = 1; i <= n; i++) {
        prefixSum[i] = prefixSum[i - 1] + P[i - 1] + Q[i - 1];
    }
    for (int L = 2; L <= n; L++) {
        for (int i = 0; i <= n - L + 1; i++) {
            int j = i + L - 1;
            cost[i][j] = INT_MAX;
            double sum = prefixSum[j + 1] - prefixSum[i];
            for (int k = i; k <= j; k++) {
                double c = sum + (k - i - 1 >= 0 ? cost[i][k - 1] : 0) + (k + 1 <= j ? cost[k + 1][j] : 0);
                if (c < cost[i][j]) {
                    cost[i][j] = c;
                }
            }
        }
    }
    return cost[0][n - 1];
}
int main() {
    cout << "How many keys: ";
    int n;
    cin >> n;

    int keys[n];
    cout << "Enter the keys:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> keys[i];
    }
    vector<int> pi1(n),qi1(n);
    cout<<"Enter values of pi: "<<endl;
    for(int i=0;i<n;i++) cin>>pi1[i];
    cout<<"Enter values of qi: "<<endl;
    for(int i=0;i<n;i++) cin>>qi1[i];
    cout<<countBSTs(4)<<endl;
    double pi, qi;
    cout << "Enter the value of Pi: ";
    cin >> pi;
    cout << "Enter the value of Qi: ";
    cin >> qi;
    Node* root = constructBST(keys, n);
    double cost = calculateCost(root, pi, qi);
    cout << "Cost of the binary search tree: " << cost << endl;
    
    return 0;
}

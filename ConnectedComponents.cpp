#include<bits/stdc++.h>
using namespace std;
const int N=1e7+10;
vector<int> tree[N];
bool vis[N];
void dfs(int vertex)
{
    vis[vertex]=true;
    for(auto child:tree[vertex]){
        if(vis[child]) continue;
        dfs(child);
    }
}
int main()
{
    int n,e;
    cin>>n>>e;
    for(int i=0;i<e;i++){
        int v1,v2;
        cin>>v1>>v2;
        tree[v1].push_back(v2);
        tree[v2].push_back(v1);
    }
    int cnt=0;
    for(int i=1;i<=n;i++){
        if(vis[i]) continue;
        dfs(i);
        cnt++;
    }
    cout<<cnt<<endl;
}

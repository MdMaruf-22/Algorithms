#include<bits/stdc++.h>
using namespace std;
const int N=1e7+10;
vector<int> graph[N];
bool vis[N];
int ti=0;
vector<pair<int,int>> vc(N);
void dfs(int vertex)
{
    vis[vertex]=true;
    ti+=1;
    vc[vertex].first=ti;
    
    for(auto child:graph[vertex]){
        if(vis[child]) continue;
        dfs(child);
    }
    ti+=1;
    vc[vertex].second=ti;
}
int main()
{
    int n,e;
    cin>>n>>e;
    for(int i=0;i<e;i++){
        int v1,v2;
        cin>>v1>>v2;
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }
    cout<<"Enter root to DFS: ";
    int root;cin>>root;
    dfs(root);
    for(int i=1;i<=n;i++) cout<<vc[i].first<<" "<<vc[i].second<<endl;
}

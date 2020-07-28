#include <bits/stdc++.h>
using namespace std;
class sample {
public:
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        unordered_map<int,vector<int>> umap;
        for(auto x:dislikes){
            umap[x[0]].push_back(x[1]);
            umap[x[1]].push_back(x[0]);
        }
        vector<int> color(N+1,-1);
        for(int i=1;i<=N;i++){
            if(color[i]==-1){
                queue<int> q;
                q.push(i);
                color[i]=0;
                while(!q.empty()){
                    int top=q.front();
                    q.pop();
                    for(auto x:umap[top]){
                        if(color[x]==color[top])
                            return false;
                        if(color[x]==-1){
                            color[x]=1-color[top];
                            q.push(x);
                        }
                    }
                }
                
            }
        }
        return true;
    }
};

int main()
{
    sample g;
    int N,E;
    cin>>N>>E;
    vector<vector<int>> edges(E,vector<int> (2));
    for(int i=0;i<E;i++){
        cin>>edges[i][0]>>edges[i][1];
    }
    bool soln= g.possibleBipartition(N,edges);
    cout<<soln<<"\n";
    return 0;
}

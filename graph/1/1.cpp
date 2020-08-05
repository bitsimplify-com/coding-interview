#include <bits/stdc++.h>
using namespace std;
class sample {
public:
    struct edge{
        int id;
        int od;
    };
    //Topologically sort to check if cycle exists.If sorting is possible, cycle does not exist and the courses can be completed. 
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        edge edges[numCourses];
        unordered_map<int,vector<int>> umap;
        for(int i=0;i<numCourses;i++){
            edges[i]={0,0};
        }
        for(auto x:prerequisites){
            edges[x[1]].od++;
            edges[x[0]].id++;
            umap[x[1]].push_back(x[0]);
        }
        queue<int> q;
        for(int i=0;i<numCourses;i++){
            if(edges[i].id==0)
                q.push(i);
        }
        int count=0;
        while(!q.empty()){
            int f=q.front();
            q.pop();
            for(auto x:umap[f]){
                if(--edges[x].id==0)
                    q.push(x);
            }
            count++;
        }
        if(count!=numCourses)
            return false;
        return true;
    }
};
int main()
{
    sample g;
     int n,k;
     cin >>n>>k;
     vector<vector<int>> A(k,vector<int> (2));
    for (int i = 0; i < k; i++)cin >> A[i][0]>>A[i][1];
    cout<<g.canFinish(n,A);
    return 0;
}

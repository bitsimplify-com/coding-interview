#include <bits/stdc++.h>
using namespace std;
class sample {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<int,int> umap;
        int count=0;
        for(auto x: tasks){
            umap[x]++;
            count=max(count,umap[x]);
        }
        int res=(count-1)*(n+1);
        for(auto x:umap){
            if(x.second==count)res++;
        }
        return max((int)tasks.size(),res);
    }
};

int main()
{
    sample g;
    int N,n;
    cin >>N>>n;
    vector<char> tasks(N);
    for (int i = 0; i < N; i++)
    {
        cin >> tasks[i];
    }
    cout << g.leastInterval(tasks,n);
    return 0;
}

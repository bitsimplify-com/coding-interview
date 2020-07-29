#include <bits/stdc++.h>
using namespace std;
class sample {
public:
    int maxmArea(vector<int> rect){
        stack<int> s;
        rect.push_back(0);
        int maxArea=0,i=0;
        while(i<rect.size()){
            if(s.empty() || rect[s.top()]<=rect[i])s.push(i++);
            else{
                int t=s.top();
                s.pop();
                int Area=(s.empty()?i*rect[t]:(i-s.top()-1)*rect[t]);
                maxArea=max(maxArea,Area);
            }
        }
        return maxArea;
    }
};

int main()
{
    sample g;
    int n;
    cin >>n;
    vector<int> heights(n);
    for (int i = 0; i < n; i++)
    {
        cin >> heights[i];
    }
    cout << g.maxmArea(heights);
    return 0;
}

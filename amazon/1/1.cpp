#include <bits/stdc++.h>
using namespace std;
class sample {
public:
    int addDigits(int num) {
        return 1 + (num - 1) % 9;
    }
};

int main()
{
    sample g;
    int N;
    cin>>N;
    int soln= g.addDigits(N);
    cout<<soln<<"\n";
    return 0;
}

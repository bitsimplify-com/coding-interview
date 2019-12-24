#include<bits/stdc++.h>
using namespace std;

struct cmp
{
    bool operator()(int A, int B)
    {
      return A > B;
    }
};

void kth_largest(int k)
{
  priority_queue<int,vector<int>,cmp> H;
  int count = 0;
  int N;
  while(1)
  {
    //cout<<"Enter element : ";
    cin>>N;
    if(H.size() < k)
      H.push(N);
    else
    {
      if(N > H.top())
      {
        H.pop();
        H.push(N);
      }
      cout<<"Kth Largest Element : "<<H.top()<<endl;
    }
    count++;
    if(count == 10)  // Just to break the while loop for testing
      break;
  }
}

int main(void)
{
  kth_largest(3);
  return 0;
}


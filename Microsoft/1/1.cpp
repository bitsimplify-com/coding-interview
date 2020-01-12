#include <iostream> 
using namespace std; 
class sample { 
public: 
    unsigned int countSetBits(int n) 
    { 
        unsigned int count = 0; 
        while (n) { 
            n &= (n - 1); 
            count++; 
        } 
        return count; 
    } 
}; 
int main() 
{ 
    sample g;
	int i; 
    	cin>>i;
	cout << g.countSetBits(i); 
    return 0; 
} 
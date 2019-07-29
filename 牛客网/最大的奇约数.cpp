#include <iostream>
using namespace std;
 
long long f(int n){
	if (n == 1)
    return 1;
	long long a = (n + 1) / 2;
	return f(n / 2) + a*a;
}
 
int main(){
	int n;
	cin >> n;
	cout << f(n);
	return 0;
}

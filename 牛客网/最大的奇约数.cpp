/*递推 奇数是本身 偶数是不断/2后得到的奇数 注意2n和n的最大奇约数一样*/
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

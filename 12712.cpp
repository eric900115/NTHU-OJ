#include <iostream>
#define MAX 5000000000	//5*(10^9)
#define two_max 63
using namespace std;

bool isOverflow(long long check, long long a, long long b) {	//check = a*b
	if (a != (check / b)) { return true; }
	else { return false; }
}

long long solution(long long y, long long* b) {
	long long g, k, r, mid, cal;
	for (int i = 0; i < two_max; i++)
	{
		k = 0;
		r = MAX;
		if (b[i] == y + 1) {		//so luck that x = 2^i => tournment = x-1 = y
			return b[i];
		}
		if (b[i] > y) { break; }	//since guess >= b[i] if b[i] > y it is impossible guess = y
		while (r > k) {				//binary search (lower bound)
			mid = (r + k) / 2;
			cal = mid * 2 + 1;		//make sure it is odd  2n+1	| 0 < n < 5*(10^9)
			/*if (isOverflow((b[i] - 1) * cal, (b[i] - 1), cal) || isOverflow((cal - 1) * cal / 2, (cal - 1) / 2, cal)) {	//detect overflow
				r = mid;
				continue;
			}*/
			g = (b[i] - 1) * cal + (cal - 1) * cal / 2;
			if (isOverflow(g, (b[i] - 1) + (cal - 1) / 2, cal)) {	//detect overflow
				r = mid;
				continue;
			}
			cout<<k<<" "<<r<<"\n";
			if (g >= y) {
				r = mid;
			}
			else {
				k = mid + 1;
			}
		}
		//cout<<r<<" "<<g<<" "<<"";
		cal = r * 2 + 1;
		//if (isOverflow((b[i] - 1) * cal, (b[i] - 1), cal) || isOverflow((cal - 1) * cal / 2, (cal - 1) / 2, cal)) { continue; }	//detect overflow
		g = (b[i] - 1) * cal + (cal - 1) * cal / 2;
		if (isOverflow(g, (b[i] - 1) + (cal - 1) / 2, cal)) { continue; }	//detect overflow
		//cout<<g<<" "<<i<<" \n";
		//cout<<i<<" ";
		if (g == y) {
			return b[i] * cal;
		}
		//cout << "i = " << i << " 2^i = " << b[i] << " k = " << cal << " g = " << g << '\n';
	}
	return - 1;
}

int main() {
	int t;
	long long two_p[two_max];
	long long n;
	two_p[0] = 1;
	cin >> t;
	for (int i = 1; i < two_max; i++)	//calcute the 2 power to save time
	{
		two_p[i] = two_p[i - 1] * 2;
	}
	for (int i = 0; i < t; i++)
	{
		cin >> n;
		if (n > 1) {
			cout << solution(n, two_p) << '\n';
		}
		/*else {
			cout << "2" << '\n';
		}*/
	}
	return 0;
}

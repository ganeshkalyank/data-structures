#include <bits/stdc++.h>

using namespace std;

void toHan(int n,char src,char dest,char aux) {
	if (n!=0) {
		toHan(n-1,src,aux,dest);
		cout<<"Move "<<n<<" from "<<src<<" to "<<dest<<endl;
		toHan(n-1,aux,dest,src);
	}
}

int main () {
	toHan(100,'A','B','C');
	return 0;
}

#include<bits/stdc++.h>
using namespace std;

int main(){
	system("g++ -std=c++11 gen.cpp -o gen.exe");
	system("g++ -std=c++20 brute.cpp -o brute.exe");
	system("g++ -std=c++11 std.cpp -o std.exe");
	for(int i = 1;i <= 1000;i++){
		system("gen.exe > test.in");
		system("brute.exe < test.in > brute.out");
		system("std.exe < test.in > std.out");
		if(system("fc std.out brute.out")){
			cout << "Wrong Answer on test " << i << "\n";
			system("type test.in");
			system("type brute.out");
			system("type std.out");
			return 0;
		}
		else{
			cout << "Accepted on test" << i << ".\n";
		}
	}
	return 0;
}

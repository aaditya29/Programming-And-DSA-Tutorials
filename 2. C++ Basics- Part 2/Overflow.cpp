#include<bits/stdc++.h>
using namespace std;

int main(){
	/*
	Major datatypes: int, char, long int, long long int, float double
	Float and double have very high range. 
	The range of rest 3 are:

	-10^9<int<10^9
	-10^12< long int<10^12
	-10^18<long long int<10^18
	*/

	int a = 100000;
	int b = 100000;
	int c = a*b;
	cout<<c<<endl;//will not give whole output because current range is 10^10 and int has 10^9
}	
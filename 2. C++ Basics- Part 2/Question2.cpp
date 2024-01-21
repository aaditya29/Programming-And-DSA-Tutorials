/*
You're given an integer N. Write a program to calculate the sum of all the digits of N.

Input:
The first line contains an integer T, the total number of testcases. Then follow T lines, each line contains an integer N.

Output:
For each test case, calculate the sum of digits of N, and display it in a new line.

EXAMPLE=>

Input:
3 
12345
31203
2123

Output:
15
9
8
*/

#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int sum=0;
		while(n>0){
			int get_last = n % 10;// to get the last digit
			sum = sum + get_last;
			n = n/10;//to remove the remaining digits
		}
		cout<<sum<<endl;
	}
}
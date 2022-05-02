#include<bits/stdc++.h>
using namespace std;

int main(){
	/*
	Calculation Order Preference:
	1. Double
	2. Float
	3. Long long int
	4. Long int
	5. Int
	6. Char
	Note: Calculation always happens in higher datatype.
	Always calculation happens first then it is stored.
	*/
	cout<<7/2<<endl;//Output 3 because both int value
	cout<<7/2.0<<endl;//Output 3.5 because 2.0 is float value
	cout<<'c' + 1<<endl;//output is 100.
	int a = 3/2.0;
	cout<<a<<endl;//output is 1 because we are storing in variable a which is int.
	//But if we change datatype to double
	double b = 3/2;
	cout<<b<<endl;//Output will be 1 because first 3/2 calculation will happen in int hence will be calculated as 1.
	//Then will be stored in double. T 

}

/*
	Fibonacci
*/

#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

//Recursion
int fibonacci_recursive(int n)
{
	if(n<=0)
		return 0;
	else if(n==1)
		return 1;
	else
		return fibonacci_recursive(n-1) + fibonacci_recursive(n-2);
}

//for loop
int fibonacci_forloop(int n)
{
	if(n<=0)
		return 0;
	if(n==1)
		return 1;
	else
	{
		int n0=0,n1=1;//base value
		int tmp;
		for(int i=2; i<n; ++i)
		{
			tmp=n1;
			n1=n0+n1;
			n0=tmp;
		}
		return n0+n1;
	}
}

//Tail Recursion
int fibonacci_tail_recursive(int n, int counter, int oneBeforeResult, int twoBeforeResult)
{
	if(n<=0)
		return 0;
	else if(n<=2)
		return 1;
	else
	{
		if(counter == n)
			return oneBeforeResult + twoBeforeResult;
		if(counter < n)
		{
			int tmp = oneBeforeResult + twoBeforeResult;
			twoBeforeResult = oneBeforeResult;
			oneBeforeResult = tmp;
			fibonacci_tail_recursive(n, ++counter, oneBeforeResult, twoBeforeResult);
		}
	}
}

int main()
{
	int num;
	cin >> num;
	
	auto start = system_clock::now();
	
	cout << "Result for the " << num << "th Fibonacci number is " << fibonacci_tail_recursive(num, 3, 1, 1) << endl;
	
	auto time_after_cal = system_clock::now();
	auto d =  time_after_cal - start;
	auto milliTail = duration_cast<milliseconds>(d).count();
	
	cout << "Tail Recursion costs " << milliTail << " milliseconds," << duration_cast<seconds>(d).count() << " seconds." << endl;;
	
	cout<< "Result for the " << num << "th Fibonacci number is " << fibonacci_recursive(num)<<endl;
	
	d = system_clock::now() - time_after_cal;
	auto milliRecur = duration_cast<milliseconds>(d).count();
	
	cout << "Recursion costs " << milliRecur << " milliseconds," << duration_cast<seconds>(d).count() << " seconds." <<endl;
	
	/*
		计算第n个斐波那契数，当n越大，尾递归的速度优势越明显。
	*/
	cout << "Tail Recursion is " << (float)milliRecur/(float)milliTail << " times faster than ordinary Recursion." << endl;
	
	getchar();
	
	return 0;
}
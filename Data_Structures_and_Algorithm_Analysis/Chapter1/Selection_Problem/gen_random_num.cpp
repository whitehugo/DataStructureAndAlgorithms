#include <iostream>
#include <fstream>
#include <random>
#include <functional>

using namespace std;
//using iofstream = basic_ofstream<int>;

int main()
{
	const int num_to_gen = 10;
	ofstream ofs("output.txt",fstream::ate|fstream::in|fstream::out);
	if(!ofs)
	{
		cerr<<"failed to open file: output.txt"<<endl;
		return -1;
	}
	int random = 0;
	auto my_random_generator = bind(normal_distribution<double>{1000,100.0},default_random_engine{});
	for(int i=0; i<num_to_gen; ++i)
	{
		random = my_random_generator();
		ofs<<random<<"\n";
	}
	//int numArray[] = new int[num_to_gen];
	ofs.close();

	ifstream ifs("output.txt", fstream::in);
	if(!ifs)
	{
		cerr<<"failed to open output.txt!"<<endl;
		return -1;
	}
	
	
	
	return 0;
}
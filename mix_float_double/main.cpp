#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;
typedef chrono::high_resolution_clock Clock;

int main() {

	float  a = 1.0f;
	double b = 1.0;

	const int numIters = 10000;

	// mixing float with double
	auto t1 = Clock::now();
	for (int i=0; i<numIters; i++) {
		a = a + 1.001;
	}
	auto t2 = Clock::now();
	cout<<"== Method 1 ========"<<endl;
	cout<<"result: "<<a<<endl;
	cout<<"time: "<<duration_cast<nanoseconds>(t2 - t1).count()<<" ns"<<endl;

	// all float
	a = 1.0f;
	t1 = Clock::now();
	for (int i=0; i<numIters; i++) {
		a = a + 1.001f;
	}
	t2 = Clock::now();
	cout<<"== Method 2 ========"<<endl;
	cout<<"result: "<<a<<endl;
	cout<<"time: "<<duration_cast<nanoseconds>(t2 - t1).count()<<" ns"<<endl;

	//all double
	t1 = Clock::now();
	for (int i=0; i<numIters; i++) {
		b = b + 1.001;
	}
	t2 = Clock::now();
	cout<<"== Method 3 ========"<<endl;
	cout<<"result: "<<b<<endl;
	cout<<"time: "<<duration_cast<nanoseconds>(t2 - t1).count()<<" ns"<<endl;


	return 0;
}

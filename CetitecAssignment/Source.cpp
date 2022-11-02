#include<iostream>
#include<thread>
#include<condition_variable>
#include<iostream>
#include<future>
#include<string>
#include"api.h"


Assignment::API api;

void writer() {
	for (int i = 0; i < 10; ++i) {
		api.write('a' + i);
	}
	
}


void reader() {
	api.read();
}



int main() {

	std::thread t1(writer);

	std::thread t2(reader);


	t1.join();
	t2.join();
	
	



}




#include<iostream>
#include<thread>
#include<condition_variable>
#include<iostream>
#include<future>
#include<string>
#include"api.h"


Assignment::API api;

void writer() {
	api.write("sfuwoaoubwafbuoafwoub");
	
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




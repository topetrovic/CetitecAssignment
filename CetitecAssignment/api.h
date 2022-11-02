#include<iostream>
#include<thread>
#include<condition_variable>
#include<string>
namespace Assignment {
	class API {
	    std::mutex m;
		std::string s;
		std::condition_variable cv;
	public:
		void write(std::string input) {
			m.lock();
			s+=input;
			std::cout << "Writing thread " << std::this_thread::get_id() << " is writing value: " << input << std::endl;
			m.unlock();
			cv.notify_one();

			
		}
		void read() {
			std::unique_lock<std::mutex>lock(m);
			if (s.empty()) {
				cv.wait(lock);
			}
		
			std::cout << "Reading thread : " << std::this_thread::get_id() << "  is reading value: " << s << std::endl;
			
		
		}

	};
}
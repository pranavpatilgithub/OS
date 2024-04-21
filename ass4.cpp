#include <iostream>
#include <thread>
#include <vector>
#include <mutex>
#include <chrono>
using namespace std;

mutex x,db;
vector<thread> threads;
int readerCount = 0;

void reader(){
	x.lock();
	readerCount++;
	if(readerCount == 1)
		db.lock();
	x.unlock();
	
	cout<<readerCount<<" reader is inside"<<endl;
	this_thread::sleep_for(chrono::milliseconds(300));
	
	x.lock();
	readerCount--;
	if(readerCount == 0)
		db.unlock();
	x.unlock();
	
	cout<<readerCount+1<<" reader is leaving"<<endl;
}
void writer(){
	cout<<"writer is trying to enter"<<endl;
	db.lock();
	cout<<"writer has entered"<<endl;
	db.unlock();
	cout<<"writer is leaving"<<endl;
}

int main(){
	int n , i;
	cout<<"enter number of readers = ";
	cin>>n;
	
	threads.reserve(2*n);
	
	for(i=0;i<n;i++){
		threads.emplace_back(reader);
		threads.emplace_back(writer);
	}
	for(auto& t : threads){
		t.join();
	}
	
	return 0;
}

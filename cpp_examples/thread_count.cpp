#include <iostream>
#include <thread>
#include <chrono> 

using namespace std;
using namespace std::chrono;

void go2sleep() {

    //auto start = high_resolution_clock::now(); 
    
    cout << "Starting to wait" << endl;
    this_thread::sleep_for(chrono::milliseconds(200) );
    cout << "Waited 200 mls on thread id=" << this_thread::get_id() << endl;

    //auto stop = high_resolution_clock::now();
    //auto duration = duration_cast<microseconds>(stop - start);

}

void print_that() {

    cout << "printing: that" << endl;
}

int main() {
    cout << "Counting number of threads available..." << endl;

    const int processor_count = thread::hardware_concurrency();

    cout << "There are --> " << processor_count << " threads." << endl;

    /*
    // time it takes to print "this" then "that" single core,
    cout << "Example 1. Using the 'sleep' function to show non-parallel execution" << endl;
    auto start = high_resolution_clock::now(); 
    go2sleep();
    go2sleep();

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start); 

    cout << "this non-parallel process took: " << duration.count() << " microseconds" << endl;
    // time it takes to print "this" and "that" on two threads in parallel
    */

    cout << "Now we print in parallel" << endl;


    //auto start_new = high_resolution_clock::now(); 
    thread thread1(go2sleep);
    thread1.join();
    thread thread2(go2sleep);
    thread2.join();

    //auto stop_1 = high_resolution_clock::now();
    //auto duration_1 = duration_cast<microseconds>(stop - start); 

    //cout << "this parallel process took: " << duration_1.count() << " microseconds" << endl;

    cout << "DONE" << endl;
    return 0;
}

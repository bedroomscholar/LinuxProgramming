#include <iostream>
#include <thread> // modern c++ threading
#include <vector> // dynamic array cotainer
#include <mutex> // for thread-safe console output
#include <sstream> // for building string safe

std::mutex cout_mutex;
/* use clobal mutex; reason: std::cout is not thread-safe */

constexpr int NUMBER_OF_THREADS = 5;

void print_hello(int thread_id){


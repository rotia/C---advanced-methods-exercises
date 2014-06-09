int add(int a, int b) {return a + b; }

std::thread t(add(2,3));
//This will not work

std::thread t(5);
//This will also not work

std::thread t(add,2,3);
//This WILL work
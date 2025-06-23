// notes.cpp
// Full C++ reference with examples and minimal library use

// include tells the I want to use features from this standard library module.
//#include <iostream> For Printing to console with std::cout
// Reading from console with std::cin
//example use
#include <iostream>

int main() {
    std::cout << "Enter your name: ";
    std::string name;
    std::cin >> name;
    std::cout << "Hello, " << name << "!\n";
    return 0;
}
//#include <string> // For Using std::string instead of C-style char[]. String manipulation (length(), substr(), etc.)
//example
#include <string>
int main() {
    std::string greeting = "Hello";
    greeting += " World"; // Concatenate
    std::cout << greeting << "\n";
    return 0;
}
//#include <vector> // For dynamic arrays
//example
#include <vector>
int main() {
    std::vector<int> numbers = {1, 2, 3};
    numbers.push_back(4); // Add element
    for (int n : numbers)
        std::cout << n << " ";
    return 0;
}
//#include <map> // For key-value storage, Associative arrays (like Python dict)
#include <map>
int main() {
    std::map<std::string, int> age;
    age["Alice"] = 30;
    age["Bob"] = 25;
    std::cout << "Alice is " << age["Alice"] << " years old.\n";
    return 0;
}
#include <algorithm> // FOR std::sort, std::for_each, std::find, std::count, etc.
//example
int main() {
    std::vector<int> v = {3, 1, 4, 2};
    std::sort(v.begin(), v.end());
    for (int n : v) std::cout << n << " "; // 1 2 3 4
    return 0;
}
#include <memory> // For smart pointers
#include <fstream> // For file input/output
#include <thread> // For threading
#include <mutex> // For synchronization
//#include <functional> // For std::function and lambdas
//example
#include <functional>
int add(int a, int b) { return a + b; }

int main() {
    std::function<int(int, int)> f = add;
    std::cout << f(3, 4) << "\n"; // 7
    return 0;
}
#include <exception> // For exceptions
#include <initializer_list> // For initializer_list

// 1. Basic Hello World
void demo_hello() {
    std::cout << "1) Hello, World!\n\n"; // Print to console
}

// 2. Basic data types and variables
void demo_types() {
    std::cout << "2) Types & Variables\n";
    int i = 42; // Integer
    double d = 3.14; // Floating point
    bool b = true; // Boolean
    char c = 'A'; // Character
    std::string s = "C++"; // String object
    std::cout << "   int: " << i << ", double: " << d
              << ", bool: " << b << ", char: " << c
              << ", string: " << s << "\n\n";
}

// 3. Control Flow: if/else, switch, loops
void demo_control() {
    std::cout << "3) Control Structures\n";

    int x = 5;
    if (x % 2 == 0)
        std::cout << "   Even\n";
    else
        std::cout << "   Odd\n";

    // Switch example
    switch (x) {
        case 1: std::cout << "   One\n"; break;
        case 5: std::cout << "   Five\n"; break;
        default: std::cout << "   Other\n";
    }

    // For loop
    std::cout << "   for:";
    for (int i = 0; i < 3; ++i)
        std::cout << ' ' << i;
    std::cout << "\n\n";
}

// 4. Function overloading
int add(int a, int b) { return a + b; }     // Integer addition
double add(double a, double b) { return a + b; } // Double addition

void demo_functions() {
    std::cout << "4) Functions & Overloading\n";
    std::cout << "   add(2,3)=" << add(2,3)
              << ", add(2.5,3.5)=" << add(2.5,3.5)
              << "\n\n";
}

// 5. Classes and Inheritance
class Animal {
public:
    Animal(std::string n): name(std::move(n)) {}
    virtual void speak() const { std::cout << name << " makes a sound\n"; }
    virtual ~Animal() = default; // Virtual destructor for safety

protected:
    std::string name;
};

class Dog : public Animal{
public:
    Dog(): Animal("Dog") {}
    void speak() const override { std::cout << name << " barks\n"; }
};

void demo_oop() {
    std::cout << "5) Classes & OOP\n";
    Animal* a = new Animal("Generic");
    Animal* d = new Dog();

    a->speak(); // Calls Animal::speak
    d->speak(); // Calls Dog::speak (polymorphism)

    delete a; delete d;
    std::cout << "\n";
}

// 6. Templates (generic functions)
template<typename T>
T maximum(T a, T b) {
    return (a > b) ? a : b;
}

void demo_templates() {
    std::cout << "6) Templates\n";
    std::cout << "   max(3,7)=" << maximum(3,7)
              << ", max(2.5,1.1)=" << maximum(2.5,1.1)
              << "\n\n";
}

// 7. Exception Handling
void may_throw(bool doThrow) {
    if (doThrow) throw std::runtime_error("Uh-oh!");
}

void demo_exceptions() {
    std::cout << "7) Exception Handling\n";
    try {
        may_throw(true); // This will throw
    } catch (const std::exception& e) {
        std::cout << "   Caught: " << e.what() << "\n";
    }
    std::cout << "\n";
}

// 8. STL Containers and Algorithms
void demo_stl() {
    std::cout << "8) STL: vector, map, sort, for_each\n";

    // Vector and sort
    std::vector<int> v = {4, 1, 3, 2};
    std::sort(v.begin(), v.end()); // Sort ascending

    std::cout << "   Sorted vector:";
    std::for_each(v.begin(), v.end(), [](int x){ std::cout << ' ' << x; });
    std::cout << "\n";

    // Map example
    std::map<std::string,int> m = {{"one",1}, {"two",2}};
    std::cout << "   Map[\"two\"] = " << m["two"] << "\n\n";
}

// 9. Smart Pointers (memory management)
void demo_smartptr() {
    std::cout << "9) Smart Pointers\n";

    {
        std::unique_ptr<int> up = std::make_unique<int>(99); // Exclusive ownership
        std::cout << "   unique_ptr => " << *up << "\n";
    }

    {
        auto sp = std::make_shared<std::string>("hello"); // Shared ownership
        std::cout << "   shared_ptr (use_count=" << sp.use_count()
                  << ") => " << *sp << "\n";
    }

    std::cout << "\n";
}

// 10. File I/O
void demo_fileio() {
    std::cout << "10) File I/O\n";

    // Write to a file
    {
        std::ofstream ofs("demo.txt");
        ofs << "Line 1\nLine 2\n";
    }

    // Read from the file
    {
        std::ifstream ifs("demo.txt");
        std::string line;
        while (std::getline(ifs, line)) {
            std::cout << "   Read: " << line << "\n";
        }
    }

    std::cout << "\n";
}

// 11. Lambdas and std::function
void demo_lambda() {
    std::cout << "11) Lambdas & std::function\n";

    auto square = [](int x){ return x*x; }; // Inline anonymous function
    std::cout << "   square(5)=" << square(5) << "\n";

    std::function<void(const std::string&)> printer =
        [](const std::string& msg){ std::cout << "   " << msg << "\n"; };
    printer("Hello from std::function");

    std::cout << "\n";
}

// 12. Move Semantics
struct Buffer {
    int* data;
    size_t sz;

    Buffer(size_t n): data(new int[n]), sz(n) { }

    // Move constructor: transfer ownership
    Buffer(Buffer&& o) noexcept : data(o.data), sz(o.sz) {
        o.data = nullptr; o.sz = 0;
    }

    ~Buffer() { delete[] data; }
};

void demo_move() {
    std::cout << "12) Move Semantics\n";
    Buffer b1(5); // Construct
    Buffer b2 = std::move(b1); // Move
    std::cout << "   Moved buffer, old sz=" << b1.sz
              << ", new sz=" << b2.sz << "\n\n";
}

// 13. Multithreading & Synchronization
void worker(int id, std::mutex& m) {
    std::lock_guard<std::mutex> lock(m); // Lock the mutex
    std::cout << "   Thread " << id << " doing work\n";
}

void demo_threading() {
    std::cout << "13) Multithreading\n";
    std::mutex m;

    std::thread t1(worker, 1, std::ref(m)); // Start thread 1
    std::thread t2(worker, 2, std::ref(m)); // Start thread 2

    t1.join(); // Wait for threads to finish
    t2.join();
    std::cout << "\n";
}

// 14. Initializer Lists and Range-Based For Loop
void demo_initlist() {
    std::cout << "14) Initializer List & Range-for\n";
    std::vector<std::string> names = {"Alice", "Bob", "Carol"};

    for (auto& name : names)
        std::cout << "   " << name << "\n";

    std::cout << "\n";
}

void demo_hello();
void demo_types();
void demo_control();
void demo_functions();
void demo_oop();
void demo_templates();
void demo_exceptions();
void demo_stl();
void demo_smartptr();
void demo_fileio();
void demo_lambda();
void demo_move();
void demo_threading();
void demo_initlist();


// === MAIN ===
int main() {
    int choice;

    while (true) {
        std::cout << "\n====== C++ Learning Menu ======\n";
        std::cout << " 1. Hello, World! (Basic output)\n";
        std::cout << " 2. Data Types & Variables\n";
        std::cout << " 3. Control Structures (if, switch, loops)\n";
        std::cout << " 4. Functions & Overloading\n";
        std::cout << " 5. Object-Oriented Programming\n";
        std::cout << " 6. Templates (Generic Programming)\n";
        std::cout << " 7. Exception Handling\n";
        std::cout << " 8. STL Containers & Algorithms\n";
        std::cout << " 9. Smart Pointers (unique_ptr, shared_ptr)\n";
        std::cout << "10. File I/O (Read/Write Files)\n";
        std::cout << "11. Lambdas & std::function\n";
        std::cout << "12. Move Semantics (Performance)\n";
        std::cout << "13. Multithreading (Threads & Mutex)\n";
        std::cout << "14. Initializer Lists & Range Loops\n";
        std::cout << " 0. Exit\n";
        std::cout << "Select a topic to run [0-14]: ";
        std::cin >> choice;

        std::cout << "\n"; // Separate output clearly
        
        switch (choice) {
            case 1:
                demo_hello();
                std::cout << "// Example: std::cout << \"Hello, World!\" << std::endl;\n";
                break;
            case 2:
                demo_types();
                std::cout << "// Example: int a = 5; double pi = 3.14; std::string s = \"text\";\n";
                break;
            case 3:
                demo_control();
                std::cout << "// Example: if (x > 5) { ... } else { ... }\n";
                std::cout << "// Example: for (int i = 0; i < 5; ++i) { ... }\n";
                break;
            case 4:
                demo_functions();
                std::cout << "// Example: int add(int a, int b); double add(double a, double b);\n";
                break;
            case 5:
                demo_oop();
                std::cout << "// Example: class Animal { virtual void speak(); };\n";
                break;
            case 6:
                demo_templates();
                std::cout << "// Example: template<typename T> T max(T a, T b);\n";
                break;
            case 7:
                demo_exceptions();
                std::cout << "// Example: try { risky(); } catch (const std::exception& e) { ... }\n";
                break;
            case 8:
                demo_stl();
                std::cout << "// Example: std::vector<int> v; std::sort(v.begin(), v.end());\n";
                break;
            case 9:
                demo_smartptr();
                std::cout << "// Example: std::unique_ptr<int> p = std::make_unique<int>(5);\n";
                break;
            case 10:
                demo_fileio();
                std::cout << "// Example: std::ofstream ofs(\"file.txt\"); ofs << \"text\";\n";
                break;
            case 11:
                demo_lambda();
                std::cout << "// Example: auto square = [](int x) { return x * x; };\n";
                break;
            case 12:
                demo_move();
                std::cout << "// Example: Buffer b2 = std::move(b1); // ownership transfer\n";
                break;
            case 13:
                demo_threading();
                std::cout << "// Example: std::thread t(worker); t.join();\n";
                break;
            case 14:
                demo_initlist();
                std::cout << "// Example: std::vector<int> nums = {1, 2, 3};\n";
                break;
            case 0:
                std::cout << "Goodbye! 👋\n";
                return 0;
            default:
                std::cout << "Invalid choice. Please select between 0 and 14.\n";
        }
    }
}
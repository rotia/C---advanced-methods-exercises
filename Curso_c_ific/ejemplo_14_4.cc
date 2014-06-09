#include <iostream> // cout, endl
#include <cstddef>  // size_t

using std::cout; using std::endl; using std::size_t;

typedef int T;

class Vectorish {
public:

  // Construct by filling with N consecutive integers
  Vectorish(int start, size_t N) : data(nullptr), size(N) {
    if (N>0) {
      data = ALLOCATE(N);
      for (size_t i=0; i<N; ++i)
        data[i] = start+i;
    }
  }

  // Copy constructor
  Vectorish(const Vectorish& other) : data(ALLOCATE(other.size)), size(other.size) {
    COPY(other);
  }

  // Assignment operator
  Vectorish& operator=(const Vectorish& other) {
    if (data) { 
      RELEASE(); 
    }
    size = other.size;
    data = ALLOCATE(size);
    COPY(other);
    return *this;
  }

  T& operator[](size_t n) { return data[n]; }

  ~Vectorish() { RELEASE(); }

private:
  T* data;
  std::size_t size;

  // Used in two places (copy constructor, assgnment operator)
  void COPY(const Vectorish& other) {
    cout << "Copying      " << size << " elements" << endl;
    for (size_t i=0; i<size; ++i) {
      data[i] = other.data[i];
    }
  }

  // Used in three places (both constructors, assignment operator)
  T* ALLOCATE(size_t N) {
    cout << "Allocating   " << N << " elements" << endl;
    return new T[N];
  }

  // Used in two places (destructor, assignment operator)
  void RELEASE() {
    cout << "Deallocating " << size << " elements" << endl;
    if (data)
      delete [] data;
  }
};
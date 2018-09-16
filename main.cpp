#include <cstdlib>
#include <iostream>
#include <math.h>

#include "vector.h"

using namespace std;

template <typename T>
struct Dimensions {
    int operator()(int* coordinates, int* sizes, int dimensions)
    {
      int r = coordinates[dimensions-1];
      for (int i=dimensions-2; i>=0; i--)
      {
        r *= sizes[i];
        r +=coordinates[i];
      }
      return r;
    }
};

struct Integer {
       typedef int T;
       typedef Dimensions<T> Operation;
};

int main(int argc, char *argv[]) {

    int dimensions = 3;
    int dimensionSizes[] = {100,200,304};

    Vector<Integer>* myV = new Vector<Integer>(dimensions, dimensionSizes);
    int position[] = {1,2,33,22};
    myV->set(19, position);
    int x = myV->get(position); // 19
    cout <<"x is: " <<x << endl;


    return EXIT_SUCCESS;
}

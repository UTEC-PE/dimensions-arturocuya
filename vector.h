#ifndef VECTOR_H
#define VECTOR_H

template <typename Tr>
class Vector {
    public:
        typedef typename Tr::T T;
        typedef typename Tr::Operation Operation;

    private:
        T* data;
        int dataSize;
        Operation op;

        int dimensions;
        int* dimensionSizes;

    public:
        Vector() : data(nullptr) {};

        Vector(int dimensions, int* dimensionSizes) : dimensions(dimensions), dimensionSizes(dimensionSizes)
        {
            dataSize = 1;
            for (int i = 0; i < dimensions; i++)
            {
              dataSize *= dimensionSizes[i];
            }

            data = new T[dataSize];
        }

        void set(T datum, int* coordinates)
        {
          int position = op(coordinates, dimensionSizes, dimensions);
          data[position] = datum;
        };

        T get(int* coordinates)
        {
          int position = op(coordinates, dimensionSizes, dimensions);
          return data[position];
        };
};

#endif

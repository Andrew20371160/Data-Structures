#include <iostream>
#include <vector>
using namespace std ;

template<typename DataType>
class heap{

    DataType *arr;
    int last_index ;
    int size ;

    public:
        heap() ;
        heap(int size ) ;
        ~heap();
        heap(DataType*_arr,int _size);
         heap(vector<DataType>_arr);
        bool has_left(int index);
        bool has_right(int index);
        bool has_parent(int index);
        int left(int index);
        int right(int index);
        int parent(int index);
        DataType min(void);
        void add(DataType data) ;
        heap bottom_up_construct(DataType*,int);
        DataType remove(int index);
        void heapify(int index) ;
        DataType remove_min(void);


};

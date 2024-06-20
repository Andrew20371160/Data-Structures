
#include "heap.h"

    template<typename DataType>
    heap<DataType>::heap(){
        arr =NULL;
        size = 0;
        last_index=-1 ;
    }

    template<typename DataType>
    heap<DataType>::~heap(){
        if(arr){
            delete[]arr;
            arr= NULL;
        }
    }

    template<typename DataType>
    heap<DataType>::heap(int _size ) {
        last_index=-1 ;
        if(_size>0){
            arr=new DataType[_size] ;
            size =_size;
        }
        else{
            size=0  ;
            last_index=-1 ;
            arr= NULL ;
        }
    }

    template<typename DataType>
    heap<DataType>::heap(DataType*_arr,int _size){
        arr= new DataType[_size] ;
        size = _size ;
        last_index=size-1 ;
        for(int i =0 ; i<_size;i++){
            arr[i]= _arr[i]  ;
        }
        for(int i = size/2-1;i>=0;i--){
            heapify(i);
        }
    }

    template<typename DataType>
    heap<DataType>::heap(vector<DataType>_arr){
        arr= new DataType[_arr.size()] ;
        size = _arr.size() ;
        last_index=size-1 ;

        for(int i =0 ; i<size;i++){
            arr[i]= _arr[i]  ;
        }
        for(int i = size/2-1;i>=0;i++){
            heapify(i);
        }
    }

    template<typename DataType>
    bool heap<DataType>::has_left(int index){
        return left(index)<=last_index;
    }

    template<typename DataType>
    bool heap<DataType>::has_right(int index){
        return right(index)<=last_index;
    }

    template<typename DataType>
    bool heap<DataType>::has_parent(int index){
        return index!=0  ;
    }

    template<typename DataType>
    int heap<DataType>::left(int index){
        return 2*index+1 ;
    }

    template<typename DataType>
    int heap<DataType>:: right(int index){
        return 2*index+2 ;
    }

    template<typename DataType>
    int heap<DataType>::parent(int index){
        return (index&1)?index/2:((index-1)/2) ;
    }

    template<typename DataType>
    DataType heap<DataType>::min(void){
        if(last_index>=0&&size>0){
            return arr[0] ;
        }
    }

    template<typename DataType>
    void heap<DataType>::add(DataType data) {
        if(last_index==size-1){
            DataType*new_heap = new DataType[size*2] ;
            size=size*2;
            for(int i = 0  ; i<size/2;i++){
                new_heap[i]=arr[i] ;
            }
            if(arr){
                delete[]arr;
                arr=NULL;
            }
            arr= new_heap;
        }
        last_index++;
        arr[last_index] = data;
        int i =last_index  ;
        while(i>=0&&arr[parent(i)]>arr[i]){
            swap(arr[parent(i)],arr[i]) ;
            i=parent(i) ;
        }
    }


    template<typename DataType>
    DataType heap<DataType>::remove(int index){
        if(index<size&&index<=last_index){
            DataType temp= arr[index] ;
            swap(arr[last_index],arr[index]);
            last_index-- ;
            heapify(index);
            int i = index ;
            while(i>=0&&arr[i]<arr[parent(i)]) {
                swap(arr[i],arr[parent(i)]) ;
                i=parent(i) ;
            }
            return temp;
        }
    }

    template<typename DataType>
    void heap<DataType>::heapify(int index) {
        int min_index=  index;
        if(has_left(index)){
            min_index= arr[left(index)]<arr[index]?left(index):index ;
        }
        if(has_right(index)){
            min_index = arr[right(index)]<arr[min_index]?right(index):min_index;
        }
        if(min_index!=index){
            swap(arr[index],arr[min_index] ) ;
            heapify(min_index);
        }

    }

    template<typename DataType>
    DataType heap<DataType>::remove_min(void){
        if(last_index>=0&&size>0){
            DataType temp = arr[0]  ;
            swap(arr[0],arr[last_index]);
            last_index--;
            heapify(0);
            return temp ;
        }

    }


int main(){

    return 0;
}

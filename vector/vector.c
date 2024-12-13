	#include "vector.h"

	bool init_vector(vector*vec,uint32_t size){
		if(vec){
			if(vec->arr){
				free(vec->arr) ;
			}
			vec->arr=NULL ;
			vec->arr = (DataType*)calloc(size,sizeof(DataType)) ;  
			vec->elements_count = 0;
			vec->size = size ; 
			return true ; 
		}
		return false ;
	}

	bool remove_vector(vector*vec){
		if(vec){
			if(vec->arr){
				free(vec->arr) ; 
				vec->arr=NULL ; 
				vec->size = 0 ; 
				vec->elements_count = 0;
				return true ; 
			}
		}
		return false ; 
	}
	bool insert(vector*vec,DataType data,uint32_t position) {
		if(vec&&position<vec->elements_count){
			if(vec->elements_count==(vec->size-1)){
				resize(vec,2*vec->size+1) ; 
			}
			for(uint32_t i = vec->elements_count;i>position;i--){
				vec->arr[i]=vec->arr[i-1] ;
			}
			vec->arr[position] = data ; 
		}
		return false ; 
	}
	bool remove(vector*vec,uint32_t position ){
		if(vec&&position<vec->elements_count){
			for(uint32_t i =position;i<vec->elements_count-1;i++){
				vec->arr[i]=vec->arr[i+1] ; 
			}
			vec->elements_count--;  
			return true ; 
		}
		return false ; 
	}
	bool remove(vector*vec,DataType data){
		if(vec){
			for(uint32_t i = 0 ;i<vec->elements_count;i++){
				if(vec->arr[i]==data) {
					for(uint32_t j =i;j<vec->elements_count-1;j++){
						vec->arr[j]=vec->arr[j+1] ; 
					}
					return true ; 
				}
			}
		}
		return false ; 
	}

	bool resize(vector*vec,uint32_t size){
		if(vec){
			if(size>0){
				if(vec->arr){
					DataType*temp_arr = (DataType*)calloc(size,sizeof(DataType)) ; 
					if(size<vec->elements_count){
						vec->elements_count=size;  
					}
					for (uint32_t i = 0; i <vec->elements_count; i++)
					{
						temp_arr[i]=vec->arr[i] ; 
					}
					free(vec->arr);
					vec->arr=NULL;
					vec->arr = temp_arr; 
					vec->size =size ;
				}
				else{
					vec->arr = (DataType*)calloc(size,sizeof(DataType)) ; 
					vec->size=size ; 
					vec->elements_count= 0;
				}
			}
			else{
				free(vec->arr);
				vec->arr=NULL;
				vec->elements_count=0;
				vec->size=0;
			}
		}
		return false ; 
	}
	bool copy(vector*dest,vector*src) {
		if(dest&&src){
			if(src->size>0){
				//make them same size
				free(dest->arr);
				dest->arr=NULL;
				dest->arr=(DataType*)calloc(src->size,sizeof(DataType));
				dest->size=src->size;
				dest->elements_count= src->elements_count;
				for (uint32_t i = 0; i < dest->elements_count; i++)
				{
					dest->arr[i]=src->arr[i] ; 
				}
			}
			else{
				free(dest->arr);
				dest->arr=NULL;
				dest->size =0;
				dest->elements_count=0;
			}
			return true ;
		}
		return false ; 
	}
	
	int main(){
		/*
		bool init_vector(vector*,uint32_t);
		bool remove_vector(vector*,uint32_t);
		bool insert(vector*,DataType,uint32_t) ; 
		bool remove(vector*,uint32_t);
		bool remove(vector*,DataType);
		bool resize(vector*,uint32_t);
		bool copy(vector*dest,vector*src) ; 
		*/
		vector vec{NULL,30,35};
		
		return 0;
	}
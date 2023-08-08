#include <iostream>
#include <vector>
#include <stdexcept>

class ArrayList{
    private:
        int capacity_ = 1;
        int growth_factor = 2;
        int size = 0;
        int *data;

        void resize(){
            capacity_ *= growth_factor;
            int *resized_data = new int[capacity_];

            for (int i = 0; i < size; i++ ){
                resized_data[i] = data[i];
            }

            delete[] data;
            data = resized_data;
        }
        
        void shrink_to_fit(){
            int new_capacity = 1;

            while (true){
                if (new_capacity < size){
                    new_capacity *= 2;
                } else {
                    break;
                }
            }
            capacity_ = new_capacity;
        }

        void check(int index){
            if (index < 0 || index >= size){
                throw std::range_error("Index out of bounds.");
            }
        }

    public:
        /**
         * Default constructor.
         * 
         * @param (Optional) capacity of array, (optional) growth factor, (optional) size of array.
        */
        ArrayList(){
            data = new int[capacity_];
        }

        /**
         * Constructor that initializes with a vector.
         * 
         * @param a vector of integers.
        */
        ArrayList(std::vector<int> data){
            if (capacity_ < data.size()){
                capacity_ = data.size();
            }
    
            this->data = new int[capacity_];

            for (int data_: data){
                append(data_);
            }
        }

        /**
         * Destructor.
        */
        ~ArrayList(){
            delete[] data;
        }

        /**
         * @brief Returns number of elements in array.
         * 
         * @return length of array.
        */
        int length(){
            return size;
        }

        /**
         * @brief Adds element to the back of array.
         * 
         * @param a value to append to array.
        */
        void append(int elem){
            if (size >= capacity_){
                resize();
            }

            data[size] = elem;
            size++;
        }

        /**
         * @brief Prints the elements of the array.
        */
        void print(){
            std::cout << "[";
            if (size > 0){
                for (int i = 0; i < size; i++){
                    std::cout << data[i] << ", ";
                }
                std::cout << "\b\b";
            } 
            std::cout << "]\n";
        }

        /**
         * @brief Returns reference to value at an index.
         * 
         * @param the desired index.
         * @return the value at given index.
        */
        int& operator[](int index){
            check(index);

            return data[index];
        }

        /**
         * @brief Inserts value into index.
         * 
         * @param the value to insert to array and the index in which the value is put.
        */
        void insert(int val, int index){
            if (index < 0 || index > size){
                throw std::range_error("Index out of bounds.");
            }   
            if (size >= capacity_){
                resize();
            }
            if (size == index){
                append(val);
                return;
            }
            for (int i = size; i > index; i--){
                data[i] = data[i-1];
            }
            size++;
            data[index] = val;
        }

        /**
         * @brief Removes element at index.
         * 
         * @param desired index. 
        */
        void remove(int index){
            check(index);

            for (int i = index+1; i < size; i++){
                data[i-1] = data[i];
            }
            size--;

            if (size < capacity_*.25){
                shrink_to_fit();
            }
        }

        /**
         * @brief Removes element at index and returns it.
         * 
         * @param desired index.
        */
        int pop(int index){
            int temp = data[index];
            remove(index);

            return temp;
        }

        /**
         * @brief Removes the last element of array and returns it.
        */
        int pop(){
            return pop(size - 1);
        }

        /**
         * @brief Returns capacity.
         * 
         * @return capacity of array.
        */
        int capacity(){
            return capacity_;
        }
};
#include <memory>
#include <vector>
#include <iostream>
#include "array_list.cpp"

struct ArrayListNode{
    std::unique_ptr<ArrayList> array;
    ArrayListNode *prev, *next;

    /**
     * Constructor for ArrayListNode.
     * 
     * @param a vector to instanciate with and pointers to next and previous arraylistnode.
    */
    ArrayListNode(std::vector<int> values, ArrayListNode *prev, ArrayListNode *next){
        array = std::make_unique<ArrayList>(values); 
        this->prev = prev;
        this->next = next;
    }
};

class LinkedArrayList{
    private:
        ArrayListNode *head = nullptr;
        ArrayListNode *tail = nullptr;
        int size = 0;

        void check(int index){
            if (index < 0 || index >= size){
                throw std::range_error("Index out of bounds.");
            }
        }

    public:
        /**
         * Constructor for LinkedArrayList.
        */
        LinkedArrayList(){}

        /**
         * Destuctor
        */
        ~LinkedArrayList(){
            ArrayListNode *current = head;
            ArrayListNode *next;

            while (current != nullptr){
                next = current->next;
                delete current;
                current = next;
            }
        }

        /**
         * @brief Appends an array to the back of linkedarraylist.
         * 
         * @param the vector.
        */
        void append(std::vector<int> elem){
            ArrayListNode *node = new ArrayListNode{elem, tail, nullptr};
            size++;

            if (head == nullptr){
                head = node;
                tail = node;
                return;
            }
            tail->next = node;
            tail = node;
        }

        /**
         * @brief Prints elements of list.
        */
        void print(){
            std::cout << "[\n";

            if (head != nullptr){
                ArrayListNode *current = head;
                while (current != nullptr){
                    std::cout << "  ";
                    current->array->print();
                    current = current->next;
                }
            } 
            std::cout << "]\n";
        }

        /**
         * @brief Gets arraylist at index.
         * 
         * @param the index.
        */
        std::unique_ptr<ArrayList>& operator[](int index){
            check(index);
            ArrayListNode *current = head;

            for (int i = 0; i < index; i++){
                current = current->next;
            }

            return current->array;
        }
};
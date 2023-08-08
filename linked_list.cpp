#include <iostream>
#include <vector>
#include <stdexcept>

struct Node{
    int data;
    Node *next = nullptr, *prev = nullptr;
};

class LinkedList{
    private:
        Node *head = nullptr;
        Node *tail = nullptr;
        int size = 0;

        void check(int index){
            if (index < 0 || index >= size){
                throw std::range_error("Index out of bounds.");
            }
        }

    public:
        /**
         * Default constructor for LinkedList.
        */
        LinkedList(){}

        /**
         * Constructor that initializes with vector.
         * 
         * @param a vector of integers.
        */
        LinkedList(std::vector<int> data){
            for (int data_: data){
                append(data_);
            }
        }

        /**
         * Destructor
        */
       ~LinkedList(){
            Node *current = head;
            Node *next;

            while (current != nullptr){
                next = current->next;
                delete current;
                current = next;
            }
       }

        /**
         * @brief returns number of elements in list.
         * 
         * @return size of list.
        */
        int length(){
            return size;
        }

        /**
         * @brief Adds element to the back of list.
         * 
         * @param an integer to append.
        */
        void append(int elem){
            Node *node = new Node{elem};
            size++;

            if (head == nullptr){
                head = node;
                tail = node;
                return;
            }

            tail->next = node;
            node->prev = tail;
            tail = node;
        }

        /**
         * @brief Prints elements of list.
        */
        void print(){
            std::cout << "[";

            if (head != nullptr){
                Node *current = head;

                while (current != nullptr){
                    std::cout << current->data << ", ";
                    current = current->next;
                }
                std::cout << "\b\b";
            }
            std::cout << "]\n";
        }

        /**
         * @brief Returns element at given index.
         * 
         * @param an index.
        */
        int& operator[](int index){
            check(index);
            Node *current = head;
            for (int i = 0; i < index; i++){
                current = current->next;
            }

            return current->data;
        }

        /**
         * @brief Inserts value to desired index.
         * 
         * @param the element to add to list and the index.
        */
        void insert(int val, int index){
            if (index < 0 || index > size) throw std::range_error("Index out of bounds."); 

            Node *node = new Node{val};

            if (size == 0 || index == size){
                append(val); 
                return;

            } else if (index == 0){
                head->prev = node;
                node->next = head;
                head = node;
                size++;
                return;
            }

            Node *current = head;

            for (int i = 0; i < index-1; i++){
                current = current->next;
            }
            
            current->next->prev = node;
            node->next = current->next;
            current->next = node;
            node->prev = current;

            size++;
        }        

        /**
         * @brief Removes element at given index.
         * 
         * @param desired index.
        */
        void remove(int index){
            check(index);

            Node *current = head;  
            for (int i = 0; i < index-1; i++){
                current = current->next;
            }

            if (index == size-1){
                pop();
                return;

            } else if (index == 0){
                head = head->next;
                head->prev = nullptr;
                size--;
                return;
            }

            current->next = current->next->next;
            current->next->prev = current;
            size--;
        }

        /**
         * @brief Removes element at given index and returns it.
         * 
         * @param desired index.
        */
        int pop(int index){
            Node *temp = head;
            for (int i = 0; i < index; i++){
                temp = temp->next;
            }
            remove(index);
            return temp->data;
        }

        /**
         * @brief Removes dddxlast element and returns it.
        */
        int pop(){
            if (size == 0) throw std::range_error("Cannot remove element from empty list.");
            Node *last = tail;
            size--;

            if (size == 0){
                head = nullptr;
                tail = nullptr;
            } else {
                tail = tail->prev;
                tail->next = nullptr;
            }
        
            return last->data;
        }
};
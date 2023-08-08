#include "array_list.cpp"
#include <cassert>
#include <vector>
#include <stdexcept>

void test_empty_array_has_length_zero(){
    ArrayList a{};

    assert(a.length() == 0);
}

void test_array_with_two_elements_appended_has_length_two(){
    ArrayList a{};
    a.append(3);
    a.append(2);

    assert(a.length() == 2);
}

void test_print(){
    ArrayList a1{};
    a1.append(1);
    a1.append(2);
    a1.append(3);

    std::cout << "Testing print for ...\n\n";
    std::cout << "-- default constructor initialized {1,2,3}:\n";
    std::cout << "a = ";
    a1.print();
    std::cout << "\n";

    ArrayList a2{};

    std::cout << "-- default constructor empty array:\n";
    std::cout << "a = ";
    a2.print();
    std::cout << "\n";
}

void test_indexing_operator(){
    ArrayList a{{1, 0, 2, 6, 9}};
    a[2] = 5;

    assert(a[1] == 0 && a[2] == 5);

    // Testing range_error
    bool throwed_range_error = false;
    try{
        int a_ = a[10];
    } catch (const std::range_error &e){
        throwed_range_error = true;
    }

    assert(throwed_range_error);
}

void test_vector_constructor(){
    ArrayList primes{{2, 3, 5, 7, 11}};

    std::cout << "-- vector constructor initialized {2,3,5,7,11}:\n";
    std::cout << "primes = ";
    primes.print();
    std::cout << "\n";
}

void test_insert(){
    ArrayList a{{0, 1}};

    assert(a.length() == 2);
    a.insert(42, 0);
    assert(a.length() == 3);
    assert(a[0] == 42);
    assert(a[1] == 0);
    assert(a[2] == 1);
    a.insert(43, 1);
    assert(a.length() == 4);
    assert(a[0] == 42);
    assert(a[1] == 43);
    assert(a[2] == 0);
    assert(a[3] == 1);
    a.insert(44, 4);
    assert(a.length() == 5);
    assert(a[0] == 42);
    assert(a[1] == 43);
    assert(a[2] == 0);
    assert(a[3] == 1);
    assert(a[4] == 44);

    // Testing range_error
    bool throwed_range_error = false;
    try{
        a.insert(1, 100);
    } catch (const std::range_error &e){
        throwed_range_error = true;
    }

    assert(throwed_range_error);
}

void test_remove(){
    ArrayList a{{1,2,3,3,4,5}};
    a.remove(3);
    assert(a[3] == 4);
    assert(a.length() == 5);
    a.remove(3);
    assert(a[3] == 5);
    assert(a.length() == 4);
    a.remove(3);
    assert(a[2] == 3);
    assert(a.length() == 3);

    // Testing range_error
    bool throwed_range_error = false;
    try{
        a.remove(4);
    } catch (const std::range_error &e){
        throwed_range_error = true;
    }

    assert(throwed_range_error);
}

void test_pop_at_index(){
    ArrayList a{{8,7,6,5}};
    
    assert(a.pop(2) == 6);
    assert(a.pop(1) == 7);
    assert(a.pop(1) == 5);
    assert(a.pop(0) == 8);
    assert(a.length() == 0);
}

void test_pop(){
    ArrayList a{{1,2,3,4,5,6,7,8,9}};

    assert(a.length() == 9);
    assert(a.pop() == 9);
    assert(a.pop() == 8);
    assert(a.pop() == 7);
    assert(a.pop() == 6);
    assert(a.pop() == 5);
    assert(a.pop() == 4);
    assert(a.pop() == 3);
    assert(a.pop() == 2);
    assert(a.pop() == 1);
    assert(a.length() == 0);
}

void test_shrink_to_fit(){
    ArrayList a{};
    assert(a.capacity() == 1);

    for (int i = 0; i < 10; i++){
        a.append(1);
    }
    assert(a.capacity() == 16);
    for (int i = 0; i < 10; i++){
        a.pop();
    }
    assert(a.capacity() == 1);
}

int main(){
    test_empty_array_has_length_zero();
    test_array_with_two_elements_appended_has_length_two();
    test_print();
    test_indexing_operator();
    test_vector_constructor();
    test_insert();
    test_remove();
    test_pop_at_index();
    test_pop();
    test_shrink_to_fit();

    return 0;
}

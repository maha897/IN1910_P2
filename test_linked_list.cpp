#include "linked_list.cpp"
#include <cassert>

void test_empty_list_has_length(){
    LinkedList l{};

    assert(l.length() == 0);
}

void test_append(){
    LinkedList l{};
    l.append(1);
    l.append(2);

    assert(l.length() == 2);
}

void test_print(){
    LinkedList l{};

    std::cout << "Testing print for ...\n\n";
    std::cout << "-- default constructor empty list:\n";
    std::cout << "l = ";
    l.print();
    std::cout << "\n";

    l.append(1);
    std::cout << "-- default constructor initialized {1}:\n";
    std::cout << "l = ";
    l.print();
    std::cout << "\n";

    l.append(2);
    l.append(3);
    std::cout << "-- default constructor initialized {1,2,3}:\n";
    std::cout << "l = ";
    l.print();
    std::cout << "\n";
}

void test_index_operator(){
    LinkedList l{{1, 0, 2, 6, 9}};
    l[2] = 5;

    assert(l[1] == 0 && l[2] == 5);

    // Testing range_error
    bool throwed_range_error = false;
    try{
        int l_ = l[10];
    } catch (const std::range_error &e){
        throwed_range_error = true;
    }

    assert(throwed_range_error);
}

void test_insert(){
    LinkedList l{{1,2,3}};

    l.insert(0, 0);
    assert(l[0] == 0);
    l.insert(4, 4);
    assert(l[4] == 4);
    l.insert(15, 2);
    assert(l[2] == 15);
    assert(l.length() == 6);

    // Testing range_error
    bool throwed_range_error = false;
    try{
        l.insert(1,50);
    } catch (const std::range_error &e){
        throwed_range_error = true;
    }

    assert(throwed_range_error);
}

void test_remove(){
    LinkedList l{{1,2,3,3,4,5}};

    l.remove(3);
    assert(l[3] == 4);
    assert(l.length() == 5);
    l.remove(3);
    assert(l[3] == 5);
    assert(l.length() == 4);
    l.remove(3);
    assert(l[2] == 3);
    assert(l.length() == 3);

    // Testing range_error
    bool throwed_range_error = false;
    try{
        l.remove(4);
    } catch (const std::range_error &e){
        throwed_range_error = true;
    }

    assert(throwed_range_error);
}

void test_pop_at_index(){
    LinkedList l{{8,7,6,5}};
    
    assert(l.pop(2) == 6);
    assert(l.pop(1) == 7);
    assert(l.pop(1) == 5);
    assert(l.pop(0) == 8);
    assert(l.length() == 0);
}

void test_pop(){
    LinkedList l{{1,2,3,4,5}};

    assert(l.pop() == 5);
    assert(l.pop() == 4);
    assert(l.pop() == 3);
    assert(l.pop() == 2);
    assert(l.pop() == 1);
    assert(l.length() == 0);
}

void test_vector_constructor(){
    LinkedList l{{2, 3, 5, 7, 11}};

    std::cout << "-- vector constructor initialized {2,3,5,7,11}:\n";
    std::cout << "l = ";
    l.print();
    std::cout << "\n";

    assert(l.length() == 5);
}

int main(){
    test_empty_list_has_length();
    test_append();
    test_print();
    test_index_operator();
    test_insert();
    test_remove();
    test_pop_at_index();
    test_pop();
    test_vector_constructor();

    return 0;
}
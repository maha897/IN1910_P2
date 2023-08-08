#include "linked_array_list.cpp"
#include <iostream>

void test_array_list_node(){
    ArrayListNode node ({1, 2, 3}, nullptr, nullptr);
    std::cout << "Testing elements of arraylistnode instanciated {1,2,3}: \n\n";
    std::cout << "array = ";
    node.array->print();
    std::cout << "\n";
}

void test_array_list_print_get_and_append(){
    LinkedArrayList lal{};  
    lal.append({1, 2});   
    lal.append({4, 5, 6}); 
    std::cout << "Testing linkedarraylist instanciated [[1,2],[4,5,6]]: \n\n";
    std::cout << "lal = ";
    lal.print();  
    std::cout << "\n";

    lal[0]->append(42);   
    std::cout << "Testing append for lal, append(42): \n\n";
    std::cout << "lal = ";
    lal.print();  
    std::cout << "\n";    
}

int main(){
    test_array_list_node();
    test_array_list_print_get_and_append();

    return 0;
}
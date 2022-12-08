#include <iostream>
using namespace std;

int main(){
    int i = 3;
    int* ptr_to_i = &i;
    int** ptr_to_ptr_to_i = &ptr_to_i;

    cout << "address of varaible i (&i): " << &i << std::endl;
    cout << "address of ptr_to_i pointed to (ptr_to_i): " << ptr_to_i << std::endl;
    cout << "address of pointer ptr_to_i (&ptr_to_i): " << &ptr_to_i << std::endl;
    cout << "value of pointer ptr_to_i (*ptr_to_i): " << *ptr_to_i << std::endl;

    cout << "address of ptr_to_ptr_to_i pointed to (ptr_to_ptr_to_i): " << ptr_to_ptr_to_i << std::endl;
    cout << "address of pointerptr_to_ptr_to_i (&ptr_to_ptr_to_i): " << &ptr_to_ptr_to_i << std::endl;
    cout << "value of pointer ptr_to_i (*ptr_to_ptr_to_i): " << (*ptr_to_ptr_to_i) << std::endl;
    cout << "value of pointer ptr_to_i (**ptr_to_ptr_to_i): " << **ptr_to_ptr_to_i << std::endl;
    return 0;
}



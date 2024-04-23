#include<cassert>
#include<iostream>
#include "linked_list.hpp"

using namespace std;

bool test_push_back() { 
    // set up
	LinkedList lst;

    //excution
	bool return1 = lst.push_back(10);
	bool return2 = lst.push_back(20);

    //validation
	assert(return1 == true);
	assert(return2 == true);
	assert(lst.get_head()->value == 10);
	assert(lst.get_head()->next->value == 20);

    // clean up
	return true;
}

bool test_is_empty() {
	// set up
	LinkedList lst;
	LinkedList lst2;
	lst2.push_back(10);

	//execution
	bool return1 = lst.is_empty();
	bool return2 = lst2.is_empty();

	// validation
	assert(return1 == true);
	assert(return2 == false);

	//cleanup
	//destructors clear dynamically allocated memory
	return true;
}


bool test_size() { 
	// set up
	LinkedList lst;
	LinkedList lst2;
	lst2.push_back(10);
	lst2.push_back(20);
	lst2.push_back(30);

	//execution
	int return1 = lst.size();
	int return2 = lst2.size();

	//validation
	assert(return1 == 0);
	assert(return2 == 3);

	//cleanup
	// deconstructor handles dynamically allocated memory
	return true;
}

bool test_push_front() { 
    // set up
    LinkedList lst;

    //excution
    bool return1 = lst.push_front(30);
    bool return2 = lst.push_front(20);
    bool return3 = lst.push_front(10);

    //validation
    assert(return1 == true);
    assert(return2 == true);
    assert(return3 == true);
    assert(lst.get_head()->value == 10);
    assert(lst.get_head()->next->value == 20);
    assert(lst.get_head()->next->next->value == 30);

    // clean up
    // deconstructor covers dynamically allocated memory
    return true;
}

bool test_insert() {
	// set up
	LinkedList lst;
	
	// execution
	bool return0 = lst.insert(9, 10);
	bool return1 = lst.insert(0, 10);
	bool return2 = lst.insert(5, 10);
	bool return3 = lst.insert(1, 30);
	bool return4 = lst.insert(1, 20);

	// validation
	assert(return0 == false);
	assert(return1 == true);
	assert(return2 == false);
	assert(return3 == true);
	assert(return4 == true);
	assert(lst.get_head()->value == 10);
	assert(lst.get_head()->next->value == 20);
	assert(lst.get_head()->next->next->value == 30);

	// cleanup
	// deconstructor deletes dynamically allocated memory
	return true;
}

bool test_remove() { 
	LinkedList lst;
	lst.push_back(10);
	lst.push_back(20);
	lst.push_back(30);

	bool return1 = lst.remove(1);
	bool return2 = lst.remove(0);
	bool return3 = lst.remove(2);

	assert(return1 == true);
	assert(return2 == true);
	assert(return3 == false);
	assert(lst.get_head()->value == 30);

	return true;
}

bool test_remove_value() {
	LinkedList lst;
	lst.push_back(10);
	lst.push_back(20);
	lst.push_back(30);

	bool return1 = lst.remove_value(20);
	bool return2 = lst.remove_value(10);
	bool return3 = lst.remove_value(30);
	bool return4 = lst.remove_value(40);

	assert(return1 == true);
	assert(return2 == true);
	assert(return3 == true);
	assert(return4 == false);

	return true;
}



int main() {
    test_push_back();
    test_is_empty();
    test_size();
    test_push_front();
    test_insert();
    test_remove();
	test_remove_value();
}

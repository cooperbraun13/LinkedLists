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
	// setup
	LinkedList lst;
	lst.push_back(10);
	lst.push_back(20);
	lst.push_back(30);

	// execution
	bool return1 = lst.remove(1);
	bool return2 = lst.remove(0);
	bool return3 = lst.remove(2);

	// validation
	assert(return1 == true);
	assert(return2 == true);
	assert(return3 == false);
	assert(lst.get_head()->value == 30);

	// cleanup
	return true;
}

bool test_remove_value() {
	// set up
	LinkedList lst;
	lst.push_back(10);
	lst.push_back(20);
	lst.push_back(30);

	// execution
	bool return1 = lst.remove_value(20);
	bool return2 = lst.remove_value(10);
	bool return3 = lst.remove_value(30);
	bool return4 = lst.remove_value(40);

	// validation
	assert(return1 == true);
	assert(return2 == true);
	assert(return3 == true);
	assert(return4 == false);

	// cleanup
	return true;
}

bool test_search() {
	// setup
	LinkedList lst;
	lst.push_back(10);
	lst.push_back(20);
	lst.push_back(30);

	// execution
	assert(lst.search(10) == 0);
	assert(lst.search(20) == 1);
	assert(lst.search(30) == 2);
	assert(lst.search(40) == -1); // 40 not in the list

	// validation
	cout << "test_search passed!" << endl;

	// cleanup
	return true;
}

bool test_print() {
	// setup
	LinkedList lst;
	lst.push_back(10);
	lst.push_back(20);
	lst.push_back(30);
	
	// execution
	lst.print();

	// validation
	cout << lst.get_head()->value << endl;
	cout << lst.get_head()->next->value << endl;
	cout << lst.get_head()->next->next->value << endl;

	// cleanup
	return true;
}

bool test_Node_default_constructor() {
	// no setup needed
	// execution
	Node* n = new Node();

	// validation
	assert(n->value == 0);
	assert(n->next == nullptr);

	// cleanup
	return true;
}

bool test_Node_constructor_with_value() {
	// setup
	int value = 5;

	// execution
	Node* n = new Node(value);

	// validation
	assert(n->value == value);
	assert(n->next == nullptr);

	// cleanup
	return true;
}

bool test_Node_constructor_with_value_next() {
	// setup
	Node* next_node = new Node(10);
	int value = 5;

	// execution
	Node* n = new Node(value, next_node);

	// validation
	assert(n->value == value);
	assert(n->next == next_node);

	// cleanup
	return true;
}

bool test_Node_copy_constructor() {
	// setup
	Node* og = new Node(5);

	// execution
	Node* copy = new Node(og);

	// validation
	assert(copy->value == og->value);
	assert(copy->next == og->next);

	// cleanup
	return true;
}

bool test_LinkedList_default_constructor() {
	// no setup needed
	// execution
	LinkedList lst;

	// validation
	assert(lst.size() == 0);
	assert(lst.get_head() == nullptr);

	// cleanup
	return true;
}

bool test_LinkedList_constructor_with_value() {
	// setup
	int value = 5;

	// execution
	LinkedList lst(value);

	// validation
	assert(lst.size() == 1);
	assert(lst.get_head() != nullptr);
	assert(lst.get_head()->value == value);

	// cleanup
	return true;
}

bool test_LinkedList_constructor_with_node_pointer() {
	// setup
	Node* node = new Node(10);

	// execution
	LinkedList lst(node);

	// validation
	assert(lst.size() == 1);
	assert(lst.get_head() != nullptr);
	assert(lst.get_head()->value == 10);

	// cleanup
	return true;
}

bool test_LinkedList_copy_constructor() {
	// setup
	LinkedList og;
	og.push_back(5);
	og.push_back(10);

	// execution
	LinkedList copy(&og);

	// validation
	assert(copy.size() == og.size());
	assert(copy.get_head() != nullptr);
	assert(copy.get_head()->value = 5);
	assert(copy.get_head()->next->value = 10);

	// cleanup
	return true;
}

bool test_LinkedList_constructor_from_array() {
	// setup
	int arr[] = {1, 2, 3};

	// execution
	LinkedList lst(arr, 3);

	// validation
	assert(lst.size() == 3);
	assert(lst.get_head() != nullptr);
	assert(lst.get_head()->value = 1);
	assert(lst.get_head()->next->value = 2);
	assert(lst.get_head()->next->next->value = 1);

	// cleanup
	return true;
}

bool test_LinkedList_constructor_from_vector() {
	// setup
	std::vector<int> vec = {4, 5, 6};

	// execution
	LinkedList lst(vec);

	// validation
	assert(lst.size() == 3);
	assert(lst.get_head() != nullptr);
	assert(lst.get_head()->value = 4);
	assert(lst.get_head()->next->value = 5);
	assert(lst.get_head()->next->next->value = 6);

	// cleanup
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
	test_search();
	test_print();
	test_Node_default_constructor();
	test_Node_constructor_with_value();
	test_Node_constructor_with_value_next();
	test_Node_copy_constructor();
	test_LinkedList_default_constructor();
	test_LinkedList_constructor_with_value();
	test_LinkedList_constructor_with_node_pointer();
	test_LinkedList_copy_constructor();
	test_LinkedList_constructor_from_array();
	test_LinkedList_constructor_from_vector();
}

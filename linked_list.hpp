#ifndef LINKED_LIST_HPP
#define LINKED_LIST_HPP

class Node {
    public:
        Node();
        Node(int value);
        Node(int value, Node* next_ptr);
        Node(Node* nde);

        int value;
        Node* next;
        
        ~Node();
};

class LinkedList {
    private:
        Node* head = nullptr;
    public:
        LinkedList();
        LinkedList(int value);
        LinkedList(Node* start);
        LinkedList(LinkedList* lst);
        LinkedList(int* arr, int size);
        LinkedList(std::vector<int>vec);
        Node* get_head() const;
        int size() const; 
        bool is_empty() const;
        bool push_back(int value);
        bool push_front(int value);
        bool insert(int index, int value);
        bool remove(int index);
        bool remove_value(int value);
        int search(int value) const;
        void print() const;
        ~LinkedList();
};

#endif
//
// Created by vscilab on 10/26/2018.
//

#ifndef EX06_LINKEDLIST_LINKEDLIST_H
#define EX06_LINKEDLIST_LINKEDLIST_H

#include <iostream>

namespace edu { namespace vcccd { namespace vc { namespace csv15 {
    template<class T>
    class LinkedList{
        struct Node {
            Node(const T&val, Node* next, Node* prev) : _data(val), _next(next), _prev(prev){
            }

            T _data;
            Node *_next;
            Node *_prev;
        };

        Node *head;
        Node *tail;
        size_t _size;

    public:
        class iterator {
        public:
            iterator(Node *node) : _node(node) {}
            iterator(const iterator &other) : _node(other._node) {}

        public:
            const T &operator*() { return _node->_data; }
            const T &operator*() const { return _node->_data; }
            iterator &operator++() { _node = _node->_next; return *this; }
            iterator operator++(int) { iterator before(*this); _node = _node->_next; return before; }
            bool operator==(const iterator &other) { return other._node == _node; }
            bool operator!=(const iterator &other) { return !operator==(other); }
            Node *node() { return _node; }
        private:
            Node *_node;
        };

    public:
        LinkedList() : _size(0), head(nullptr), tail(nullptr) {}

        LinkedList(const LinkedList &other) : _size(0), head(nullptr), tail(nullptr) {
            for (const T& val : other) {
                push_front(val);
            }
        }

        ~LinkedList() { clear(); }

    public:
        bool empty() const { return _size == 0; }
        T &front() { return head->_data; }
        const T &front() const { return head->_data; }
        T &back() { return tail->_data; }
        const T &back() const { return tail->_data; }
        size_t size() const { return _size; }

    public:
        iterator begin() { return iterator(head); }
        const iterator begin() const { return iterator(head); }
        iterator end() { return iterator(nullptr); }
        const iterator end() const { return iterator(nullptr); }

    public:
        void clear() {
            erase(begin(), end());
            delete head;
            head = nullptr;
            _size = 0;
        }
        iterator insert(iterator where, const T &value) {
            Node *node = where.node();
            Node *newNode = new Node(value, node->_next, node->_prev);

            newNode -> _next = node -> _next;
            newNode -> _prev = node;
            node -> _next -> _prev = newNode;
            node -> _next = newNode;
            return where;
        }
        //iterator erase(iterator where) {}
        iterator erase(iterator first, iterator last) {
            iterator iter = first;
            for(auto i = first; i != last; i++) {
                iter = erase(i);
            }
            return iter;
        }
        void push_back(const T &value) {
            insert(tail, value);
        }
        void pop_back() {
            erase(tail);
        }
        void push_front(const T &value) {
            insert(head, value);}
        void pop_front() {
            erase(head);
        }

    public:
        void swap(LinkedList &other) {
            std::swap(this -> head, other.head);
            std::swap(this -> tail, other.tail);
            std::swap(this -> _size, other._size);
        }

/*    private:
        Node *head;
        Node *tail;
        size_t _size;
*/
    public:
        iterator erase(iterator where){
            Node *n = where.node();
            if (head == nullptr && tail == nullptr) return where;
            if (n -> _prev != nullptr) {
                n -> _prev -> _next = n -> _next;
            }
            else {
                head = n -> _next;
            }
            if (n -> _next != nullptr) {
                n -> _next -> _prev = n -> _prev;
            }
            else {
                tail = n -> _prev;
            }
            delete n;
            return n -> _prev;
        }
/*
        void insert(Node<T> *n, const T &val){
            Node<T> *newNode = new Node<T>(val, _next, _prev);

            newNode -> _next = n -> next;
            newNode -> _prev = n;
            n -> _next = newNode;
            n -> next -> _prev = newNode;
        }
*/
    };
}}}}
#endif //EX06_LINKEDLIST_LINKEDLIST_H

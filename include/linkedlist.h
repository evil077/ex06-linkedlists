//
// Created by vscilab on 10/26/2018.
//

#ifndef EX06_LINKEDLIST_LINKEDLIST_H
#define EX06_LINKEDLIST_LINKEDLIST_H
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
        iterator begin() { return interator(head); }
        const iterator begin() const { return interator(head); }
        iterator end() { return interator(nullptr); }
        const iterator end() const { return interator(nullptr); }

    public:
        void clear() {}
        iterator insert(iterator where, const T &value) {
            Node<T> *newNode = new Node<T>(val, _next, _prev);

            newNode -> _next = n -> next;
            newNode -> _prev = n;
            n -> _next = newNode;
            n -> next -> _prev = newNode;
        }
        //iterator erase(iterator where) {}
        iterator erase(iterator first, iterator last) {
            for(auto i = first; i != last; i++) {
                erase(i);
            }
        }
        void push_back(const T &value) {
            insert(tail, value);
        }
        void pop_back() {
            std::cout(tail);
            erase(tail);
        }
        void push_front(const T &value) {
            insert(head, value);}
        void pop_front() {
            std::cout(head);
            erase(head);
        }

    public:
        void swap(LinkedList &other) {
            std::swap(this -> head, other.head);
            std::swap(this -> tail, other.tail);
            std::swap(this -> size, other.size);
        }

/*    private:
        Node *head;
        Node *tail;
        size_t _size;
*/
    public:
        void erase(iterator where){
            Node<T> *n = iterator.node();
            if (head == nullptr && tail == nullptr) return;

            if (n -> _prev != nullptr) {
                n -> prev -> _next = n -> next;
            }
            else {
                head = n -> next;
            }

            if (n -> _next != nullptr) {
                n -> next -> _prev = n -> prev;
            }

            else {
                tail = n -> prev;
            }

            delete n;
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

//
// Created by Aviv on 5/30/2022.
//

#ifndef PROJECT_DLIST_H
#define PROJECT_DLIST_H



/**
 * Data Structure that implement a dual linked list.
 *  the data type, T, need to have:
 *  default c'tor, operator=, copy c'tor
 */
/**
* base Node in the list. so user can access a node in O(1) time.
* @tparam T
*/
template<class T>
class DList;

template<class T>
class Node {
    friend DList<T>;
    Node *next;
    Node *prev;
    void deleteNode()
    {
        this->prev->next = this->next;
        if (this->next != nullptr) {
            this->next->prev = this->prev;
        }
        delete this;
    }
public:
    T data;
};

template<class T>
class DList {
    friend Node<T>;
    Node<T> *head;

public:
    DList() : head(new(Node<T>)) {
        head->next = nullptr;
        head->prev = nullptr;
    }

    DList(const DList& src) = delete;

    ~DList() {
        while (head->next != nullptr) {
            head->next->deleteNode();
        }
        delete head;
    }


    DList& operator= (const DList& list_to_copy)
    {
        if(this == &list_to_copy){
            return *this;
        }
        Node<T>* new_lists_head  = new Node<T>;
        new_lists_head->next = nullptr;
        new_lists_head->prev = nullptr;
        const Node<T>* curr = list_to_copy.head->next;
        Node<T>* prev = new_lists_head;
        while(curr != nullptr) {
            Node<T> *next = new (std::nothrow) Node<T>;
            if(next == nullptr){
                while(new_lists_head->next != nullptr) {
                    deleteNode(new_lists_head->next);
                }
                delete new_lists_head;
                throw std::bad_alloc();
            }
            next->data = curr->data;
            next->next = nullptr;
            next->prev = prev;
            prev->next = next;
            curr = curr->next;
            prev = next;
        }
        while(this->head->next != nullptr) {
            deleteNode(this->head->next);
        }
        delete this->head;
        this->head = new_lists_head;
        return *this;
    }

    Node<T>* insertFirst(const T& to_insert_first)
    {
        Node<T>* new_node = new (Node<T>);
        new_node->data = to_insert_first;
        new_node->next = head->next;
        new_node->prev = head;
        if(head->next != nullptr){
            head->next->prev = new_node;
        }
        head->next = new_node;
        return new_node;
    }

    void deleteNode(Node<T>* node_to_delete)
    {
        if (node_to_delete == nullptr){
            return;
        }
        node_to_delete->deleteNode();
    }

    /*
     * iterator made to iterate through the data in the list.
     */
    class iterator{
        Node<T>* current;
        friend DList;
        explicit iterator(Node<T>* init) : current(init) {}
    public:
        T& getData() const{
            return current->data;
        }

        Node<T>* operator* ()
        {
            return current;
        }
        const iterator& operator ++ ()
        {
            current = current->next;
            return *this;
        }
        iterator operator++ (int)
        {
            iterator tmp = *this;
            current = current->next;
            return tmp;
        }

        bool operator == (const iterator& iter) const
        {
            return (iter.current == current);
        }
        bool operator != (const iterator& iter) const
        {
            return !(iter == *this);
        }

    };

    iterator begin()
    {
        return iterator(head->next);
    }
    iterator end()
    {
        return iterator(nullptr);
    }

    class ConstIterator{
        const Node<T>* current;
        friend DList;
        explicit ConstIterator(const Node<T>* init) : current(init) {}
    public:
        const T& getData() const{
            return current->data;
        }

        const Node<T>* operator* () const
        {
            return current;
        }
        ConstIterator& operator ++ ()
        {
            current = current->next;
            return *this;
        }
        ConstIterator operator++ (int)
        {
            ConstIterator tmp = *this;
            current = current->next;
            return tmp;
        }

        bool operator == (const ConstIterator& iter) const
        {
            return (iter.current == current);
        }
        bool operator != (const ConstIterator& iter) const
        {
            return !(iter == *this);
        }

    };

    ConstIterator constBegin() const
    {
        return ConstIterator(head->next);
    }
    ConstIterator constEnd() const
    {
        return ConstIterator(nullptr);
    }

};

#endif //PROJECT_DLIST_H

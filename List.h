/*
 * ******************************************************************
 *                                                                  *
 *     There is a template class which called List and its subclass *
 * which called iterator in this head file. Because List is a       *
 * template I make class define (only include class members'        *
 * declaration) and members' definition together in only one file.  *
 *                                                                  *
 *     All of the template class are contained in namespace cyc.    *
 * Declaration is the first and followed are definition.            *
 *                                                                  *
 *     The template class List is a linked list. We can access next *
 * and previous element only by current element. We can add or      *
 * delete element in any position of this linked list.              *
 *                                                                  *
 *     The subclass iterator is like a point which is used to       *
 * access value of current element, access next and previous        *
 * element.                                                         *
 *                                                                  *
 *     The template class List have basic functions which are       *
 * constructor, destructor and assignment operator. They also have  *
 * special functions which are:                                     *
 *                                                                  *
 *     empty(): return a bool explain whether the List is empty.    *
 *     get_size(): return an int explain the List size.             *
 *     find(T): return a iterator where the element live.           *
 *     begin(): return a iterator which point head element.         *
 *     end(): return a iterator which point next of tail element.   *
 *     rbegin(): return a iterator which point tail element.        *
 *     rend(): return a iterator which point previous of head       *
 *         element.                                                 *
 *     insert_front(iterator, T): add element before the iterator   *
 *         point, no return.                                        *
 *     insert_back(iterator, T): add element after the iterator     *
 *         point, no return.                                        *
 *     erase(iterator): delete element where the iterator point, no *
 *         return.                                                  *
 *     clear(): delete all element, no return.                      *
 *                                                                  *
 *     The subclass iterator have basic function which are          *
 * constructor, destructor and assignment operator. They also have  *
 * special functions which are:                                     *
 *                                                                  *
 *     operator*(): dereference current iterator to access value of *
 *         current element.                                         *
 *     operator->(): dereference current iterator to access members *
 *         of current element.                                      *
 *     operator==(iterator): return whether two iterator is equal.  *
 *     operator!=(iterator): return whether two iterator is not     *
 *         equal.                                                   *
 *     operator++(): let itself point next element on linked list,  *
 *         return itself.                                           *
 *     operator--(): let itself point pervious element on linked    *
 *         list, return itself.                                     *
 *                                                                  *
 * ******************************************************************
 */

#ifndef SUMMERPROJECT_LIST_H
#define SUMMERPROJECT_LIST_H

namespace cyc
{
    template <typename T>
    class List
    {
    private:
        struct Node
        {
            T *pdata;
            Node *pre, *next;
        } *head, *tail;
        int size;
    public:
        class iterator
        {
        private:
            Node *ptr;
        public:
            friend class List;
            iterator(Node *p);
            ~iterator();
            iterator(const iterator &rhs);
            iterator &operator=(const iterator &rhs);

            T &operator*() const;
            T *operator->() const;
            bool operator==(const iterator &obj) const;
            bool operator!=(const iterator &obj) const;
            iterator &operator++();
            iterator &operator--();
        };

        List();
        ~List();
        List(const List &rhs);
        List &operator=(const List &rhs);

        bool empty() const;
        int get_size() const;
        iterator find(const T &rhs) const;
        iterator begin() const;
        iterator end() const;
        iterator rbegin() const;
        iterator rend() const;

        void insert_front(const iterator &pos, const T &rhs);
        void insert_back(const iterator &pos, const T &rhs);
        void erase(const iterator &pos);
        void clear();
    };

    /*
     * ******************************************************************
     *                                                                  *
     *     All after here are definitions of functions of class List.   *
     *                                                                  *
     * ******************************************************************
     */

    template <typename T>
    List<T>::iterator::iterator(Node *p)
            : ptr(p)
    {
        ;
    }

    template <typename T>
    List<T>::iterator::~iterator()
    {
        ;
    }

    template <typename T>
    List<T>::iterator::iterator(const iterator &rhs)
            : ptr(rhs.ptr)
    {
        ;
    }

    template <typename T>
    typename List<T>::iterator &List<T>::iterator::operator=(const iterator &rhs)
    {
        if (&rhs == this)
        {
            return *this;
        }
        ptr = rhs.ptr;
        return *this;
    }

    template <typename T>
    T &List<T>::iterator::operator*() const
    {
        return *(operator->());
    }

    template <typename T>
    T *List<T>::iterator::operator->() const
    {
        return ptr->pdata;
    }

    template <typename T>
    bool List<T>::iterator::operator==(const List<T>::iterator &rhs) const
    {
        return ptr == rhs.ptr;
    }

    template <typename T>
    bool List<T>::iterator::operator!=(const List<T>::iterator &rhs) const
    {
        return ptr != rhs.ptr;
    }

    template <typename T>
    typename List<T>::iterator &List<T>::iterator::operator++()
    {
        ptr = ptr->next;
        return *this;
    }

    template <typename T>
    typename List<T>::iterator &List<T>::iterator::operator--()
    {
        ptr = ptr->pre;
        return *this;
    }

    template <typename T>
    List<T>::List()
            : head(new Node), tail(new Node), size(0)
    {
        *head = {nullptr, nullptr, tail};
        *tail = {nullptr, head, nullptr};
    }

    template <typename T>
    List<T>::~List()
    {
        while (begin() != end())
        {
            erase(begin());
        }
        delete head;
        delete tail;
    }

    template <typename T>
    List<T>::List(const List &rhs)
            : List()
    {
        *this = rhs;
    }

    template <typename T>
    List<T> &List<T>::operator=(const List &rhs)
    {
        if (this == &rhs)
        {
            return *this;
        }
        while (begin() != end())
        {
            erase(begin());
        }
        for (iterator it = rhs.begin(); it != rhs.end(); ++it)
        {
            insert_front(end(), *it);
        }
        return *this;
    }

    template <typename T>
    bool List<T>::empty() const
    {
        return size == 0;
    }

    template <typename T>
    int List<T>::get_size() const
    {
        return size;
    }

    template <typename T>
    typename List<T>::iterator List<T>::find(const T &rhs) const
    {
        iterator it = begin();
        while (it != end() && *it != rhs)
        {
            ++it;
        }
        return it;
    }

    template <typename T>
    typename List<T>::iterator List<T>::begin() const
    {
        return iterator(head->next);
    }

    template <typename T>
    typename List<T>::iterator List<T>::end() const
    {
        return iterator(tail);
    }

    template <typename T>
    typename List<T>::iterator List<T>::rbegin() const
    {
        return iterator(tail->pre);
    }

    template <typename T>
    typename List<T>::iterator List<T>::rend() const
    {
        return iterator(head);
    }

    template <typename T>
    void List<T>::insert_front(const List<T>::iterator &pos, const T &rhs)
    {
        Node *pre_ptr = pos.ptr->pre, *next_ptr = pos.ptr;
        Node *this_ptr = new Node{new T(rhs), pre_ptr, next_ptr};
        pre_ptr->next = next_ptr->pre = this_ptr;
        size++;
    }

    template <typename T>
    void List<T>::insert_back(const List<T>::iterator &pos, const T &rhs)
    {
        Node *pre_ptr = pos.ptr, *next_ptr = pos.ptr->next;
        Node *this_ptr = new Node{new T(rhs), pre_ptr, next_ptr};
        pre_ptr->next = next_ptr->pre = this_ptr;
        size++;
    }

    template <typename T>
    void List<T>::erase(const List<T>::iterator &pos)
    {
        Node *pre_ptr = pos.ptr->pre, *next_ptr = pos.ptr->next;
        pre_ptr->next = next_ptr;
        next_ptr->pre = pre_ptr;
        delete pos.ptr->pdata;
        delete pos.ptr;
        size--;
    }

    template <typename T>
    void List<T>::clear()
    {
        *this = List();
    }
}

#endif //SUMMERPROJECT_LIST_H

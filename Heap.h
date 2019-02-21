/*
 * ******************************************************************
 *                                                                  *
 *     There is a template class which called Heap in this head     *
 * file. Because it's a template I make class define (only include  *
 * class members' declaration) and members' definition together in  *
 * only one file.                                                   *
 *                                                                  *
 *     All of the template class are contained in namespace cyc.    *
 * Declaration is the first and followed are definition.            *
 *                                                                  *
 *     The template class Heap is a binary tree but the top of tree *
 * is minimum than another of the tree.                             *
 *                                                                  *
 *     The template class Heap have basic functions which are       *
 * constructor, destructor and assignment operator. They also have  *
 * special functions which are:                                     *
 *                                                                  *
 *     empty(): return a bool explain whether the Stack is empty.   *
 *     get_size(): return an int explain the Stack size.            *
 *     top(): return the top element of Heap.                       *
 *     push(T): add an object at the top of Heap, no return.        *
 *     pop(): make the top element of Heap delete, no return.       *
 *     clear(): delete all elements, no return.                     *
 *                                                                  *
 * ******************************************************************
 */

#ifndef SUMMERPROJECT_HEAP_H
#define SUMMERPROJECT_HEAP_H

#include "Vector.h"

namespace cyc
{
    template<typename T>
    class Heap
    {
    private:
        Vector <T> v;
        static void swap(T &l, T &r);

    public:
        Heap();
        ~Heap();
        Heap(const Heap &rhs);
        Heap &operator=(const Heap &rhs);

        bool empty() const;
        int get_size() const;
        const T &top() const;

        void push(const T &rhs);
        void pop();
        void clear();
    };

    /*
     * ******************************************************************
     *                                                                  *
     *     All after here are definitions of functions of class Heap.   *
     *                                                                  *
     * ******************************************************************
     */

    template<typename T>
    void Heap<T>::swap(T &l, T &r)
    {
        T t = l;
        l = r, r = t;
    }

    template<typename T>
    Heap<T>::Heap()
    {
        ;
    }

    template<typename T>
    Heap<T>::~Heap()
    {
        ;
    }

    template<typename T>
    Heap<T>::Heap(const Heap &rhs)
            : Heap()
    {
        *this = rhs;
    }

    template<typename T>
    Heap<T> &Heap<T>::operator=(const Heap &rhs)
    {
        if (&rhs == this)
        {
            return *this;
        }
        v = rhs.v;
        return *this;
    }

    template<typename T>
    bool Heap<T>::empty() const
    {
        return get_size() == 0;
    }

    template<typename T>
    int Heap<T>::get_size() const
    {
        return v.get_size();
    }

    template<typename T>
    const T &Heap<T>::top() const
    {
        return v[0];
    }

    template<typename T>
    void Heap<T>::push(const T &rhs)
    {
        v.push_back(rhs);
        int rank = v.get_size() - 1, father = (rank - 1) / 2;
        while (rank != 0 && v[rank] < v[father])
        {
            swap(v[rank], v[father]);
            rank = father;
            father = (rank - 1) / 2;
        }
    }

    template<typename T>
    void Heap<T>::pop()
    {
        v[0] = v[v.get_size() - 1];
        v.pop_back();
        int rank = 0;
        while (v.get_size() > rank * 2 + 1)
        {
            int l_child = rank * 2 + 1, r_child = rank * 2 + 2;
            int min_child = l_child;
            if (r_child < v.get_size() && v[r_child] < v[l_child])
            {
                min_child = r_child;
            }
            if (v[min_child] < v[rank])
            {
                swap(v[rank], v[min_child]);
                rank = min_child;
            }
            else
            {
                break;
            }
        }
    }

    template<typename T>
    void Heap<T>::clear()
    {
        v.clear();
    }
}

#endif //SUMMERPROJECT_HEAP_H

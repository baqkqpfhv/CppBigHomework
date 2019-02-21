/*
 * ******************************************************************
 *                                                                  *
 *     There is a template class which called Queue in this head    *
 * file. Because it's a template I make class define (only include  *
 * class members' declaration) and members' definition together in  *
 * only one file.                                                   *
 *                                                                  *
 *     All of the template class are contained in namespace cyc.    *
 * Declaration is the first and followed are definition.            *
 *                                                                  *
 *     The template class Queue is a queue which obey FIFO(first in *
 * , first out) rule. It means that which is front in hole(first in *
 * will go out by first.                                            *
 *                                                                  *
 *     The template class Queue have basic functions which are      *
 * constructor, destructor and assignment operator. They also have  *
 * special functions which are:                                     *
 *                                                                  *
 *     empty(): return a bool explain whether the Queue is empty.   *
 *     get_size(): return an int explain the Queue size.            *
 *     front(): return the front element of Stack.                  *
 *     push(T): add an object at the top of Queue, no return.       *
 *     pop(): make the top element of Queue delete, no return.      *
 *     clear(): delete all elements, no return.                     *
 *                                                                  *
 * ******************************************************************
 */

#ifndef SUMMERPROJECT_QUEUE_H
#define SUMMERPROJECT_QUEUE_H

#include "List.h"

namespace cyc
{
    template <typename T>
    class Queue
    {
    private:
        List<T> l;

    public:
        Queue();
        ~Queue();
        Queue(const Queue &rhs);
        Queue &operator=(const Queue &rhs);

        bool empty() const;
        int get_size() const;
        const T &front() const;

        void push(const T &rhs);
        void pop();
        void clear();
    };

    /*
     * ******************************************************************
     *                                                                  *
     *     All after here are definitions of functions of class Queue.  *
     *                                                                  *
     * ******************************************************************
     */

    template <typename T>
    Queue<T>::Queue()
    {
        ;
    }

    template <typename T>
    Queue<T>::~Queue()
    {
        ;
    }

    template <typename T>
    Queue<T>::Queue(const Queue &rhs)
            : Queue()
    {
        *this = rhs;
    }

    template <typename T>
    Queue<T> &Queue<T>::operator=(const Queue &rhs)
    {
        if (&rhs == this)
        {
            return *this;
        }
        l = rhs.l;
        return *this;
    }

    template <typename T>
    bool Queue<T>::empty() const
    {
        return get_size() == 0;
    }

    template <typename T>
    int Queue<T>::get_size() const
    {
        return l.get_size();
    }

    template <typename T>
    const T &Queue<T>::front() const
    {
        return *(l.begin());
    }

    template <typename T>
    void Queue<T>::push(const T &rhs)
    {
        l.insert_front(l.end(), rhs);
    }

    template <typename T>
    void Queue<T>::pop()
    {
        l.erase(l.begin());
    }

    template <typename T>
    void Queue<T>::clear()
    {
        l.clear();
    }
}

#endif //SUMMERPROJECT_QUEUE_H

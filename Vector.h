/*
 * ******************************************************************
 *                                                                  *
 *     There is a template class which called Vector in this head   *
 * file. Because it's a template I make class define (only include  *
 * class members' declaration) and members' definition together in  *
 * only one file.                                                   *
 *                                                                  *
 *     All of the template class are contained in namespace cyc.    *
 * Declaration is the first and followed are definition.            *
 *                                                                  *
 *     The template class Vector is like a array but its size isn't *
 * fixed. Users can change its size, add and delete elements at     *
 * last of Vector. Users also can access any element by operator[]. *
 *                                                                  *
 *     The template class Vector have basic functions which are     *
 * constructor, destructor and assignment operator. They also have  *
 * special functions which are:                                     *
 *                                                                  *
 *     empty(): return a bool explain whether the Vector is empty.  *
 *     get_size(): return an int explain the Vector size.           *
 *     operator[](int): return a specified element by conference.   *
 *     push_back(T): add an object behind of Vector, no return.     *
 *     pop_back(): make last element of Vector delete, no return.   *
 *     resize(int): change size, if new is larger, construct, else  *
 *         delete, no return.                                       *
 *     clear(): delete all elements, no return.                     *
 *                                                                  *
 * ******************************************************************
 */

#ifndef SUMMERPROJECT_VECTOR_H
#define SUMMERPROJECT_VECTOR_H

namespace cyc
{
    template<typename T>
    class Vector
    {
    private:
        T **arr;
        int cap, size;
        void recap(int new_cap);

    public:
        Vector();
        ~Vector();
        Vector(const Vector &rhs);
        Vector &operator=(const Vector &rhs);

        bool empty() const;
        int get_size() const;
        const T &operator[](int rank) const;

        T &operator[](int rank);
        void push_back(const T &rhs);
        void pop_back();
        void resize(int new_size);
        void clear();
    };

    /*
     * ******************************************************************
     *                                                                  *
     *     All after here are definitions of functions of class Vector. *
     *                                                                  *
     * ******************************************************************
     */

    template<typename T>
    void Vector<T>::recap(int new_cap)
    {
        cap = new_cap;
        T **new_arr = new T *[cap];
        for (int i = 0; i < size; i++)
        {
            new_arr[i] = arr[i];
        }
        delete[] arr;
        arr = new_arr;
    }

    template<typename T>
    Vector<T>::Vector()
            : cap(1), size(0)
    {
        arr = new T *[cap];
    }

    template<typename T>
    Vector<T>::~Vector()
    {
        for (int i = 0; i < size; i++)
        {
            delete arr[i];
        }
        delete[] arr;
    }

    template<typename T>
    Vector<T>::Vector(const Vector &rhs)
            : Vector()
    {
        *this = rhs;
    }

    template<typename T>
    Vector<T> &Vector<T>::operator=(const Vector &rhs)
    {
        if (&rhs == this)
        {
            return *this;
        }
        for (int i = 0; i < size; i++)
        {
            delete arr[i];
        }
        delete[] arr;
        cap = rhs.cap, size = rhs.size;
        arr = new T *[cap];
        for (int i = 0; i < size; i++)
        {
            arr[i] = new T(*rhs.arr[i]);
        }
        return *this;
    }

    template<typename T>
    bool Vector<T>::empty() const
    {
        return size == 0;
    }

    template<typename T>
    int Vector<T>::get_size() const
    {
        return size;
    }

    template<typename T>
    const T &Vector<T>::operator[](int rank) const
    {
        return *arr[rank];
    }

    template<typename T>
    T &Vector<T>::operator[](int rank)
    {
        return *arr[rank];
    }

    template<typename T>
    void Vector<T>::push_back(const T &rhs)
    {
        if (size == cap)
        {
            recap(cap * 2);
        }
        arr[size++] = new T(rhs);
    }

    template<typename T>
    void Vector<T>::pop_back()
    {
        if (size == 0)
        {
            return;
        }
        delete arr[--size];
        if (cap > 1 && size * 3 < cap)
        {
            recap(cap / 2);
        }
    }

    template<typename T>
    void Vector<T>::resize(int new_size)
    {
        while (size < new_size)
        {
            push_back(T());
        }
        while (size > new_size)
        {
            pop_back();
        }
    }

    template<typename T>
    void Vector<T>::clear()
    {
        *this = Vector();
    }
}

#endif //SUMMERPROJECT_VECTOR_H

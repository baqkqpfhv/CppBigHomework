/*
 * ******************************************************************
 *                                                                  *
 *     There are two functions about sort in this head file.        *
 * Because it's all template I make function declaration and        *
 * definition together in only one file.                            *
 *                                                                  *
 *     All of the template function are contained in namespace cyc. *
 * Declaration is the first and followed are definition.            *
 *                                                                  *
 *     The template function quick_sort(Vector<T> &v, int l, int r) *
 * will sort v between l and r(contain v[l] and v[r]) by quick sort *
 * algorithm.                                                       *
 *                                                                  *
 *     The template function outside_sort(std::ifstream &in_file,   *
 * std::ofstream &out_file, T, const int file_cap = 100000) will    *
 * sort from in_file and then output answer to out_file.            *
 *                                                                  *
 * ******************************************************************
 */

#ifndef SUMMERPROJECT_SORT_H
#define SUMMERPROJECT_SORT_H

#include "Vector.h"
#include "Heap.h"

#include <fstream>
#include <string>

namespace cyc
{
    template<typename T>
    void quick_sort(Vector <T> &v, int l = -1, int r = -1);

    template<typename T>
    void outside_sort(std::ifstream &in_file, std::ofstream &out_file, T *, const int file_cap = 100000);

    /*
     * ******************************************************************
     *                                                                  *
     *     All after here are definitions of functions named quick_sort *
     * and outside_sort.                                                *
     *                                                                  *
     * ******************************************************************
     */

    template<typename T>
    void quick_sort(Vector <T> &v, int l, int r)
    {
        if (l == -1 && r == -1)
        {
            l = 0;
            r = v.get_size() - 1;
        }
        int i = l, j = r;
        T d_mid = v[(l + r) / 2];
        do
        {
            while (v[i] < d_mid)
            {
                i++;
            }
            while (d_mid < v[j])
            {
                j--;
            }
            if (i <= j)
            {
                T t = v[i];
                v[i] = v[j];
                v[j] = t;
                i++;
                j--;
            }
        } while (i <= j);
        if (l < j)
        {
            quick_sort(v, l, j);
        }
        if (i < r)
        {
            quick_sort(v, i, r);
        }
    }

    template<typename T>
    struct SortingNode
    {
        T value;
        int file_rank;

        bool operator<(const SortingNode &rhs) const;
    };

    template<typename T>
    bool SortingNode<T>::operator<(const SortingNode &rhs) const

    {
        return value < rhs.value;
    }

    template<typename T>
    void outside_sort(std::ifstream &in_file, std::ofstream &out_file, T *, const int file_cap)
    {
        int file_num = 0;
        T lhs;
        while (in_file >> lhs)
        {
            Vector<T> v;
            v.push_back(lhs);
            while (v.get_size() < file_cap && in_file >> lhs)
            {
                v.push_back(lhs);
            }
            quick_sort(v);
            std::ofstream file_temp(std::string("sorting_file/") + std::to_string(file_num) + ".txt");
            for (int i = 0; i < v.get_size() - 1; i++)
            {
                file_temp << v[i] << ' ';
            }
            file_temp << v[v.get_size() - 1];
            file_temp.close();
            file_num++;
        }
        Heap<SortingNode<T>> h;
        std::ifstream *file_temp = new std::ifstream[file_num];
        for (int i = 0; i < file_num; i++)
        {
            file_temp[i].open(std::string("sorting_file/") + std::to_string(i) + ".txt");
            T value;
            file_temp[i] >> value;
            h.push({value, i});
        }
        while (!h.empty())
        {
            SortingNode<T> sn(h.top());
            h.pop();
            out_file << sn.value << ' ';
            T value;
            if (file_temp[sn.file_rank] >> value)
            {
                h.push({value, sn.file_rank});
            }
            else
            {
                file_temp[sn.file_rank].close();
            }
        }
        delete[] file_temp;
    }
}

#endif //SUMMERPROJECT_SORT_H

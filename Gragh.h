/*
 * ******************************************************************
 *                                                                  *
 *     There are three class which called Gragh, WeightGragh and    *
 * UnweightGragh in this head file. I make class define(only        *
 * include class members' declaration) in this file and others      *
 * (members' definition) in Gragh.cpp.                              *
 *                                                                  *
 *     All of the classes are contained in namespace cyc.           *
 *                                                                  *
 *     The class Gragh is a abstract base class. WeightGragh and    *
 * UnweightGragh are inherited from Gragh. A Gragh recored node and *
 * edge's information so that after we build a gragh we can         *
 * calculate distant between two nodes.                             *
 *                                                                  *
 *     The abstract base class Gragh have basic functions which are *
 * constructor and destructor. They also have special functions     *
 * which are:                                                       *
 *                                                                  *
 *     add_edge(int,int,int=1): add an edge between two nodes, no   *
 *         return.                                                  *
 *     get_min_path(int,Vector<int>&): calculate and return distant *
 *         between one node and others.                             *
 *                                                                  *
 *     The class WeightGragh have basic functions which are         *
 * constructor, destructor and assignment operator. They also have  *
 * special functions but all are redefine from base class           *
 * functions.                                                       *
 *                                                                  *
 *     The class UnweightGragh have basic functions which are       *
 * constructor, destructor and assignment operator. They also have  *
 * special functions but all are redefine from base class           *
 * functions.                                                       *
 *                                                                  *
 * ******************************************************************
 */

#ifndef SUMMERPROJECT_GRAGH_H
#define SUMMERPROJECT_GRAGH_H

#include "Vector.h"

namespace cyc
{
    class Gragh
    {
    protected:
        struct Edge
        {
            int u, v, e;
        };

        int n, m;
        Vector<Vector<int>> table;
        Vector<Edge> edges;
        static const int oo = 0x3fffffff;

    public:
        Gragh(int v = 0);
        virtual ~Gragh();
        Gragh(const Gragh &rhs);

        virtual void add_edge(int u, int v, int e = 1);
        virtual Vector<int> &get_min_path(int s, Vector<int> &dist) = 0;
    };

    class WeightGragh : public Gragh
    {
    private:
        struct HeapNode
        {
            int dist, u;
            bool operator<(const HeapNode &rhs) const;
        };

    public:
        WeightGragh(int v = 0);
        virtual ~WeightGragh();
        WeightGragh(const WeightGragh &rhs);
        WeightGragh &operator=(const WeightGragh &rhs);

        virtual Vector<int> &get_min_path(int s, Vector<int> &dist);
    };

    class UnweightGragh : public Gragh
    {
    private:

    public:
        UnweightGragh(int v = 0);
        virtual ~UnweightGragh();
        UnweightGragh(const UnweightGragh &rhs);
        UnweightGragh &operator=(const UnweightGragh &rhs);

        virtual Vector<int> &get_min_path(int s, Vector<int> &dist);
    };
}

#endif //SUMMERPROJECT_GRAGH_H

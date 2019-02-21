/*
 * ******************************************************************
 *                                                                  *
 *     There are three class which called Gragh, WeightGragh and    *
 * UnweightGragh in this head file. I make class define(only        *
 * include class members' declaration) in Gragh.h and others        *
 * (members' definition) in this file.                              *
 *                                                                  *
 *     All of the classes are contained in namespace cyc.           *
 *                                                                  *
 * ******************************************************************
 */

#include "Gragh.h"

#include "Vector.h"
#include "Heap.h"
#include "Queue.h"

namespace cyc
{
    Gragh::Gragh(int v) : n(v), m(0)
    {
        table.resize(v);
    }

    Gragh::~Gragh()
    {
        ;
    }

    Gragh::Gragh(const Gragh &rhs)
            : n(rhs.n), m(rhs.m), table(rhs.table), edges(rhs.edges)
    {
        ;
    }

    void Gragh::add_edge(int u, int v, int e)
    {
        table[u].push_back(m++);
        edges.push_back({u, v, e});
    }

    WeightGragh::WeightGragh(int v) : Gragh(v)
    {
        ;
    }

    WeightGragh::~WeightGragh()
    {
        ;
    }

    WeightGragh::WeightGragh(const WeightGragh &rhs)
            : Gragh(rhs)
    {
        ;
    }

    WeightGragh &WeightGragh::operator=(const WeightGragh &rhs)
    {
        if (&rhs == this)
        {
            return *this;
        }
        n = rhs.n;
        m = rhs.m;
        table = rhs.table;
        edges = rhs.edges;
        return *this;
    }


    bool WeightGragh::HeapNode::operator<(const HeapNode &rhs) const
    {
        return dist < rhs.dist;
    }

    Vector<int> &WeightGragh::get_min_path(int s, Vector<int> &dist)
    {
        Vector<bool> vis;
        dist.resize(n);
        vis.resize(n);
        for (int i = 0; i < n; i++)
        {
            dist[i] = +oo;
            vis[i] = false;
        }
        Heap<HeapNode> H;
        H.push({0, s});
        dist[s] = 0;
        while (!H.empty())
        {
            HeapNode node = H.top();
            H.pop();
            if (vis[node.u])
            {
                continue;
            }
            vis[node.u] = true;
            for (int i = 0; i < table[node.u].get_size(); i++)
            {
                const Edge &ed = edges[table[node.u][i]];
                if (dist[node.u] + ed.e < dist[ed.v])
                {
                    H.push({dist[node.u] + ed.e, ed.v});
                    dist[ed.v] = dist[node.u] + ed.e;
                }
            }
        }
        return dist;
    }

    UnweightGragh::UnweightGragh(int v)
            : Gragh(v)
    {
        ;
    }

    UnweightGragh::~UnweightGragh()
    {
        ;
    }

    UnweightGragh::UnweightGragh(const UnweightGragh &rhs)
            : Gragh(rhs)
    {
        ;
    }

    UnweightGragh &UnweightGragh::operator=(const UnweightGragh &rhs)
    {
        if (&rhs == this)
        {
            return *this;
        }
        n = rhs.n;
        m = rhs.m;
        table = rhs.table;
        edges = rhs.edges;
        return *this;
    }

    Vector<int> &UnweightGragh::get_min_path(int s, Vector<int> &dist)
    {
        Vector<bool> vis;
        dist.resize(n);
        vis.resize(n);
        for (int i = 0; i < n; i++)
        {
            dist[i] = +oo;
            vis[i] = false;
        }
        Queue<int> Q;
        Q.push(s);
        dist[s] = 0;
        vis[s] = true;
        while (!Q.empty())
        {
            int node = Q.front();
            Q.pop();
            for (int i = 0; i < table[node].get_size(); i++)
            {
                const Edge &ed = edges[table[node][i]];
                if (vis[ed.v])
                {
                    continue;
                }
                Q.push(ed.v);
                dist[ed.v] = dist[node] + 1;
                vis[ed.v] = true;
            }
        }
        return dist;
    }
}

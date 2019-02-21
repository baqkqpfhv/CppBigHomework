/*
 * ******************************************************************
 *                                                                  *
 *     main.cpp is used to test another file.                       *
 *                                                                  *
 * ******************************************************************
 */

#include "Vector.h"
#include "Stack.h"
#include "Heap.h"

#include "List.h"
#include "Queue.h"

#include "Gragh.h"
#include "Sort.h"

#include <cstdio>
using std::sscanf;

#include <cstring>
using std::strlen;
using std::strcmp;

#include <cctype>
using std::isdigit;

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <fstream>
using std::ifstream;
using std::ofstream;

int read(int l = -2147483647, int r = 2147483647);

void vector_test();
void stack_test();
void heap_test();
void list_test();
void queue_test();
void weightgragh_test();
void unweightgragh_test();
void quicksort_test();
void outsidesort_test();

int main()
{
    cout << "Welcome to Data Structure and Algorithm test interface!";
    while (1)
    {
        cout << endl << endl;
        cout << "0. Vector" << endl;
        cout << "1. Stack" << endl;
        cout << "2. Heap" << endl;
        cout << "3. List" << endl;
        cout << "4. Queue" << endl;
        cout << "5. Single source shortest path algorithm" << endl;
        cout << "6. Sort algorithm" << endl;
        cout << "7. I want to quit." << endl;
        cout << "Please input a number to choose you want to test." << endl;
        int a = read(0, 7);
        if (a == 0) vector_test();
        else if (a == 1) stack_test();
        else if (a == 2) heap_test();
        else if (a == 3) list_test();
        else if (a == 4) queue_test();
        else if (a == 5)
        {
            cout << endl << endl;
            cout << "Is you gragh weight?" << endl;
            cout << "0. Yes(WeightGragh)" << endl;
            cout << "1. No (UnweightGragh)" << endl;
            int b = read(0, 1);
            if (b == 0) weightgragh_test();
            else unweightgragh_test();
        }
        else if (a == 6)
        {
            cout << "Which sort do you want?" << endl;
            cout << "0. Quick sort algorithm" << endl;
            cout << "1. Outside sort" << endl;
            int b = read(0, 1);
            if (b == 0) quicksort_test();
            else outsidesort_test();
        }
        else break;
    }
    return 0;
}

int read(int l, int r)
{
    int ans = 0, sign = 1;
    while (1)
    {
        static char s[1000];
        cin >> s;
        const char *sp = s;
        sign = 1;
        if (*sp == '-')
        {
            ++sp;
            sign = -1;
        }
        while (*sp == '0')
        {
            ++sp;
        }
        bool b = false;
        for (const char *spi = sp; *spi != '\0'; ++spi)
        {
            if (!isdigit(*spi))
            {
                b = true;
                break;
            }
        }
        int len = strlen(sp);
        static const char *maxInt = "2147483647";
        b = len > 10 || (len == 10 && s > maxInt);
        if (b)
        {
            cout << "Please input correct number!" << endl;
            continue;
        }
        sscanf(sp, "%d", &ans);
        ans *= sign;
        b = ans < l || ans > r;
        if (b)
        {
            cout << "Please input correct number!" << endl;
            continue;
        }
        break;
    }
    return ans;
}

void vector_test()
{
    cout << endl << endl;
    cout << "Welcome to vector test!" << endl;
    cyc::Vector<int> v;
    while (1)
    {
        cout << "0. empty()" << endl;
        cout << "1. get_size()" << endl;
        cout << "2. operator[]()" << endl;
        cout << "3. push_back()" << endl;
        cout << "4. pop_back()" << endl;
        cout << "5. resize()" << endl;
        cout << "6. clear()" << endl;
        cout << "7. output one by one" << endl;
        cout << "8. Quit" << endl;
        cout << "Please input a number to choose you want." << endl;
        int a = read(0, 8);
        if (a == 0) cout << (v.empty() ? "Yes" : "No") << endl;
        else if (a == 1) cout << v.get_size() << endl;
        else if (a == 2)
        {
            if (v.empty())
                continue;
            cout << "Please input index." << endl;
            int x = read(0, v.get_size() - 1);
            cout << "The v[" << x << "] is " << v[x] << endl;
        }
        else if (a == 3)
        {
            cout << "Please input the value you want to push." << endl;
            int x = read();
            v.push_back(x);
        }
        else if (a == 4)
        {
            if (!v.empty())
                v.pop_back();
        }
        else if (a == 5)
        {
            cout << "Please input the size you want." << endl;
            int x = read(0);
            v.resize(x);
        }
        else if (a == 6) v.clear();
        else if (a == 7)
        {
            for (int i = 0; i < v.get_size(); i++)
                cout << v[i] << ' ';
            cout << endl;
        }
        else break;
    }
    cout << "The vector test is ending." << endl;
}

void stack_test()
{
    cout << endl << endl;
    cout << "Welcome to stack test!" << endl;
    cyc::Stack<int> s;
    while (1)
    {
        cout << "0. empty()" << endl;
        cout << "1. get_size()" << endl;
        cout << "2. top()" << endl;
        cout << "3. push()" << endl;
        cout << "4. pop()" << endl;
        cout << "5. clear()" << endl;
        cout << "6. Quit" << endl;
        cout << "Please input a number to choose you want." << endl;
        int a = read(0, 6);
        if (a == 0) cout << (s.empty() ? "Yes" : "No") << endl;
        else if (a == 1) cout << s.get_size() << endl;
        else if (a == 2)
        {
            if (!s.empty())
                cout << s.top() << endl;
        }
        else if (a == 3)
        {
            cout << "Please input the value you want to push." << endl;
            int x = read();
            s.push(x);
        }
        else if (a == 4)
        {
            if (!s.empty())
                s.pop();
        }
        else if (a == 5) s.clear();
        else break;
    }
    cout << "The stack test is ending." << endl;
}

void heap_test()
{
    cout << endl << endl;
    cout << "Welcome to heap test!" << endl;
    cyc::Heap<int> h;
    while (1)
    {
        cout << "0. empty()" << endl;
        cout << "1. get_size()" << endl;
        cout << "2. top()" << endl;
        cout << "3. push()" << endl;
        cout << "4. pop()" << endl;
        cout << "5. clear()" << endl;
        cout << "6. Quit" << endl;
        cout << "Please input a number to choose you want." << endl;
        int a = read(0, 6);
        if (a == 0) cout << (h.empty() ? "Yes" : "No") << endl;
        else if (a == 1) cout << h.get_size() << endl;
        else if (a == 2)
        {
            if (!h.empty())
                cout << h.top() << endl;
        }
        else if (a == 3)
        {
            cout << "Please input the value you want to push." << endl;
            int x = read();
            h.push(x);
        }
        else if (a == 4)
        {
            if (!h.empty())
                h.pop();
        }
        else if (a == 5) h.clear();
        else break;
    }
    cout << "The heap test is ending." << endl;
}

void list_test()
{
    cout << endl << endl;
    cout << "Welcome to list test!" << endl;
    cyc::List<int> l;
    while (1)
    {
        cout << "0. empty()" << endl;
        cout << "1. get_size()" << endl;
        cout << "2. find()" << endl;
        cout << "3. insert_front()" << endl;
        cout << "4. insert_back()" << endl;
        cout << "5. erase()" << endl;
        cout << "6. clear()" << endl;
        cout << "7. output one by one" << endl;
        cout << "8. Quit" << endl;
        cout << "Please input a number to choose you want." << endl;
        int a = read(0, 8);
        if (a == 0) cout << (l.empty() ? "Yes" : "No") << endl;
        else if (a == 1) cout << l.get_size() << endl;
        else if (a == 2)
        {
            if (l.empty())
                continue;
            cout << "Please input a value you want to find." << endl;
            int x = read();
            if (l.find(x) != l.end())
                cout << "The value is in the list" << endl;
            else
                cout << "The value is not in the list" << endl;
        }
        else if (a == 3)
        {
            cout << "Please input two value(2nd will add before 1st)" << endl;
            int x = read(), y = read();
            l.insert_front(l.find(x), y);
        }
        else if (a == 4)
        {
            cout << "Please input two value(2nd will add after 1st)" << endl;
            int x = read(), y = read();
            if (l.find(x) != l.end())
                l.insert_back(l.find(x), y);
            else
                l.insert_front(l.end(), y);
        }
        else if (a == 5)
        {
            cout << "Please input a value you want to erase." << endl;
            int x = read();
            if (l.find(x) != l.end())
                l.erase(l.find(x));
        }
        else if (a == 6) l.clear();
        else if (a == 7)
        {
            for (cyc::List<int>::iterator it = l.begin(); it != l.end(); ++it)
                cout << *it << ' ';
            cout << endl;
        }
        else break;
    }
    cout << "The list test is ending." << endl;
}

void queue_test()
{
    cout << endl << endl;
    cout << "Welcome to queue test!" << endl;
    cyc::Queue<int> q;
    while (1)
    {
        cout << "0. empty()" << endl;
        cout << "1. get_size()" << endl;
        cout << "2. front()" << endl;
        cout << "3. push()" << endl;
        cout << "4. pop()" << endl;
        cout << "5. clear()" << endl;
        cout << "6. Quit" << endl;
        cout << "Please input a number to choose you want." << endl;
        int a = read(0, 6);
        if (a == 0) cout << (q.empty() ? "Yes" : "No") << endl;
        else if (a == 1) cout << q.get_size() << endl;
        else if (a == 2)
        {
            if (!q.empty())
                cout << q.front() << endl;
        }
        else if (a == 3)
        {
            cout << "Please input the value you want to push." << endl;
            int x = read();
            q.push(x);
        }
        else if (a == 4)
        {
            if (!q.empty())
                q.pop();
        }
        else if (a == 5) q.clear();
        else break;
    }
    cout << "The queue test is ending." << endl;
}

void weightgragh_test()
{
    cout << endl << endl;
    cout << "Welcome to weightgragh single source path test" << endl;
    cout << "Please input the number of node" << endl;
    int n = read(1);
    cyc::WeightGragh g(n);
    cyc::Vector<int> v;
    v.resize(n);
    while (1)
    {
        cout << "0. add_edge()" << endl;
        cout << "1. get_min_path()" << endl;
        cout << "2. Quit" << endl;
        cout << "Please input a number to choose you want." << endl;
        int a = read(0, 2);
        if (a == 0)
        {
            cout << "Please input two node rank and edge weight." << endl;
            int u = read(0, n - 1), v = read(0, n - 1), e = read();
            g.add_edge(u, v, e);
        }
        else if (a == 1)
        {
            cout << "Please input the start node" << endl;
            int s = read(0, n - 1);
            g.get_min_path(s, v);
            for (int i = 0; i < v.get_size(); i++)
            {
                if (v[i] < 0x3fffffff)
                    cout << v[i] << ' ';
                else
                    cout << "NoPath" << ' ';
            }
            cout << endl;
        }
        else break;
    }
    cout << "The weightgragh test is ending." << endl;
}

void unweightgragh_test()
{
    cout << endl << endl;
    cout << "Welcome to unweightgragh single source path test" << endl;
    cout << "Please input the number of node" << endl;
    int n = read(1);
    cyc::UnweightGragh g(n);
    cyc::Vector<int> v;
    v.resize(n);
    while (1)
    {
        cout << "0. add_edge()" << endl;
        cout << "1. get_min_path()" << endl;
        cout << "2. Quit" << endl;
        cout << "Please input a number to choose you want." << endl;
        int a = read(0, 2);
        if (a == 0)
        {
            cout << "Please input two node rank." << endl;
            int u = read(0, n - 1), v = read(0, n - 1);
            g.add_edge(u, v);
        }
        else if (a == 1)
        {
            cout << "Please input the start node" << endl;
            int s = read(0, n - 1);
            g.get_min_path(s, v);
            for (int i = 0; i < v.get_size(); i++)
            {
                if (v[i] < 0x3fffffff)
                    cout << v[i] << ' ';
                else
                    cout << "NoPath" << ' ';
            }
            cout << endl;
        }
        else break;
    }
    cout << "The unweightgragh test is ending." << endl;
}

void quicksort_test()
{
    cout << endl << endl;
    cout << "Welcome to quick sort test" << endl;
    cout << "Please input the number of numbers will be sort" << endl;
    int n = read(1);
    cout << "Please input n numbers to sort." << endl;
    cyc::Vector<int> v;
    for (int i = 0; i < n; i++)
    {
        int x = read();
        v.push_back(x);
    }
    cyc::quick_sort(v);
    for (int i = 0; i < v.get_size(); i++)
        cout << v[i] << ' ';
    cout << endl;
    cout << "The quick sort is ending." << endl;
}

void outsidesort_test()
{
    cout << endl << endl;
    cout << "Welcome to outside sort test" << endl;
    static char in_file_name[1000], out_file_name[1000];
    cout << "Please input the input file" << endl;
    cin >> in_file_name;
    cout << "Please input the output file" << endl;
    cin >> out_file_name;
    cout << "Please input the file capacity (100000 is better)." << endl;
    int cap = read();
    ifstream ifile(in_file_name);
    ofstream ofile(out_file_name);
    cyc::outside_sort(ifile, ofile, &cap, cap);
    ifile.close();
    ofile.close();
    cout << "The outside sort is ending." << endl;
}

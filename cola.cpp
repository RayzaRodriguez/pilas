#include<vector>
#include<stdio.h>
#include<iostream>

using namespace std;

template <class T> class Stack ;

template <class T>
Stack <T> operator +( const Stack <T> &s1 , const Stack <T> &s2)
{
    Stack <T> result=s1;
    for (unsigned i = 0; i < s2.items.size (); ++i)
    {
            result.items.push_back(s2.items[i]);
    }
    return result;
}

template <class T>
Stack <T> operator -(const Stack <T> &s1 , const Stack <T> &s2)
{
     Stack <T> result;
    for (unsigned i = 0; i < s1.items.size() ; i++)
    {
        int cont =0;
        for(unsigned j =0 ; j < s2.items.size(); j++)
        {
            if(s1.items[i] == s2.items[j])
            {
                cont++;
            }
        }
        if(cont==0)
        {
            result.items.push_back(s1.items[i]);
        }

    }
    return result;
}

template <class T>
class Stack
{
    friend Stack <T> operator +<>( const Stack <T> &s1 , const Stack <T> & s2);
    public :
        vector <T> items ;
        bool empty()const
        {
            return items.empty () ;
        }
        void push ( const T & item )
        {
            items . push_back ( item );
        }
        T pop ()
        {
            T last = items . back ();
            items . pop_back ();
            return last ;
        }
        void print()
        {
         for(int x=0;x<items.size();x++)
         {
             cout<<items[x]<<" ";
         }
        }
};


int main()
{
    Stack <int > a, b;
    a. push (1) ;
    a. push (2) ;
    a.push(3);
    a.push(4);
    b. push (1) ;
    b. push (3) ;
    Stack <int > c = a - b;
    c.print();
}

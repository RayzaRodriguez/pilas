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
            result.items.push_front(s2.items[i]);
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
            result.items.push_front(s1.items[i]);
        }

    }
    return result;
}

template<class T>
ostream& operator << (ostream &output, const Stack<T> &result)
{
    for(unsigned x=0;x<result.items.size();x++)
    {
        output <<result.items[x]<<" ";
    }
    return output;
}

template <class T>
class Stack
{
    friend Stack <T> operator +<>( const Stack <T> &s1 , const Stack <T> & s2);
    friend Stack <T> operator -<>( const Stack <T> &s1 , const Stack <T> & s2);
    friend ostream& operator << <>(ostream &output, const Stack<T> &result);
    public :
        vector <T> items ;
        bool empty()const
        {
            return items.empty () ;
        }
        void push ( const T & item )
        {
            items . push_front ( item );
        }
        T pop ()
        {
            T last = items . front ();
            items . pop_front ();
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
    b. push (2) ;
    b. push (1) ;
    Stack <int > c = a - b;
    //c.print();
    cout<<c;


}

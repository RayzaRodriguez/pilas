#include<vector>
#include<stdio.h>
#include<iostream>

using namespace std;

template <class T> class Stack ;

template <class T>
Stack <T> operator +( const Stack <T> &s1 , const Stack <T> &s2)
{
    Stack <T> result;
    unsigned tam = s1.items.size ()+ s2.items.size();
    int count = 0;
    for (unsigned i = (s1.items.size ()-1); i < tam; --i)
    {
        if(count == 0)
            result.items.push_back(s1.items[i]);
        else
            result.items.push_back(s2.items[i]);
        if(i==0 && count == 0)
        {
             i=s2.items.size();
             count ++;
        }
    }
    return result;
}

template <class T>
Stack <T> operator -(const Stack <T> &s1 , const Stack <T> &s2)
{
    Stack <T> result;

    for (unsigned i = s1.items.size()-1; i > 0  ; --i)
    {
        int cont =0;
        for(unsigned j = s2.items.size()-1; j > 0; --j)
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

template<class T>
ostream& operator << (ostream &output, const Stack<T> &result)
{
    for(unsigned i=0;i<result.items.size();i++)
    {
        output <<result.items[i] << endl;
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
         for(int x=items.size()-1;x>=0;x--)
         {
             cout<<items[x]<<" \n";
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
    b. push (5) ;
    b. push (6) ;
    Stack <int > c = a + b;
    //c.print();
    cout<<c;
}

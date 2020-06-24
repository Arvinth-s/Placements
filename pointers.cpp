//OM NAMO NARAYANA
#include<bits/stdc++.h>
using namespace std;
//error.
//can't convert interger pointer to character pointer
// void display(int* a)
// {
//     cout<<*a<<endl;
//     return;
// }
// int main()
// {
//     char a='a';
//     display(&a);
//     return 0;
// }
class base
{
    protected:
        int i;
    public:
    base(int a)
    {
        i=a;
    }
    void display()
    {
        cout<<"In base class\n";
    }
};

class derived: public base{
    public:
        int j;
        void display(){cout<<"In derived class\n";}
        derived(int a, int b): base(a)
        {
            j=b;
        }
};

void print(base* b)
{
    b->display();
}

int main()
{
    base *b = new base(1);
    derived *d = new derived(1, 2);
    print(b);
    print(d);
}

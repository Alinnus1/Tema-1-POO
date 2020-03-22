#include <iostream>
#include "Vector_de_vectori.h"
#include <vector>

using namespace std;

int main()
{
    int num=0;
    vector<int> m;
    for (int j = 0; j < 4; j++) {
            m.push_back(num);
            num +=15;
        }

    Vector_de_vectori v;
    cin>> v;
    cout<<v<<endl;
    v.Matrice();
    Vector_de_vectori x(v);
    cout<<x<<endl;
    Vector_de_vectori w(3,m);
    cout<<w<<endl;
    v+w;


    return 0;
}

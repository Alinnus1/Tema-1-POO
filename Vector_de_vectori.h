#ifndef VECTOR_DE_VECTORI_H
#define VECTOR_DE_VECTORI_H
#include <vector>
#include <iostream>
using namespace std;

class Vector_de_vectori
{
private:
    int n;
    vector<vector<int>> v;
public:
    Vector_de_vectori();
    Vector_de_vectori(int , vector<int> );
    Vector_de_vectori(const Vector_de_vectori &);
    ~Vector_de_vectori();
    void Matrice();
    friend operator + (const Vector_de_vectori &, const Vector_de_vectori &);
    friend ostream &operator <<(ostream&,Vector_de_vectori &);
    friend istream& operator >>(istream&,Vector_de_vectori&);
};

#endif // VECTOR_DE_VECTORI_H

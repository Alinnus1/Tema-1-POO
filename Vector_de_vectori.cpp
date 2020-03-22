#include "Vector_de_vectori.h"
#include <vector>
#include <iostream>
using namespace std;

Vector_de_vectori::Vector_de_vectori()
{
    this->n=0;
}

Vector_de_vectori::Vector_de_vectori(int n, vector<int> v)
{
    this->n=n;
    for(int i=0;i<n;i++)
        this->v.push_back(v);
}

Vector_de_vectori::Vector_de_vectori(const Vector_de_vectori &z)
{
    if(this->v!=z.v)
    {
        this->n=z.n;
        vector<vector<int>> temp;
        for (int i = 0; i <z.n ; i++)
            temp.push_back(z.v[i]);
        this->v.swap(temp);
    }
}

Vector_de_vectori::~Vector_de_vectori()
{
    this->n=0;
    this->v.resize(this->n);
    this->v.shrink_to_fit();
    cout<< "s a apelat destr"<<endl;
}

void Vector_de_vectori::Matrice()
{
    int maxi=0;
    for (int i=0;i<this->n;i++)
    {
        if (maxi<this->v[i].size())
            maxi=this->v[i].size();
    }
    for (int i=0;i<this->n;i++)
    {
        for (int j=0; j<this->v[i].size(); j++)
            cout << this->v[i][j] << " ";
        for (int j=0; j<maxi-v[i].size();j++)
            cout << "0"<< " " ;
        cout << endl;
    }
}
operator + (const Vector_de_vectori &a, const Vector_de_vectori &b)
{
    int nrcol=0;
    int nrlin=0;
    for (int i=0;i<a.n;i++)
    {
        if (nrcol<a.v[i].size())
            nrcol=a.v[i].size();
    }
    for (int i=0;i<b.n;i++)
    {
        if (nrcol<b.v[i].size())
            nrcol=b.v[i].size();
    }
    if(a.n>b.n)
        nrlin=a.n;
    else
        nrlin=b.n;
    for(int i=0;i<nrlin;i++)
    {
        vector<int> temp (nrcol,0);
        for (int j=0;j<a.v[i].size();j++)
            temp[j]+=a.v[i][j];
        for (int j=0;j<b.v[i].size();j++)
            temp[j]+=b.v[i][j];
        for (int j=0;j<temp.size();j++)
            cout<<temp[j]<<" ";
        cout<<endl;
    }
}
istream& operator >>(istream& input ,Vector_de_vectori& a)
{
    if(a.n==0)
    {
        int h;
        cout<<"ce dimensiune sa aiba v de v?\n";
        input >>h;
        a.n=h;
        for(int i=0;i<a.n;i++)
        {
            vector<int> temp;
            int dimentemp;
            cout<<"ce dimensiune sa aiba al"<<i+1<<"-lea v din v?\n";
            input >> dimentemp;
            for(int j=0;j<dimentemp;j++)
            {
                int x;
                input>>x;
                temp.push_back(x);
            }
            a.v.push_back(temp);
        }
    }
}

ostream &operator<<(ostream &output,Vector_de_vectori & a)
{
    output <<"{ ";
    for (int i = 0; i < a.v.size(); i++)
    {
        output <<"{ ";
        for (int j = 0; j < a.v[i].size(); j++)
            output << a.v[i][j] << " ";
        output <<"}";

    }
    output <<" }";
    return output;
}

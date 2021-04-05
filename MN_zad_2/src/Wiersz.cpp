#include "Wiersz.h"

Wiersz::Wiersz(int n):n(n)
{
    wartosci = new double [n];
    for(int i=0; i<n; i++)
    {
        wartosci[i] = 0;
    }
}

Wiersz::~Wiersz()
{
    delete wartosci;
}

bool Wiersz::setValue(int id, double v)
{
    if(id < 0 || id >= n)
    {
        return false;
    }
    else
    {
        wartosci[id] = v;
    }
    return true;
}

double Wiersz::getValue(int id) const
{
    if(id < 0 || id >= n)
    {
        return 0xffffff;
    }
    else
    {
        return wartosci[id];
    }
}

unsigned int Wiersz::getSize() const
{
    return n;
}

std::string Wiersz::toString()
{
    std::stringstream stream;
    stream << "|   ";
    for(int i=0; i<n; i++)
    {
        stream << std::setw(10) << wartosci[i] << "   ";
    }
    stream << "|";
    return stream.str();
}





Wiersz &Wiersz::operator+(const Wiersz &other)
{
    Wiersz *cpy = new Wiersz(this->getSize());

    if(this->getSize() == other.getSize())
    {
        for(int i=0; i<this->getSize(); i++)
        {
            cpy->setValue(i, this->getValue(i)+other.getValue(i));
        }
    }
    else
    {
        for(int i=0; i<this->getSize(); i++)
        {
            cpy->setValue(i, 0);
        }
    }

    return *cpy;
}

Wiersz &Wiersz::operator-(const Wiersz &other)
{
    Wiersz *cpy = new Wiersz(this->getSize());

    if(this->getSize() == other.getSize())
    {
        for(int i=0; i<this->getSize(); i++)
        {
            cpy->setValue(i, this->getValue(i)-other.getValue(i));
        }
    }
    else
    {
        for(int i=0; i<this->getSize(); i++)
        {
            cpy->setValue(i, 0);
        }
    }
    return *cpy;
}

Wiersz &Wiersz::operator*(double x)
{
    Wiersz *cpy = new Wiersz(this->getSize());

    for(int i=0; i<this->getSize(); i++)
    {
        cpy->setValue(i, this->getValue(i)*x);
    }
    return *cpy;
}

Wiersz &Wiersz::operator/(double x)
{
    Wiersz *cpy = new Wiersz(this->getSize());

    if(x == 0)
    {
        return *this;
    }

    for(int i=0; i<this->getSize(); i++)
    {
        cpy->setValue(i, this->getValue(i)/x);
    }
    return *cpy;
}

bool Wiersz::operator+=(const Wiersz &other)
{
    if(this->getSize() == other.getSize())
    {
        for(int i=0; i<this->getSize(); i++)
        {
            this->setValue(i, this->getValue(i)+other.getValue(i));
        }
        return true;
    }
    else
    {
        return false;
    }
}

bool Wiersz::operator-=(const Wiersz &other)
{
    if(this->getSize() == other.getSize())
    {
        for(int i=0; i<this->getSize(); i++)
        {
            this->setValue(i, this->getValue(i)-other.getValue(i));
        }
        return true;
    }
    else
    {
        return false;
    }
}

bool Wiersz::operator/=(double x)
{
    if(x == 0)
    {
        return false;
    }
    for(int i=0; i<this->getSize(); i++)
    {
        this->setValue(i, this->getValue(i)/x);
    }
    return true;
}

bool Wiersz::operator*=(double x)
{
    for(int i=0; i<this->getSize(); i++)
    {
        this->setValue(i, this->getValue(i)*x);
    }
    return true;
}

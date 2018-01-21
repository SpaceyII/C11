#ifndef __COMPLEXNUM_H__
#define __COMPLEXNUM_H__

#include <iostream>

using namespace std;

template<typename T>
class ComplexNum
{
public:
	explicit ComplexNum(T real = mDefaultReal, T virt = mDefaultVirt);
	virtual ~ComplexNum();

	//Copy Ctor
	ComplexNum(const ComplexNum<T>& src);
	//Overload =
	ComplexNum<T>& operator=(const ComplexNum<T>& src);

	//Overload +
	ComplexNum<T>& operator+(const ComplexNum<T>& src);
	//Overload -
	ComplexNum<T>& operator-(const ComplexNum<T>& src);
	//Overload *
	ComplexNum<T>& operator*(const ComplexNum<T>& src);
	//Overload /
	ComplexNum<T>& operator/(const ComplexNum<T>& src);

	T& getReal();
	T& getVirt();
	bool setReal(const T& real);
	bool setVirt(const T& virt);

	static const T mDefaultReal = 0;
	static const T mDefaultVirt = 0;

	inline void print()
	{
		cout << "The num is " << m_real << " + j" << m_virt << endl;
	}
protected:
	T m_real;
	T m_virt;
};


template<typename T>
ComplexNum<T>::ComplexNum(T real, T virt) : m_real(real), m_virt(virt)
{
	cout << "Constructed:" << real << " + j" << virt << endl;
}

template<typename T>
ComplexNum<T>::~ComplexNum()
{
	cout << "Decontructed~" << endl;
}

template<typename T>
ComplexNum<T>& ComplexNum<T>::operator=(const ComplexNum<T>& src)
{
	if (this == &src)
		return *this;

	this->m_real = src.m_real;
	this->m_virt = src.m_virt;

	return *this;
}

template<typename T>
ComplexNum<T>& ComplexNum<T>::operator+(const ComplexNum<T>& src)
{
	this->m_real += src.m_real;
	this->m_virt += src.m_virt;

	return *this;
}

template<typename T>
ComplexNum<T>& ComplexNum<T>::operator-(const ComplexNum<T>& src)
{
	this->m_real -= src.m_real;
	this->m_virt -= src.m_virt;

	return *this;
}

template<typename T>
ComplexNum<T>& ComplexNum<T>::operator*(const ComplexNum<T>& src)
{
	cout << "TBD" << endl;
}

template<typename T>
ComplexNum<T>& ComplexNum<T>::operator/(const ComplexNum<T>& src)
{
	cout << "TBD" << endl;
}

template<typename T>
T& ComplexNum<T>::getReal()
{
	return m_real;
}

template<typename T>
T& ComplexNum<T>::getVirt()
{
	return m_virt;
}

template<typename T>
bool ComplexNum<T>::setReal(const T& real)
{
	this->m_real = real;
	return true;
}

template<typename T>
bool ComplexNum<T>::setVirt(const T& virt)
{
	this->m_virt = virt;
	return true;
}

#endif
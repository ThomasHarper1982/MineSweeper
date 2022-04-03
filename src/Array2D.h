#ifndef ARRAY2D_H
#define ARRAY2D_H

#include <vector>
#include <algorithm>
#include <cassert>
#include <iostream>
/**
 * class Array2D - Implementation of an 2D Array
 **/

template<typename T>
class Array2D
{
public:
	~Array2D(){
		   std::cout << "Deconstructor: Array2D" << std::endl;
	}

	Array2D(size_t rows, size_t cols): m_RowCount(rows), m_ColCount(cols)
	{
	//assert(rows > 0 && cols > 0);
		m_Items.resize(rows * cols);
		std::fill(m_Items.begin(), m_Items.end(), T());
	}
	Array2D(size_t rows, size_t cols, const T& val) : m_RowCount(rows), m_ColCount(cols)
	{
		//assert(rows > 0 && cols > 0);
		m_Items = new T[rows * cols];
		std::fill(m_Items.begin(), m_Items.end(), val);
	}


	Array2D(const Array2D &source){
   		std::cout << "Copy Constructor "<< this << std::endl;
		m_Items = source.m_Items;//vector copy
		m_RowCount = source.m_RowCount;
		m_ColCount = source.m_ColCount;
	} 

	Array2D& operator=(const Array2D &source){
		std::cout << "Copy assignment "<< this << std::endl;
		if (this == &source)
			return *this;
		delete m_Items;
		m_Items = source.m_Items;//vector copy
		m_RowCount = source.m_RowCount;
		m_ColCount = source.m_ColCount;
		return *this;

	}// 3 : copy assignment operator

	Array2D(Array2D &&source){
		std::cout << "Move Constructor" << std::endl;
		m_RowCount = source.m_RowCount;
		m_ColCount = source.m_ColCount;
		m_Items = std::move(source.m_Items);
	//	source.m_Items = nullptr;
		source.m_RowCount= nullptr;
		source.m_ColCount= nullptr;
	} // 4 : move constructor

	Array2D &operator=(Array2D &&source){
		std::cout << "Move Assignment Operator" << std::endl;
		if (this == &source)
			return *this;
		m_RowCount = source.m_RowCount;
		m_ColCount = source.m_ColCount;
		m_Items = std::move(source.m_Items);
	//	source.m_Items = nullptr;
		source.m_RowCount= nullptr;
		source.m_ColCount= nullptr;
		return *this;
	}
/**
	~Array2D(){
		//m_Items = nullptr;
		m_Items.clear();
		//delete m_Items;
	}**/

	void clear(){
		m_Items.clear();
	}

	size_t rows() const 
	{ 
		return m_RowCount; 
	}
	
	size_t cols() const 
	{ 
		return m_ColCount; 
	}

	T& operator()(const size_t row, const size_t col)
	{
		//std::cout << "op:start" << std::endl;
		//assert(row > 0 && col > 0);
		size_t index = row * m_ColCount + col;
		//std::cout << "op:end" << std::endl;
		return m_Items[index];
	}
	
	const T& operator()(const size_t row, const size_t col) const
	{
		//assert(row > 0 && col > 0);
		size_t index = row * m_ColCount + col;

		return m_Items[index];
	}

	T* operator[](size_t row)
	{
		//assert(row < m_RowCount);
		return &m_Items[row * m_ColCount];
	}

	const T* operator[](size_t row) const
	{
		//assert(row < m_RowCount);

		return &m_Items[row * m_ColCount];
	}

	
private:
	std::vector<T> m_Items;
	size_t  m_RowCount, m_ColCount;
};
#endif
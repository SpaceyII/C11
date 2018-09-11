/* 本段代码的意义在于实现类模板，类模板的声明与实现都必须在头文件中声明完全，这样编译器在
创建模板类的实例的时候才会知道所有的模板实现细节*/

#include <stdexcept>

template<typename T>
class MyArray
{
public:
	MyArray(size_t size) : mSize(size), mArray(nullptr)
	{
		mArray = new T[size];
	}
	virtual ~MyArray()
	{
		if (mArray)
		{
			delete[] mArray;
			mArray = nullptr;
		}
	}

	//左值构造 + 左值赋值
	MyArray(MyArray& src)
	{
		this->mSize = src.mSize;
		this->mArray = src.mArray;
		cout << "This is lvalue ctor ~";
	}
	bool operator=(MyArray& src)
	{
		if (this == &src) return *this;
	}

	//右值构造 + 右值赋值
	MyArray(MyArray&& src)
	{
		//Copy
		this->mSize = src.mSize;
		this->mArray = src.mArray;
		cout << "This is rvalue ctor ~";
		//Reset

	}
	MyArray& operator=(MyArray&& src)
	{
		if (this == &src) return *this;
		if (mArray)
		{
			delete[] mArray;
			mArray = nullptr;
		}

		//Copy
		this->mSize = src.mSize;
		this->mArray = src.mArray;
		cout << "This is rvalue ctor ~";
		//Reset

	}

	size_t getSize() const { return mSize; }
	T& at(size_t index) throw(std::out_of_range)
	{
		if (index >= 0 && index < getSize())
			return mArray[index];
		else
			throw std::out_of_range("MyArray::at: Index out of range.");
	}

protected:
	size_t mSize;
	T* mArray;
};
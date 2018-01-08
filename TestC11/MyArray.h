/* ���δ������������ʵ����ģ�壬��ģ���������ʵ�ֶ�������ͷ�ļ���������ȫ��������������
   ����ģ�����ʵ����ʱ��Ż�֪�����е�ģ��ʵ��ϸ��*/

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

	//��ֵ���� + ��ֵ��ֵ
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

	//��ֵ���� + ��ֵ��ֵ
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
#ifndef __DEPENDENCY_INVERSION_PRINCIPLE__
#define __DEPENDENCY_INVERSION_PRINCIPLE__

/**
* 依赖倒置原则（Dependency Inversion Principle）
* 依赖于抽象(接口),不要依赖具体的实现(类)，也就是针对接口编程。
*/

/*在派生类中，重写 (override) 继承自基类成员函数的实现 (implementation) 时，要满足如下条件：
  一虚：基类中，成员函数声明为虚拟的 (virtual)
  二容：基类和派生类中，成员函数的返回类型和异常规格 (exception specification) 必须兼容
  四同：基类和派生类中，成员函数名、形参类型、常量属性 (constness) 和 引用限定符 (reference qualifier) 必须完全相同
  如此多的限制条件，导致了虚函数重写如上述代码，极容易因为一个不小心而出错
  C++11 中的 override 关键字，可以显式的在派生类中声明，哪些成员函数需要被重写，如果没被重写，则编译器会报错。
*/

#include <iostream>

class HardDisk
{
public:
	virtual void work() = 0;
	virtual ~HardDisk() {}
};

class Memory
{
public:
	virtual void work() = 0;
	virtual ~Memory() {}
};

class CPU
{
public:
	virtual void work() = 0;
	virtual ~CPU() {}
};


class Computer
{
public:
	Computer(HardDisk * harddisk, Memory * memory, CPU * cpu) : m_harddisk(harddisk), m_memory(memory), m_cpu(cpu)
	{
		
	}

	void work()
	{
		m_harddisk->work();
		m_memory->work();
		m_cpu->work();
	}

private:
	HardDisk *m_harddisk;
	Memory *m_memory;
	CPU *m_cpu;
};

class InterCPU : public CPU
{
public:
	virtual void work() override
	{
		std::cout << "我是Inter CPU 我工作良好" << std::endl;
	}
};

class AMDCPU : public CPU
{
public:
	virtual void work() override
	{
		std::cout << "我是AMD CPU 我工作良好" << std::endl;
	}
};

class KingstomMemory : public Memory
{
public:
	virtual void work() override
	{
		std::cout << "我是Kingstom Memory 我工作良好" << std::endl;
	}
};

class SamsungMemory : public Memory
{
public:
	virtual void work() override
	{
		std::cout << "我是Samsung Memory 我工作良好" << std::endl;
	}
};

class WDHardDisk : public HardDisk
{
public:
	virtual void work() override
	{
		std::cout << "我是WD HardDisk 我工作良好" << std::endl;
	}
};

class STHardDisk : public HardDisk
{
public:
	virtual void work() override
	{
		std::cout << "我是ST HardDisk 我工作良好" << std::endl;
	}
};

void DIP_test()
{
	HardDisk * harddisk = nullptr;
	Memory * memory = nullptr;
	CPU * cpu = nullptr;
	Computer * mycomputer = nullptr;

	harddisk = new WDHardDisk;
	memory = new KingstomMemory;
	cpu = new InterCPU;

	std::cout << "---------->>>" << std::endl;
	mycomputer = new Computer(harddisk, memory, cpu);
	mycomputer->work();
	delete mycomputer;
	mycomputer = nullptr;
	delete cpu;
	cpu = nullptr;
	delete memory;
	memory = nullptr;
	delete harddisk;
	harddisk = nullptr;
	std::cout << "<<<----------" << std::endl;

	harddisk = new STHardDisk;
	memory = new SamsungMemory;
	cpu = new AMDCPU;

	std::cout << "---------->>>" << std::endl;
	mycomputer = new Computer(harddisk, memory, cpu);
	mycomputer->work();
	delete mycomputer;
	mycomputer = nullptr;
	delete cpu;
	cpu = nullptr;
	delete memory;
	memory = nullptr;
	delete harddisk;
	harddisk = nullptr;
	std::cout << "<<<----------" << std::endl;

	return;
}

#endif
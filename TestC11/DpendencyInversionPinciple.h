#ifndef __DEPENDENCY_INVERSION_PRINCIPLE__
#define __DEPENDENCY_INVERSION_PRINCIPLE__

/**
* ��������ԭ��Dependency Inversion Principle��
* �����ڳ���(�ӿ�),��Ҫ���������ʵ��(��)��Ҳ������Խӿڱ�̡�
*/

/*���������У���д (override) �̳��Ի����Ա������ʵ�� (implementation) ʱ��Ҫ��������������
  һ�飺�����У���Ա��������Ϊ����� (virtual)
  ���ݣ�������������У���Ա�����ķ������ͺ��쳣��� (exception specification) �������
  ��ͬ��������������У���Ա���������β����͡��������� (constness) �� �����޶��� (reference qualifier) ������ȫ��ͬ
  ��˶�������������������麯����д���������룬��������Ϊһ����С�Ķ�����
  C++11 �е� override �ؼ��֣�������ʽ��������������������Щ��Ա������Ҫ����д�����û����д����������ᱨ��
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
		std::cout << "����Inter CPU �ҹ�������" << std::endl;
	}
};

class AMDCPU : public CPU
{
public:
	virtual void work() override
	{
		std::cout << "����AMD CPU �ҹ�������" << std::endl;
	}
};

class KingstomMemory : public Memory
{
public:
	virtual void work() override
	{
		std::cout << "����Kingstom Memory �ҹ�������" << std::endl;
	}
};

class SamsungMemory : public Memory
{
public:
	virtual void work() override
	{
		std::cout << "����Samsung Memory �ҹ�������" << std::endl;
	}
};

class WDHardDisk : public HardDisk
{
public:
	virtual void work() override
	{
		std::cout << "����WD HardDisk �ҹ�������" << std::endl;
	}
};

class STHardDisk : public HardDisk
{
public:
	virtual void work() override
	{
		std::cout << "����ST HardDisk �ҹ�������" << std::endl;
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
#include <string>
// ����� ����������
class stexcp :public std::exception
{
private:
	std::string errmsg;
public:
	stexcp(const std::string &msg) { errmsg = msg; }
};

// ������ ������ ����
template<class sType>
class Stack
{
private:
	const int Size;						//������������ ������ �����
	int top;							//������ ��������
	sType* StMem;						//��������� �� ��-�� �����

public:
	Stack(int s = 10000);								// ����������� ��� ����������
	~Stack();											// ����������
	Stack(const Stack<sType>& src);						// ����������� �����������
	int size() const { return Size; }					// ������ �����
	void push(const sType& val);						// �������� ������� �� ������� �����
	sType pop();										// ������ � ������� ����� � ��������� 
	sType peek() const;								    // ������ � ������� ����� ��� ��������
	bool full() const { return top == Size - 1; }		// ���� ��������
	bool empty() const { return top == -1; }			// ���� ����
};


// ���������� ������� ������ ����
template<class sType>			// ����������� ��� ����������
Stack<sType>::Stack(int s) : Size(s)
{
	top = -1;
	StMem = new sType[Size];
}

template<class sType>			// ����������
Stack<sType>::~Stack()
{
	delete[] StMem;
}

template<class sType>			// ����������� �����������
Stack<sType>::Stack(const Stack<sType>& src)
{
	Size = src.Size;
	if (top+1>0)
	{
		StMem = new sType[Size];
		for (int i = 0; i < top+1; i++)
			StMem[i] = src.StMem[i];
	}
}

template<class sType>			// �������� ������� �� ������� �����
void Stack<sType>::push(const sType& val)
{
	if (!full())
		StMem[++top] = val;
	else
		throw stexcp("Stack overflow");
}

template<class sType>			// ������ � ������� ����� ��� ��������
sType Stack<sType>::peek() const
{
	if (!empty())
		return StMem[top];
	else
		throw stexcp("Stack is empty");
}
template<class sType>			// ������ � ������� ����� c ��������
sType Stack<sType>::pop()
{
	if (!empty())
		return StMem[top--];
	else
		throw stexcp("Stack is empty");
}

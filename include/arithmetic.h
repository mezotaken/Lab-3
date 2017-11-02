#include "stack.h"
#include <iostream>
class arithmetic
{
	enum lexem_type { OPERATOR, LBRACKET, RBRACKET, NUMBER, VARIABLE, UNKNOWN };	//Типы лексем
	struct Lexem { std::string str; lexem_type tp; };				//Лексема
private:
	static const std::string symb;				//Разрешённые символы
	static double vars[6];						//Переменные
	std::string expr;							//Выражение
	Lexem* pLex;								//Массив лексем
	int nL;										//Количество лексем
	void clrspace();							//Удаление пробелов
	void parse();								//Разбор на лексемы
	bool check_symbols() const;					//Проверка на недопустимые символы
	bool check_brackets() const;				//Проверка на соответствие скобок
	bool check_opers() const;					//Проверка на пропущенные операции/операнды
	int toRPN(Lexem* out) const;				//Перевод в ОПН
	bool priority(Lexem in, Lexem top) const;	//Определение приоритета
public:
	arithmetic(const std::string i_expr);		//Конструктор по данному выражению
	arithmetic& operator=(const arithmetic& a);	//
	~arithmetic() { delete[] pLex; }			//Деструктор
    bool IsCorrect() const;						//Проверка корректности выражения
	double Calc() const;						//Подсчёт результата
	static void SetVar(int p, double val)				//Установить значение переменной
	{ vars[p] = val; }	
	static double GetVar(int p) { return vars[p]; }	//Получить значение переменной
};
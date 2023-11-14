#include "Set.h"


#define MAX_STACK_SIZE 100

typedef struct {
    char data[MAX_STACK_SIZE];
    int top;
} OperatorStack;

typedef struct {
    double data[MAX_STACK_SIZE];
    int top;
} OperandStack;

//主运行函数
int operation();
// 表达式求值函数
double EvaluateExpression(char *expression);
// 计算两个操作数的运算结果
double Calculate(double operand1, char op, double operand2);
// 获取运算符之间的优先级
char GetPriority(char op1, char op2);
// 获取栈顶元素
char GetTop(OperatorStack *stack);
double GetTop(OperandStack *stack);
// 出栈
char Pop(OperatorStack *stack);
double Pop(OperandStack *stack);
//入栈
void Push(OperatorStack *stack, char item);
void Push(OperandStack *stack, double item);
// 判断栈是否为空
int IsEmpty(OperatorStack *stack);
int IsEmpty(OperandStack *stack);
// 初始化栈
void InitStack(OperatorStack *stack);
void InitStack(OperandStack *stack);














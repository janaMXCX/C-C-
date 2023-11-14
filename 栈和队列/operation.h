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

//�����к���
int operation();
// ���ʽ��ֵ����
double EvaluateExpression(char *expression);
// ����������������������
double Calculate(double operand1, char op, double operand2);
// ��ȡ�����֮������ȼ�
char GetPriority(char op1, char op2);
// ��ȡջ��Ԫ��
char GetTop(OperatorStack *stack);
double GetTop(OperandStack *stack);
// ��ջ
char Pop(OperatorStack *stack);
double Pop(OperandStack *stack);
//��ջ
void Push(OperatorStack *stack, char item);
void Push(OperandStack *stack, double item);
// �ж�ջ�Ƿ�Ϊ��
int IsEmpty(OperatorStack *stack);
int IsEmpty(OperandStack *stack);
// ��ʼ��ջ
void InitStack(OperatorStack *stack);
void InitStack(OperandStack *stack);














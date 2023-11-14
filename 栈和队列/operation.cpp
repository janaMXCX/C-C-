
#include "Set.h"

// ��Ϊͷ�ļ�֮����໥����̫���ˣ���һ����ʹ�õ�ʱ�򱨴�Ϊ�ظ�������ֻ��
// ��������д��һ��cpp�ļ�֮�У��ڽ��е���
extern unsigned char Prior[8][8];

// ��ʼ��ջ
void InitStack(OperatorStack *stack)
{
    stack->top = -1;
}

void InitStack(OperandStack *stack)
{
    stack->top = -1;
}

// �ж�ջ�Ƿ�Ϊ��
int IsEmpty(OperatorStack *stack)
{
    return stack->top == -1;
}

int IsEmpty(OperandStack *stack)
{
    return stack->top == -1;
}

// ��ջ
void Push(OperatorStack *stack, char item)
{
    if (stack->top == MAX_STACK_SIZE - 1) {
        printf("Stack Overflow\n");
        exit(1);
    }
    stack->data[++stack->top] = item;
}

void Push(OperandStack *stack, double item)
{
    if (stack->top == MAX_STACK_SIZE - 1) {
        printf("Stack Overflow\n");
        exit(1);
    }
    stack->data[++stack->top] = item;
}

// ��ջ
char Pop(OperatorStack *stack) {
    if (IsEmpty(stack)) {
        printf("Stack Underflow\n");
        exit(1);
    }
    return stack->data[stack->top--];
}

double Pop(OperandStack *stack) {
    if (IsEmpty(stack)) {
        printf("Stack Underflow\n");
        exit(1);
    }
    return stack->data[stack->top--];
}

// ��ȡջ��Ԫ��
char GetTop(OperatorStack *stack)
{
    if (IsEmpty(stack)) {
        printf("Stack is empty\n");
        exit(1);
    }
    return stack->data[stack->top];
}

double GetTop(OperandStack *stack)
{
    if (IsEmpty(stack)) {
        printf("Stack is empty\n");
        exit(1);
    }
    return stack->data[stack->top];
}

// ��ȡ�����֮������ȼ�
char GetPriority(char op1, char op2) {
    int i, j;
    switch (op1) {
        case '+': i = 0; break;
        case '-': i = 1; break;
        case '*': i = 2; break;
        case '/': i = 3; break;
        case '(': i = 4; break;
        case ')': i = 5; break;
        case '#': i = 6; break;
        case '^': i = 7; break;
        default: printf("Invalid operator: %c\n", op1); exit(1);
    }
    switch (op2) {
        case '+': j = 0; break;
        case '-': j = 1; break;
        case '*': j = 2; break;
        case '/': j = 3; break;
        case '(': j = 4; break;
        case ')': j = 5; break;
        case '#': j = 6; break;
        case '^': j = 7; break;
        default: printf("Invalid operator: %c\n", op2); exit(1);
    }
    return Prior[i][j];
}

// ����������������������
double Calculate(double operand1, char op, double operand2)
{
    switch (op) {
        case '+': return operand1 + operand2;
        case '-': return operand1 - operand2;
        case '*': return operand1 * operand2;
        case '/': return operand1 / operand2;
        case '^': return pow(operand1, operand2);
        default: printf("Invalid operator: %c\n", op); exit(1);
    }
}


// ���ʽ��ֵ����
double EvaluateExpression(char *expression)
{
    OperatorStack optrStack;
    OperandStack opndStack;
    InitStack(&optrStack);
    InitStack(&opndStack);

    Push(&optrStack, '#');
    char *ptr = expression;

    while (*ptr != '#' || GetTop(&optrStack) != '#') {
        if (*ptr >= '0' && *ptr <= '9') {
            double operand = 0;
            while (*ptr >= '0' && *ptr <= '9') {
                operand = operand * 10 + (*ptr - '0');
                ptr++;
            }
            Push(&opndStack, operand);
        } else {
            char topOperator = GetTop(&optrStack);
            char currentOperator = *ptr;
            char priority = GetPriority(topOperator, currentOperator);

            if (priority == '<') {
                Push(&optrStack, currentOperator);
                ptr++;
            } else if (priority == '=') {
                Pop(&optrStack);
                ptr++;
            } else if (priority == '>') {
                char operatorOnStack = Pop(&optrStack);
                double operand2 = Pop(&opndStack);
                double operand1 = Pop(&opndStack);
                double result = Calculate(operand1, operatorOnStack, operand2);
                Push(&opndStack, result);
            } else {
                printf("Invalid expression\n");
                exit(1);
            }
        }
    }

    return GetTop(&opndStack);
}



int operation()
{
    char expression[100];
    //��֪��Ϊʲô���뺺������������
    printf("��������ʽ����#��������");
    scanf("%s", expression);

    double result = EvaluateExpression(expression);
    printf("�����: %lf\n", result);

    return 0;
}

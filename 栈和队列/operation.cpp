
#include "Set.h"

// 因为头文件之间的相互引用太多了，这一段在使用的时候报错为重复所以我只能
// 把它单独写到一个cpp文件之中，在进行调用
extern unsigned char Prior[8][8];

// 初始化栈
void InitStack(OperatorStack *stack)
{
    stack->top = -1;
}

void InitStack(OperandStack *stack)
{
    stack->top = -1;
}

// 判断栈是否为空
int IsEmpty(OperatorStack *stack)
{
    return stack->top == -1;
}

int IsEmpty(OperandStack *stack)
{
    return stack->top == -1;
}

// 入栈
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

// 出栈
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

// 获取栈顶元素
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

// 获取运算符之间的优先级
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

// 计算两个操作数的运算结果
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


// 表达式求值函数
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
    //不知道为什么输入汉语这里乱码了
    printf("请输入表达式（以#结束）：");
    scanf("%s", expression);

    double result = EvaluateExpression(expression);
    printf("结果是: %lf\n", result);

    return 0;
}

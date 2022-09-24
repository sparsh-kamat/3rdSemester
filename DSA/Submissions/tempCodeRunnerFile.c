char peek(char *stack, int top)
{
    if (top == -1)
        return ' ';
    else
        return stack[top];
}
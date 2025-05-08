#include <stdint.h>
#define TRUE    1U
#define FALSE   0U
#define BOOL    uint8_t

#define STACK_SIZE_B    256

typedef struct stStack
{
    uint32_t m_index;
    uint32_t m_array[STACK_SIZE_B];
}stStack;

BOOL isEmpty(stStack* a_pStack)
{
    return (0U == a_pStack->m_index);
}

BOOL isFull(stStack* a_pStack)
{
    return (STACK_SIZE_B == a_pStack->m_index);
}

BOOL push(stStack* a_pStack, uint32_t a_value)
{
    if(TRUE == isFull(a_pStack))
    {
        printf("Stack is full\n");
        return FALSE;
    }

    a_pStack->m_array[a_pStack->m_index] = a_value;
    a_pStack->m_index++;
    return TRUE;
}

BOOL pop(stStack* a_pStack, uint32_t* a_pValue)
{
    if(TRUE == isEmpty(a_pStack))
    {
        printf("Stack is empty\n");
        return FALSE;
    }

    a_pStack->m_index--;
    *a_pValue = a_pStack->m_array[a_pStack->m_index];
    return TRUE;
}

BOOL peek(stStack* a_pStack, uint32_t* a_pValue)
{
    if(TRUE == isEmpty(a_pStack))
    {
        printf("Stack is empty\n");
        return FALSE;
    }
    *a_pValue = a_pStack->m_array[a_pStack->m_index-1];
    return TRUE;
}






int main(void)
{
    return 0;
}
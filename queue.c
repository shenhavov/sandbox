#include <stdint.h>
#define TRUE    1U
#define FALSE   0U
#define BOOL    uint8_t

#define Q_SIZE_B    256

typedef struct stQ
{
    uint32_t m_head;
    uint32_t m_tail;
    uint32_t m_size;
    uint32_t m_array[Q_SIZE_B]
}stQ;

BOOL enqueue(stQ* a_pQueue, uint32_t a_value)
{
    if(a_pQueue->m_size >= Q_SIZE_B)
    {
        return FALSE;
    }

    a_pQueue->m_array[a_pQueue->m_tail] = a_value;
    (a_pQueue->m_size)++;
    a_pQueue->m_tail = (a_pQueue->m_tail + 1) % Q_SIZE_B;


    return TRUE;
}


BOOL dequeue(stQ* a_pQueue, uint32_t* a_pVal)
{
    if(0U == a_pQueue->m_size)
    {
        return FALSE;
    }

    *a_pVal = a_pQueue->m_array[a_pQueue->m_head];
    a_pQueue->m_size--;
    a_pQueue->m_head = (a_pQueue->m_head+1)% Q_SIZE_B;
    return TRUE;
}

int main(void)
{
    return 0;
}
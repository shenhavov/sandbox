#include <stdint.h>
#define TRUE    1U
#define FALSE   0U
#define BOOL    uint8_t


typedef struct stNode
{
    uint32_t m_num;
    stNode*  m_pNext;
}stNode;

stNode* addNextNode( stNode* a_pHead, uint32_t a_num)
{
    stNode* ptr = (stNode*)malloc(sizeof(stNode));
    if(ptr == NULL)
    {
        printf("addNextNode malloc error");
        return NULL;    
    }
    ptr->m_num = a_num;
    ptr->m_pNext = NULL;

    if(a_pHead == NULL)//case: this is the first node
    {
        return ptr;
    }
    else
    {
        a_pHead->m_pNext = ptr; 
    }
    return a_pHead;
}

stNode* addNodeAtTheEnd(stNode* a_pHead, uint32_t a_num)
{
    stNode* ptr = a_pHead;
    if(ptr == NULL)
    {
        return addNextNode(a_pHead, num);
    }

    while(ptr->m_pNext != NULL)
    {
        ptr=ptr->m_pNext;
    }

    addNextNode(ptr,a_num);
    return a_pHead;
}

void printMyLinkedList(stNode* a_pHead)
{
    if(a_pHead == NULL)
    {
        printf("L.L is empty");
        return;
    }
    uint32_t index = 0; 
    while(a_pHead->m_pNext != NULL)
    {
        printf("#%d =%d->",&index, &a_pHead->m_num);
        ptr=ptr->m_pNext;
    }
    printf("NULL\n");

}

/// @brief this function detaches current head from list and returns new Head to list or NULL if there's only one node
stNode* detachFirstNode(stNode* a_pHead)
{
    if(a_pHead == NULL)
    {
        return NULL;    
    }

    stNode* newHead = a_pHead->m_pNext;

    a_pHead->m_pNext = NULL;

    return newHead;
}   


stNode* reverseList(stNode* a_pHead)
{
    if( (a_pHead == NULL) || (a_pHead->m_pNext == NULL))// handle the 0,1 node cases!!!
    {
        return a_pHead;
    }

    stNode* next = NULL;
    stNode* curr = a_pHead;
    stNode* prev = NULL;

    while(curr->m_pNext != NULL) 
    {
        next = curr->m_pNext;
        curr->m_pNext = prev;
        prev = curr;
        curr = next;
    }

    curr->m_pNext = prev;

    return curr;
}

stNode* jumpK_nodes(stNode* a_pHead, uint32_t a_k)
{
    stNode* ptr = a_pHead;
    for(uint32_t idx = 0; (idx < a_k) &&(ptr != NULL); idx++ )
    {
        ptr = ptr->m_pNext;
    }
    return ptr;
}

stNode* reverseListByKGroups(stNode* a_pHead, uint32_t a_k)
{
    stNode* kSome_head = a_pHead;
    stNode* remainderHead = a_pHead;
    stNode* tailKsome = a_pHead;
    BOOL isFirstTime = TRUE;
    if((0U == a_k) || (1U == a_k))
    {
        printf("cannot reverse a list with k = %d\n", a_k);
        return a_pHead;
    }

    while(NULL != (remainderHead = jumpK_nodes(remainderHead, a_k)))
    {
        tailKsome = jumpK_nodes(remainderHead, a_k-1);
        if (tailKsome != NULL) 
        {
            tailKsome->m_pNext = NULL;
        }
        kSome_head = reverseList(kSome_head);
        if(TRUE == isFirstTime)
        {
            a_pHead = kSome_head;
            isFirstTime = FALSE;
        }
        tailKsome = jumpK_nodes(kSome_head, a_k-1);
              if (tailKsome != NULL)
        {
            tailKsome->m_pNext = remainderHead;
        }

    }
    return a_pHead;
}

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
BOOL hasCycle(stNode* a_pHead) 
{
    if(a_pHead == NULL)
    {
        return false;
    }

    if(a_pHead->m_pNext == NULL)
    {
        return false;
    }

    stNode* pSlow = a_pHead;
    stNode* pFast = a_pHead->m_pNext;

    while(true)
    {
        if(pSlow == pFast)
        {
            return true;
        }
        if( (pFast == NULL) || (pFast->m_pNext == NULL))
        {
            return false;
        }

        pSlow = pSlow->m_pNext;
        pFast = pFast->m_pNext->m_pNext;
    }
}

bool hasCycle(struct ListNode *head) 
{
    if(head == NULL)
    {
        return false;
    }

    if(head->next == NULL)
    {
        return false;
    }

    struct ListNode* pSlow = head;
    struct ListNode* pFast = head->next;

    while(true)
    {
        if(pSlow == pFast)
        {
            return true;
        }
        if( (pFast == NULL) || (pFast->next == NULL))
        {
            return false;
        }

        pSlow = pSlow->next;
        pFast = pFast->next->next;
    }
}


stNode* mergeTwoLists(stNode* a_pList1, stNode* a_pList2) 
{
    if(a_pList1 == NULL)
    {
        return a_pList2;
    }

    if(a_pList2 == NULL)
    {
        return a_pList1;
    }

    stNode* pNewHead = NULL;
    stNode* pNewtail = NULL;

    while(TRUE)
    {
        if(a_pList1 == NULL)
        {
            pNewtail->m_pNext = a_pList2;
            break;
        }
        if(a_pList2 == NULL)
        {
            pNewtail->m_pNext = a_pList1;
            break;
        }

        if(a_pList1->m_num <= a_pList2->m_num)
        {
            if(pNewHead == NULL)
            {
                pNewHead = a_pList1;
                pNewtail = a_pList1;

            }
            else
            {
                pNewtail->m_pNext = a_pList1;
                pNewtail = pNewtail->m_pNext;
            }
            a_pList1 = a_pList1->m_pNext;
        }
        else
        {
            if(pNewHead == NULL)
            {
                pNewHead = a_pList2;
                pNewtail = a_pList2;
            }
            else
            {
                pNewtail->m_pNext = a_pList2;
                pNewtail = pNewtail->m_pNext;
            }
            a_pList2 = a_pList2->m_pNext;
        }
    }
    return pNewHead;
}

stNode* reverseLL(stNode* a_pHead)
{
    if((a_pHead == NULL) || (a_pHead->m_pNext == NULL))
    {
        return a_pHead;
    }

    stNode* prev = NULL;
    stNode* curr = a_pHead;
    stNode* next = a_pHead->m_pNext;

    while(next != NULL)
    {
        curr->m_pNext = prev;
        prev = curr;
        curr = next;
        next = next->m_pNext;
    }

    curr->m_pNext=prev;
    return curr;
}



stNode* kNodesToTopLL(stNode* a_pHead, int a_k)
{
    size_t len = 0;
    stNode* ptr = a_pHead;

    while(ptr!= NULL)
    {
        ptr = ptr->m_pNext;
        ++len;
    }

    if(len <= a_k)
    {
        return a_pHead;
    }

    stNode* pTail = a_pHead;
    ptr = a_pHead;

    for(size_t i = 0; i < (len-a_k-1); ++i)
    {
        ptr = ptr->m_pNext;
    }
    pTail = ptr->m_pNext;
    ptr->m_pNext = NULL;

    for(ptr = pTail; ptr->m_pNext != NULL;ptr = ptr->m_pNext);

    ptr->m_pNext = a_pHead;
    return pTail;
}


uint64_t getTime(void)
{
    uint32_t high1 , low, high2;

    do
    {
        high1 = getHigh();
        low = getLow();
        high2 = getHigh();
    } while (high1 != high2);

    return (((uint64_t)high1)<<32|low);
}

#include<math.h>
uint32_t* uniformRandomArr(uint32_t a_size) // free() is on user!
{
    uint32_t* arr = (uint32_t*)malloc(a_size*sizeof(uint32_t));
    for(size_t i = 0; i<a_size; i++)
    {
        arr[i] = i;
    }

    size_t randIdx = 0;
    uint32_t tmp = 0;

    for(int32_t i = a_size-1; i>0; --i)
    {
        randIdx = rand()%(i+1);
        tmp = arr[i];
        arr[i] = arr[randIdx];
        arr[randIdx] = tmp;
    }
    return arr;
}


void twoMaxVals( uint32_t* nums, size_t n, uint32_t* retvals)
{
    uint32_t first = INT32_MIN;
    uint32_t second = INT32_MIN;

    for(size_t i =0; i<n; i++)
    {
        if(nums[i] > second)
        {   
            if(nums[i] >= first) // optional: add condition if we want first != second:  && nums[i] != first
            {
                first = nums[i];
            }
            else
            {
                second = nums[i];
            }
        }
    }

    retvals[0] = first;
    retvals[1] = second;
}



uint32_t findTheLoner(uint32_t* nums, size_t n)
{
    uint32_t res = 0;

    for(uint32_t bit = 0; bit<32; bit++)
    {
        uint32_t counter = 0;
        for(uint32_t i = 0 ; i<n ; i++)
        {
            counter += ((nums[i]>>bit)&0x01);
            counter %=3;
        }

        res |= counter<<bit;
    }

    return res;
}


void swap(char* a, char* b)
{
    char temp = *a;
    *a = *b;
    *b = temp;
}


void permute( char* str, int l, int r)
{
    if(l == r) // case finished all possible swappings
    {
        printf("%s\n", *str);
    }

    for(size_t i = l; i<=r; i++)
    {
        swap(&str[i],&str[l]);
        permute(str, l+1, r);
        swap(&str[i],&str[l]);
    }
}





int main(void)
{
    stNode* pHead = NULL;
    printMyLinkedList(pHead);

    pHead = addNodeAtTheEnd(pHead, 10);
    pHead = addNodeAtTheEnd(pHead, 20);
    pHead = addNodeAtTheEnd(pHead, 30);
    pHead = addNodeAtTheEnd(pHead, 40);
    pHead = addNodeAtTheEnd(pHead, 50);
    pHead = addNodeAtTheEnd(pHead, 60);

    printMyLinkedList(pHead);


    return 0;
}
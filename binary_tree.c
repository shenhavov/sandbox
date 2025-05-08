#include <stdint.h>
#define TRUE    1U
#define FALSE   0U
#define BOOL    uint8_t


typedef struct stBST
{
    int32_t m_val;
    stBST* m_pLeft;
    stBST* m_pRight;
}stBST;

stBST* createLeaf(int32_t a_val)
{
    stBST* pRes = (stBST*)malloc(sizeof(stBST));
    if(pRes == NULL)
    {
        printf("new stBST* allocation failed\r\n");
    }
    else
    {
        pRes->m_pLeft = NULL;
        pRes->m_pRight = NULL;
        pRes->m_val = a_val;
    }
    return pRes;
}

stBST* insert(stBST* a_pHead, int32_t a_val)
{
    if(a_pHead == NULL)
    {
        return createLeaf(a_val);
    }

    if(a_val < a_pHead->m_val)
    {
        a_pHead->m_pLeft =  insert(a_pHead->m_pLeft, a_val);
    }
    else if(a_val > a_pHead->m_val)
    {
        a_pHead->m_pRight =  insert(a_pHead->m_pRight, a_val);

    }
    else
    {
    }
    return a_pHead;
}

void inOrderTraversal(stBST* a_pHead)
{
    if(a_pHead == NULL)
    {
        return;
    }

    inOrderTraversal(a_pHead->m_pLeft);
    printf("%d ", a_pHead->m_val);
    inOrderTraversal(a_pHead->m_pRight);
}

stBST* search(stBST* a_pHead, int32_t a_val)
{
    if( (a_pHead == NULL) || (a_pHead->m_val == a_val))
    {
        return a_pHead;
    }

    if(a_val > a_pHead->m_val)
    {
        return search(a_pHead->m_pRight, a_val);
    }
    else
    {
        return search(a_pHead->m_pLeft, a_val);
    }
}


stBST* findMin(stBST* a_pHead)
{
    while (a_pHead && a_pHead->m_pLeft)
    {
        a_pHead = a_pHead->m_pLeft;
    }
    return a_pHead;
}


stBST* deleteNode(stBST* a_pHead, int32_t a_val)
{
    if(a_pHead == NULL)
    {
        return a_pHead;
    }

    if(a_pHead->m_val == a_val)
    {
        stBST* tmp = a_pHead;
        if((a_pHead->m_pLeft == NULL) && (a_pHead->m_pRight == NULL))
        {
            free(a_pHead);
            return NULL;
        }
        else if(a_pHead->m_pLeft == NULL)
        {
            a_pHead = a_pHead->m_pRight;
            free(tmp);
        }
        else if (a_pHead->m_pRight == NULL)
        {
            a_pHead = a_pHead->m_pLeft;
            free(tmp);
        }
        else // full tree
        {
            stBST* tmp = a_pHead->m_pRight;
            while (tmp->m_pLeft != NULL) 
            {
                tmp = tmp->m_pLeft;
            }

            a_pHead->m_val = tmp->m_val;
            a_pHead->m_pRight = deleteNode(a_pHead->m_pRight, tmp->m_val);
        }
        return a_pHead;
    }
    else if(a_pHead->m_val > a_val)
    {
        return deleteNode(a_pHead->m_pLeft, a_val);
    }
    else
    {
        return deleteNode(a_pHead->m_pRight, a_val);
    }
}


int treeDepth(stBST* a_pHead)
{
    if (a_pHead == NULL)
        return 0;

    int leftCtr  = treeDepth(a_pHead->m_pLeft);
    int rightCtr = treeDepth(a_pHead->m_pRight);

    return 1 + (leftCtr > rightCtr ? leftCtr : rightCtr);
}


int RecFunc(stBST* a_pHead, int k, int* cnt)
{
    if (!a_pHead) return -1;

    int retVal = RecFunc(a_pHead->m_pLeft, k, cnt);
    if (retVal != -1) return retVal;

    if (*cnt == k - 1)
        return a_pHead->m_val;

    (*cnt)++;

    return RecFunc(a_pHead->m_pRight, k, cnt);
}

int kthSmallest(stBST* a_pHead, int k)
{
    int cnt = 0;
    return RecFunc(a_pHead, k, &cnt);
}


bool isFullTree(stBST* a_pHead )
{
    if(!a_pHead)
    {
        return true;
    }

    if( ((!a_pHead->m_pLeft) && (a_pHead->m_pRight)) ||
        ((a_pHead->m_pLeft) && (!a_pHead->m_pRight)))
    {
        return false;
    }

    return isFullTree(a_pHead->m_pLeft)&& isFullTree(a_pHead->m_pLeft);
}


int main(void)
{
    return 0;
}
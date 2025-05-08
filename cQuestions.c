#include <stdint.h>
#define TRUE    1U
#define FALSE   0U
#define BOOL    uint8_t


#define I 1
#define V 5
#define X 10
#define L 50
#define C 100
#define D 500
#define M 1000

#define IV 4
#define IX 9
#define XL 40
#define XC 90
#define CD 400
#define CM 900

int romanToInt(char* s) 
{
    int retVal = 0;

    if(s == NULL)
    {
        return retVal;
    }

    for(size_t c = 0; s[c] != '\0'; c++)
    {
        switch(s[c])
        {
            case 'I':
            {
                if(s[c+1] == 'V')
                {
                    retVal+=IV;
                    c++;
                }
                else if(s[c+1] == 'X')
                {
                    retVal+=IX;
                    c++;
                }
                else
                {
                    retVal+=I;
                }
            }
            break;
            case 'V':
            {
                retVal+=V;
            }
            break;
            case 'X':
            {
                if(s[c+1] == 'L')
                {
                    retVal+=XL;
                    c++;
                }
                else if(s[c+1] == 'C')
                {
                    retVal+=XC;
                    c++;
                }
                else
                {
                    retVal+=X;
                }
            }
            break;
            case 'L':
            {
                retVal+=L;
            }
            break;
            case 'C':
            {
                if(s[c+1] == 'D')
                {
                    retVal+=CD;
                    c++;
                }
                else if(s[c+1] == 'M')
                {
                    retVal+=CM;
                    c++;
                }
                else
                {
                    retVal+=C;
                }
            }
            break;
            case 'D':
            {
                retVal+=D;
            }
            break;
            case 'M':
            {
                retVal+=M;
            }
            break;
        }
    }
    return retVal;    
}


#define RET_STR_LENGTH  20

char* intToRoman(int num)
{

}

char* reverseWords(char* s) 
{
    
}

#define ASCII_CHAR_SIZE_B 256


bool isIsomorphic(char* s, char* t) 
{
    char charArr[ASCII_CHAR_SIZE_B] = {0};
    while( (*s != '\0')||((*t != '\0')))
    {
        if(charArr[*s] == 0) // new transformation can be formed...
        {
            charArr[*s] = *t;
        }
        else // existing transformation found
        {
            if(charArr[*s] != *t)
            {
               return false;
            }
        }
        s++;
        t++;
    }

    if((*s == '\0') ^ (*t == '\0'))
    {
        return false;
    }

    return true;
}

//Given two strings ransomNote and magazine, return true if ransomNote can be constructed by using the letters from magazine and false otherwise.

//Each letter in magazine can only be used once in ransomNote.

#define NUM_ABC_LETTERS 26

bool canConstruct(char* ransomNote, char* magazine) 
{
    bool m0 = ( magazine == NULL );
    bool r0 = ( ransomNote == NULL );

    if(r0 == true) // ransomNote is empty
    {
        return true;
    }
    else // rensomNote is non-empty
    {
        if(m0 == true) // when ransom is non-empty but magazine is empty return false
        {
            return false;
        }
    }

    size_t letterOcurr[NUM_ABC_LETTERS] = {0};

    while(*magazine)
    {
        letterOcurr[(*magazine-'a')]++;
        magazine++;
    }

    while(*ransomNote)
    {
        if(letterOcurr[(*ransomNote-'a')] == 0)
        {
            return false;
        }
        else
        {
            letterOcurr[(*ransomNote-'a')]--;
        }
        ransomNote++;
    }

    return true;
}


    uint32_t reverseBits(uint32_t n) 
    {
        n = ((n&0x55555555)<<1|(n&0xAAAAAAAA)>>1);    
        n = ((n&0x33333333)<<2|(n&0xCCCCCCCC)>>2);    
        n = ((n&0x0F0F0F0F)<<4|(n&0xF0F0F0F0)>>4);    
        n = ((n&0x00FF00FF)<<8|(n&0xFF00FF00)>>8);    
        n = (((0xFFFF0000&n)<<16)|((0xFFFF0000&n)>>16));
        return n;
    }



typedef struct {
    int* data;
    size_t size;
    size_t capacity;
} DynamicArray;

#define DYN_ARR_INIT_CAPACITY 16

// 1. Initialize an empty array
void init_array(DynamicArray* arr)
{
    arr->capacity = DYN_ARR_INIT_CAPACITY;
    arr->size = 0U;
    arr->data = (int*)calloc(arr->capacity, sizeof(int));
    if(arr->data  == NULL)
    {
        printf("error: DynamicArray allocation failed\r\n");
        arr->capacity = 0;
    }
}

#define DYN_ARR_MULTIPLIER 2

void append(DynamicArray* arr, int value)
{
    if (arr->size >= arr->capacity)
    {
        int* temp = (int*)realloc(arr->data, arr->capacity * DYN_ARR_MULTIPLIER * sizeof(int));

        if (temp == NULL)
        {
            printf("error: DynamicArray realloc failed\r\n");
            // Optional: arr->capacity = 0;
            return;
        }

        arr->data = temp;
        arr->capacity = arr->capacity * DYN_ARR_MULTIPLIER;
    }

    arr->data[arr->size++] = value;
}



// 3. Print the contents
void print_array(const DynamicArray* arr);

// 4. Free the memory
void free_array(DynamicArray* arr)
{
    if(arr->data != NULL)
    {
        free(arr->data);
    }
    return init_array(arr);
}


int fib( int n)
{
    if( n <= 1)
    {
        return n;
    }
    if (n == 2)
    {
    return 1;
    }

    int tmp = 0;
    int a_1 = 1;
    int a_2 = 0;
    int a_3 = 0;

    for(int i = 3; i < n ; i++)
    {

    }
    return tmp;
}


#pragma pack(1)
typedef union uByte_name
{
    uint8_t _data;
    struct uByte_data
    {
        uint8_t m_enable : 1;
        uint8_t m_modee : 3;
        uint8_t m_status : 4;
    };
}uByte;
#pragma pop()



void* memcpy64(void* dest, const void* src, size_t n)
{
    int N = n/8;
    int r = n%8;
    uint64_t* dest64 = (uint64_t*)dest;
    uint64_t* src64 = (uint64_t*)src;
    

    for(size_t i = 0; i<N; i ++)
    {
        dest64[i] = src64[i];
    }

    uint8_t* dest8 = (uint8_t*)dest;
    uint8_t* src8 = (uint8_t*)src;

    for(size_t i = 0; i<r; i++)
    {
        dest8[N*8+i] = src8[N*8+i];
    }

    return dest;
}

#include "stdint.h"

void* memcpy64_safe(void* dest, const void* src, size_t n)
{
    int N = n/8;
    int r = n%8;
    int srcShift = (uintptr_t) src % 8; // how many bytes src has been shifted forward
    int destShift = (uintptr_t) dest % 8;  // how many bytes dst has been shifted forward

    uint8_t* dest8 = (uint8_t*)(dest);
    dest8 += +destShift;
    uint8_t* src8 = (uint8_t*)src;

    if( destShift != 0)
    {
        printf("dest is not 64 bit aligned");
        
    }

    if( srcShift != 0)
    {
        printf("src is not 64 bit aligned");
    }

    for(size_t i = 0; i< n; i++)
    {
        dest8[i] = src8[i];
    }
    return (void*)dest8;

}

#define ALIGNMENT_B 64

void* aligned64malloc(size_t size)
{
    uint8_t* orig_ptr = (uint8_t*)malloc(size+ALIGNMENT_B);

    size_t shift = ((uintptr_t)orig_ptr)%ALIGNMENT_B; // that means the address is far by shift bytes from being 64 bytes aligned

    // shift is in range 0-63

    orig_ptr[ALIGNMENT_B-shift-1] = shift;
    return (void*)(&orig_ptr[ALIGNMENT_B-shift]);
}

void aligned64free(void* ptr)
{
    uint8_t* u8ptr = (uint8_t*)ptr;
    size_t shift = (size_t)(*(u8ptr-1));
    uint8_t* orig_ptr = (uint8_t*)(u8ptr-ALIGNMENT_B+shift+1);
    free(orig_ptr);

}

bool isBigEndian(void)
{
    uint16_t val = 0x0001;
    uint8_t* firstBytePtr = (uint8_t*)(&val);
    return ((*firstBytePtr) == 0x00); 
}


int thirdSetBitIdx(uint32_t a_num)
{
    int index = 0;
    int bitIndex = 0;
    while(a_num != 0)
    {
        if( (a_num & 0x01) == 1)
        {
            index++;
        }
        if(index == 3)
        {
            return bitIndex;
        }
        a_num >>=1;
        bitIndex++;
    }
    return  -1;
}

uint32_t fib( uint32_t a_num)
{
    if(a_num < 2)
    {
        return a_num;
    }

    uint32_t a_2 = 0;
    uint32_t a_1 = 1;
    uint32_t res = 0;
    for(size_t i = 2; i<=a_num; i++)
    {
        res = a_1 + a_2;
        a_2 = a_1;
        a_1 = res;
    }
    return res;
}


uint64_t trib( uint64_t a_num)
{
    if(a_num < 2)
    {
        return a_num;
    }

    if(a_num == 2)
    {
        return 1;
    }

    uint64_t a_3 = 0;
    uint64_t a_2 = 1;
    uint64_t a_1 = 1;
    uint64_t res = 0;
    for(size_t i = 3; i<=a_num; i++)
    {
        res = a_1 + a_2+ a_3;
        a_3 = a_2;
        a_2 = a_1;
        a_1 = res;
    }
    return res;
}



uint64_t tribRecursive(uint64_t a_num)
{
    if(a_num < 2)
    {
        return a_num;
    }

    if(a_num == 2)
    {
        return 1;
    }

    return tribRecursive(a_num - 1) + tribRecursive(a_num-2) + tribRecursive(a_num-3);
}


#include <stdio.h>
#define FALSE 0
#define TRUE 1
void sevenBoom(uint32_t a_n)
{
    for(size_t i=1; i<=a_n; i++)
    {
        uint8_t isBoom = FALSE;
        if(i%7 == 0) // case devides by 7
        {
            isBoom = TRUE;
        }
        else // check if one of it's digits contain the number 7
        {
            uint32_t tmp = i;
            while(tmp != 0)
            {
                if(tmp%10 == 7)//rightmost digit is 7
                {
                    isBoom = TRUE;
                    break;
                }
                tmp /=10; // shift number one decimal digit to the right
            }
        }
        if(isBoom)
        {
            printf("Boom!\t");
        }
        else
        {
            printf("%d ", i);
        }
    }
}


#include <stdio.h>
#define FALSE 0
#define TRUE 1
void sevenBoomrecursive(uint32_t a_n)
{
    if(a_n == 0)
    {
        return;
    }

    sevenBoomrecursive(a_n-1);

    uint8_t isBoom = FALSE;
    if(a_n%7 == 0) // case devides by 7
    {
        isBoom = TRUE;
    }
    else // check if one of it's digits contain the number 7
    {
        uint32_t tmp = a_n;
        while(tmp != 0)
        {
            if(tmp%10 == 7)//rightmost digit is 7
            {
                isBoom = TRUE;
                break;
            }
            tmp /=10; // shift number one decimal digit to the right
        }
    }
    if(isBoom)
    {
        printf("Boom!\t");
    }
    else
    {
        printf("%d ", a_n);
    }
}

#include <stdio.h>
#define FALSE 0
#define TRUE 1
#define ARR_SIZE 256
uint32_t arr[ARR_SIZE] = {0};

void fillArr(void)
{
    size_t arrIdx=0;
    size_t i = 1;
    while( arrIdx<ARR_SIZE)
    {
        uint8_t isBoom = FALSE;
        if(i%7 == 0) // case devides by 7
        {
            isBoom = TRUE;
        }
        else // check if one of it's digits contain the number 7
        {
            uint32_t tmp = i;
            while(tmp != 0)
            {
                if(tmp%10 == 7)//rightmost digit is 7
                {
                    isBoom = TRUE;
                    break;
                }
                tmp /=10; // shift number one decimal digit to the right
            }
        }
        if(isBoom)
        {
         arr[arrIdx] = i;
         arrIdx++;
        }
        i++;
    }
}

//once it's filled we can use it as a LUT

void preComputed7Boom(uint32_t a_n)
{
    uint32_t arrIdx = 0;
    for(uint32_t i = 1; (i<=a_n)&&(arrIdx <ARR_SIZE ); i++)
    {
        if(i == arr[arrIdx])
        {
            arrIdx++;
            printf("Boom\t");
        }
        else
        {
            printf("%d\t", i);
        }
    }
}

uint32_t reverseBitwise(uint32_t x)
{
    x = ((x&0x55555555)<<1)|((x&0xAAAAAAAA)>>1);
    x = ((x&0x33333333)<<2)|((x&0xCCCCCCCC)>>2);
    x = ((x&0x0F0F0F0F)<<4)|((x&0xF0F0F0F0)>>4);
    x = ((x&0x00FF00FF)<<8)|((x&0xFF00FF00)>>8);
    x = ((x&0x0000FFFF)<<16)|((x&0xFFFF0000)>>16);
    return x;
}

uint32_t andBetweenAnB(uint32_t a, uint32_t b)
{
    uint32_t bigger = a;
    uint32_t smaller = b;
    uint32_t shift = 0;
    if(b > a)
    {
        bigger = b;
        smaller = a;
    }

    while(bigger > smaller)
    {
        bigger>>=1;
        smaller>>=1;
        shift++;
    }

    return bigger<<shift;

}

uint8_t highestBitSwapper( uint8_t num)
{
    return (num&0x77)|((num&0x80)>>4)|((num&0x08)<<4);
}


uint32_t twoBitsSwapper(uint32_t num)
{
    return ((num&0x33333333)<<2)|((num&0xCCCCCCCC)>>2);
}


int countBitFlips(uint32_t a, uint32_t b) {
    uint32_t c = a ^ b;
    int count = 0;
    while (c) {
        c &= (c - 1);
        ++count;
    }
    return count;
}


bool isPalindrome(int x) {
    // Special cases:
    // As discussed above, when x < 0, x is not a palindrome.
    // Also if the last digit of the number is 0, in order to be a palindrome,
    // the first digit of the number also needs to be 0.
    // Only 0 satisfy this property.
    if (x < 0 || (x % 10 == 0 && x != 0)) {
        return false;
    }

    int revertedNumber = 0;
    while (x > revertedNumber) {
        revertedNumber = revertedNumber * 10 + x % 10;
        x /= 10;
    }

    // When the length is an odd number, we can get rid of the middle digit by
    // revertedNumber/10 For example when the input is 12321, at the end of the
    // while loop we get x = 12, revertedNumber = 123, since the middle digit
    // doesn't matter in palidrome(it will always equal to itself), we can
    // simply get rid of it.
    return x == revertedNumber || x == revertedNumber / 10;
}

    #include <unordered_map>
    #include <utility>
int firstUniqChar(string s) 
    {
        std::unordered_map<char,std::pair<int/*to store the occurrences*/,int/*to store the first index*/>> map;

        // first traversal..
        for(size_t i = 0; i<s.size(); i++)
        {
            if(!map.count(s[i]))
            {
                map[s[i]] = {1,i};
            }
            else
            {
                map[s[i]].first++;
            }
        }

        int minIdx = -1;
        bool isFirstUniqChar = false;
        //second traversal
        for (const auto& [ch, info] : map) {

            if(info.first == 1)
            {
                if(isFirstUniqChar == false)
                {
                    isFirstUniqChar = true;
                    minIdx = info.second;
                }
                else
                {
                    minIdx = std::min(minIdx, info.second);
                }
            }
        }
        return minIdx;
    }

// including leading zeros
bool isBitwisePalindrome(uint32_t x)
{
    bool res = true;
    for(uint8_t i = 0; i<16; i++)
    {
        if(((x>>i)&0x01) != ((x>>(31-i))&0x01))
        {
            return false;
        }
    }
    return true;
}


bool isBitwisePalindrome(uint32_t x)
{
    // Count leading zeros
    uint8_t n = 0;
    while (((x >> (31 - n)) & 0x01) == 0) 
    {
        n++;
        if (n == 32)
        {
        return true; // x == 0 → palindrome
        } 
            
    }

    uint8_t bit_width = 32 - n;

    for (uint8_t i = 0; i < bit_width / 2; i++) 
    {
        if (((x >> i) & 0x01) != ((x >> (bit_width - 1 - i)) & 0x01)) 
        {
            return false;
        }
    }

    return true;
}


int thirdSetBit(uint32_t num)
{
    num &=(num-1);
    num &=(num-1);

    num>>=2;
    for(uint32_t i = 0; i<30; i++)
    {
        if((num&0x01) ==1)
        {
            return i+2;
        }
        num>>=1;
    }
    return -1;
}

int main(void)
{
    return 0;
}
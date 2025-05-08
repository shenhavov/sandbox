#include <string>
#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
namespace stock
{
    
using vector = std::vector;

class Solution 
{
    public:
        int maxProfit(vector<int>& prices) {
            int maxprofit = 0;
            int minPrice = prices[0];

            for(size_t i = 0; i < prices.size(); i++) {
                minPrice = std::min(minPrice, prices[i]);  // Correct min price update
                maxprofit = std::max(maxprofit, prices[i] - minPrice);  // Update max profit
            }
            return maxprofit; // Correct return variable
        }

        int countNumDistinctives(vector<int>& nums) 
        {
            int numDistinctives = 0;
            int lastDistictiveNum = INT_FAST32_MAX;
            for(int& num :nums)
            {
                if(num != lastDistictiveNum)// meaning a new distinctive number has been found
                {
                    nums[numDistinctives] = num;
                    numDistinctives++;
                    lastDistictiveNum = num;
                }
            }
            return numDistinctives;
        }

void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n)
{
    int writeIdx = m + n - 1;
    int idx1 = m - 1;
    int idx2 = n - 1;

    // Continue until either array is fully traversed
    while (true)
    {
        if (idx2 < 0)
        {
            // Nothing left in nums2 to merge
            break;
        }

        if (idx1 >= 0 && nums1[idx1] > nums2[idx2])
        {
            nums1[writeIdx--] = nums1[idx1--];
        }
        else
        {
            nums1[writeIdx--] = nums2[idx2--];
        }
    }
}

        int lengthOfLastWord(string s) 
        {
            int lastWordLen = 0;
            int currWordLen = 0;
            if(true == s.empty())
            {
                return lastWordLen;
            }

            for(const char& c : s)
            {
                if( c == ' ')
                {
                    if(currWordLen != 0)
                    {
                        lastWordLen = currWordLen;
                    }
                    currWordLen = 0;
                }
                else
                {
                    if(currWordLen == 0)
                    {
                        lastWordLen = 0;
                    }
                    currWordLen++;
                }
            }

            return (currWordLen+lastWordLen);
        }

        uint32_t stringToU32(string str)
        {
            uint32_t result = 0;
            for (const char& c : str) 
            {
                result <<=1;
                if(c == '1')
                {
                    result++;
                }
            }
            return result;
        }

        string u32ToString(uint32_t num)
        {
            string str{};
            bool isFirstOne {true};
            uint32_t digit = 0;
            for(size_t idx{31}; idx>0; idx--)
            {
                digit = (num>>idx)&1;
                if(digit == 1)
                {
                    if(isFirstOne)
                    {
                        isFirstOne = false;
                    }
                    str +='1';
                }
                else // case 0
                {
                    if(isFirstOne == false)
                    {
                        str+='0';
                    }
                }
            }
            return str;
        }

        string addBinary(string a, string b) 
        {
            return u32ToString(stringToU32(a)+ stringToU32(b));
        }


    int singleNumber(vector<int>& nums) 
    {
        int res = 0;
        for(size_t i = 0; i<nums.size(); i++)
        {
            res += (nums[i]>>i)&0x01;
            res%=3;
            res 
        }
        return res;    
    }

    int hammingWeight(int n) 
    {
        int weight = 0;
        while(n != 0x00)
        {
            n = n&(n-1);
            weight ++;
        }    
        return weight;
    }

std::string reverseWords(std::string s) 
    {
        if(s.empty())
        {
            return s;
        }
        std::stack<size_t> myStack; // saves indices of the words
        int w_start = -1;
        int w_end = 0;
        for(int i = 0 ; i< s.size(); i++)
        {
          if(s[i] != ' ')
          {
            if(w_start == -1) // a new word has been found
            {
                w_start = i;
            }
          } 
          else // we've got a ' '
          {
            if(w_start != -1) // a new word has been found
            {
                myStack.push(w_start);
                myStack.push(i-1);
                w_start = -1;
            }
          } 

        }
        if(w_start != -1)
        {
            myStack.push(w_start);
            myStack.push(s.size());
        }

        std::string result = "";
        result.reserve(s.size());
        while(!myStack.empty())
        {
            w_end = myStack.top();
            myStack.pop();
            w_start = myStack.top();
            myStack.pop();
            result += s.substr(w_start,w_end-w_start+1);
            if(myStack.empty() != true)
            {
                result += ' ';
            }
        }
        return result;
    }

    uint8_t countOnes( bool input)
    {
        static constexpr uint64_t sixtyBitsMask = 0x3FFFFFFFFFFFFFFF;
        static uint64_t ctr = 0;
        ctr <<= 1;
        ctr |= input & 0x01;
        ctr &= sixtyBitsMask;

        uint8_t result = 0;
        uint64_t tmpCtr = ctr;
        while(tmpCtr != 0)
        {
            tmpCtr &= (tmpCtr-1);
            result++;
        }
        return result;
    }

    int searchInsert(vector<int>& nums, int target) 
    {
        if(nums.size() == 0)
        {
            return 0;
        }

        size_t startIdx = 0;
        size_t endIdx = nums.size();
        size_t midIdx = (endIdx+startIdx)/2;
        
        while( true)
        {

            if(target == nums[startIdx])
            {
                return startIdx;
            }
            else if( target == nums[endIdx])
            {
                return endIdx;
            }
            else
            {
                if(nums[midIdx] > target)
                {
                    endIdx = midIdx;
                    midIdx = (endIdx+startIdx)/2;
                }
                else if(nums[midIdx] < target)
                {
                    startIdx = midIdx;
                    midIdx = (endIdx+startIdx)/2;
                }
            }
        }
        return midIdx;
    }

    #include <fstream>
    struct Person 
    {
        int age;
        float height;
    };

    {
        Person p1 = {25, 5.9f};

        std::ofstream ofile ("person.bin", std::ios::binary)

        if ( ofile.isOpen() == true)
        {
            ofile.write(reinterpret_cast<const char*>(&p1), sizeof(Person));
            ofile.close();
        }
        Person person{};
        std::ifstream ifile("person.bin", std::ios::binary)
        {
            if(ifile.isOpen() == true)
            {
                person = (Person)ifile.read(sizeof(Person));

                ifile.close();
            }
        }

        if((p1.age == person.age)&&(p1.height == person.height))
        {
            return true
        }

        return false;

    }



#include <unordered_map>
#include <vector>
#include <iostream>  // Instead of <stdio>

std::vector<int> twoSumUnique(std::vector<int>& vec, int target)
{
    std::unordered_map<int, int> map; // maps (target - val) -> index

    for (int i = 0; i < vec.size(); i++)
    {
        if (map.count(vec[i])) 
        {
            return {map[vec[i]],i};
        }
        else
        {
            map[target - vec[i]] = i;
        }
    }

    std::cout << "No pair has been found" << std::endl;
    return {};
}


#include <unordered_map>
#include <vector>
#include <iostream>

std::vector<std::pair<int, int>> twoSum(std::vector<int>& vec, int target)
{
    std::unordered_map<int, int> map; // val -> index
    std::vector<std::pair<int, int>> res;

    // No need to pre-fill map with vec[0]; just start from i = 0
    for (int i = 0; i < vec.size(); i++)
    {
        if (map.count(vec[i])) 
        {
            res.push_back({map[vec[i]],i});
        }
        else
        {
            map[target - vec[i]] = i;
        }
    }

    if (res.empty())
    {
        std::cout << "No pair has been found" << std::endl;
    }

    return res;
}


std::vector<int> twoSumUniqueOrdered(std::vector<int>& vec, int target)
{
    int left = 0, right = vec.size() - 1;
    while (left < right)
    {
        int sum = vec[left] + vec[right];
        if (sum == target)
            return {left, right};
        else if (sum < target)
            ++left;
        else
            --right;
    }

    std::cout << "No pair has been found" << std::endl;
    return {};
}

int missingNumber(std::vector<int>& nums) {
    int xorResult = nums.size();  // start with n
    for (int i = 0; i < nums.size(); ++i) {
        xorResult ^= i ^ nums[i];
    }
    return xorResult;
}


std::pair<int, int> findTwoMax(const std::vector<int>& vec)
{
    std::pair<int, int> res{INT32_MIN, INT32_MIN};

    if (vec.size() < 2)
        return res;

    for (auto& num : vec)
    {
        if (num > res.first)
        {
            res.second = res.first;
            res.first = num;
        }
        else if (num > res.second)
        {
            res.second = num;
        }
    }

    return res;
}




std::vector<std::vector<int>> threeSum(std::vector<int>& nums, int target)
{
    std::vector<std::vector<int>>  res;
    if(nums.size()<3)
    {
        return res;
    }

    std::sort(vec.begin(), vec.end());
    int i = 0;
    int j = 1;        
    int k = nums.size()-1;

    while((j!=i)&& (j!=k))
    {
        if(nums[i])
    }
}

#include <unordered_map>
int lengthOfLongestSubstring(const std::string& s) 
{
    std::unordered_map<char,int> map;

    int maxlen = 0;
    int left = 0;

    for(int right = 0; right<s.size(); right++)
    {
        char current = s[right];
        if(map.count(current) && (map[current] >= left))
        {
            left = map[current]+1;
        }

        charIndex[current] = right;

        maxlen = std::max(maxlen, right - left + 1);
    }
    return maxlen;
}


struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

#include <stack>
int kthSmallest(TreeNode* root, int k) 
{
    TreeNode* curr = root;
    std::stack<TreeNode*> stk

    while(curr || !stk.empty())
    {
        while (curr) 
        {
            stk.push(curr);
            curr = curr->left;
        }

        curr = stk.top();
        stk.pop();
        k--;
        if(k == 0)
        {
            return curr->val;
        }

        curr = curr->right;
    }

    return -1;
}


#include <stack>
int getMinimumDifference(TreeNode* root) 
{
    int minDiff = INT32_MAX;
    int tmpVal = INT32_MAX;
    std::stack<TreeNode*> stk;
    TreeNode* curr = root;
    stk.push(curr);

    while(curr || !stk.empty())
    {
        while(curr) // push all left nodes on the way...
        {
            stk.push(curr);
            curr = curr->left;
        }


    }



    return minDiff;
}




static constexpr size_t N = 10;
inline uint32_t coeff(size_t n)
{
    static const uint32_t factor_a[N] = 
    {
        1,          // 0!
        1,          // 1!
        2,          // 2!
        6,          // 3!
        24,         // 4!
        120,        // 5!
        720,        // 6!
        5040,       // 7!
        40320,      // 8!
        362880,     // 9!
    };

    if(n>=N)
    {
        return -1;
    }

    return factor_a[n];
}

double exp(double x)
{
    double result = 1.0;
    double tmpX = 1.0;
    for(size_t i{1}; i<N; i++)
    {
        tmpX *= x;
        result += tmpX/coeff(i);  
    }
    return result;
}

bool stream( bool n)
{
    static constexpr uint8_t ref = 0b101;
    static uint8_t val = 0;
    val <<=1; 
    val |= n; 
    val&=0x07;

    if(val == ref )
    {
        val = 0;
        return 1;
    }

    return 0;
}

};
};

int main(void)
{
    return 0;
}





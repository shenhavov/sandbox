
#include <algorithm>  // for min/max usage
namespace my_space
{
   int maxProfit(vector<int>& prices) 
   {
        if(prices.size() == 0)
        {
            return -1;
        }
        int min_price = prices[0];
        int max_profit = 0;

        for(const auto& price : prices)
        {
            min_price = std::min(price, min_price);
            max_profit = std::max(price - min_price, max_profit);
            
        }
        return maxProfit;
   }

   int maxProfit2(vector<int>& prices) 
   {
        if(prices.size() < 2)
        {
            return -1;
        }

        int min_price = prices[0];
        int curr_profit = 0;
        int max_profit = 0; // cummulative 

        for(int i = 1; i<prices.size(); i++)
        {
            if(prices[i] >= prices[i-1])
            {
                curr_profit = prices[i] - min_price;
            }   
            else
            {
                max_profit +=curr_profit;
                curr_profit = 0;
                min_price = prices[i];
            }         
        }
        max_profit +=curr_profit;
        return max_profit;
   }

    void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n)
    {

    }

    #include <unordered_map>
    int majorityElement(vector<int>& nums)  // hash map solution
    {
        std::unordered_map<int,int> map;
        int result = nums[0];
        int max_occurance = 0;

        for(const auto& num : nums)
        {
            if(map.count(num))
            {
                map[num]++;
                if(max_occurance < map[num])
                {
                    max_occurance = map[num];
                    result = num;
                    if(max_occurance >= ((nums.size()/2) +1))
                    {
                        break;
                    }
                }
            }
            else
            {
                map[num] = 1;
            }
        }
        return result;
    }

inline int getNewIdx(int newIdx, int k, int n)
    {
        return (newIdx+k)%n;
    }

    void rotate(vector<int>& nums, int k) // in place solution...
    {
        int currIdx = 0;
        int currVal = nums[0];
        int nextIdx = 0;
        int nextVal = 0;
        const int n = nums.size();
        for(int i = 0; i < n; i++)
        {
            nextIdx = getNewIdx(currIdx,k, n);
            nextVal = nums[nextIdx];
            
            nums[nextIdx] = currVal;

            currIdx = nextIdx;
            currVal = nextVal;
        }
    }

vector<string> summaryRanges(vector<int>& nums) 
    {
        vector<string> result;
        if(!nums.size())
        {
            return result;
        }
        
        int start = nums[0];
        int end = nums[0];
        int rangeIdx = 0;
        string tmp{};

        for( int i = 1; i<nums.size() ; i++)
        {
            if(nums[i] != end+1) // new range to be added
            {
                if(start != end)
                {
                    tmp = to_string(start) + "->" + to_string(end);
                }
                else
                {
                    tmp = to_string(start);
                }
                result.push_back(tmp);
                rangeIdx++;
                start = nums[i];
            }
            end = nums[i];
        }

        if(start != end)
        {
            tmp = to_string(start) + "->" + to_string(end);
        }
        else
        {
            tmp = to_string(start);
        }
        result.push_back(tmp);
        rangeIdx++;

        return result;
    }


    int maxArea(vector<int>& height) 
    {
        if(height.size()<2)
        {
            return 0;
        }

        int maxArea = 0;
        int left = 0;  
        int right = height.size()-1;

        while(left!=right)
        {
            maxArea = std::max(maxArea, std::min(height[left],height[right])*(right-left));
            if(height[left] < height[right])
            {
                left++;
            }
            else
            {
                right--;
            }
        }
        return maxArea; 

    }

    // BFS search: in this case the 'visited' data structure is embedded within the matrix itself
    #include <queue>
    #include <iostream>
    #include <vector>
    using vector = std::vector;
    using pair = std::pair;
    using Q = std::queue<pair<int, int>>;

    inline bool isLandPoint(vector<vector<bool>>& grid, const int i, const int j, const unsigned int n, const unsigned int m)
    {
        return (0 <= i && 0 <= j && i < n && j < m && grid[i][j]);
    }

    int numIslands(vector<vector<bool>>& grid)
    {
        const unsigned int n = grid.size();
        const unsigned int m = grid[0].size();
        unsigned int ctr = 0;

        Q q;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j])
                {
                    ctr++;
                    q.push({i, j});
                    while (!q.empty())
                    {
                        const auto p = q.front();
                        q.pop();
                        const auto x = p.first;
                        const auto y = p.second;

                        grid[x][y] = false;

                        if (isLandPoint(grid, x - 1, y, n, m)) q.push({x - 1, y});
                        if (isLandPoint(grid, x + 1, y, n, m)) q.push({x + 1, y});
                        if (isLandPoint(grid, x, y - 1, n, m)) q.push({x, y - 1});
                        if (isLandPoint(grid, x, y + 1, n, m)) q.push({x, y + 1});
                    }
                }
            }
        }

        return ctr;
    }

    inline bool isValidPoint(vector<vector<int>>& grid, const int i, const int j, const unsigned int n, const unsigned int m, const int refColor)
    {
        return (0 <= i && 0 <= j && i < n && j < m && (grid[i][j] == refColor));
    }

    #include <stack>
    #include <iostream>
    #include <vector>
    using stk = std::stack<pair<int, int>>;
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) 
    {
        vector<vector<int>> res{image};
        stk s;
        const unsigned int n = image.size();
        const unsigned int m = image[0].size();

        const int refColor = res[sr][sc];
        if(refColor == color)
        {
            return res;
        }

        s.push({sr,sc});

        while(!s.empty())
        {
            const auto p = s.top();
            s.pop();

            const auto x = p.first;
            const auto y = p.second;
            res[x][y] = color;

            if(isValidPoint(res, x-1, y, n, m, refColor))
            {
                s.push({x-1,y});
            }

            if(isValidPoint(res, x+1, y, n, m, refColor))
            {
                s.push({x+1,y});
            }

            if(isValidPoint(res, x, y-1, n, m, refColor))
            {
                s.push({x,y-1});
            }

            if(isValidPoint(res, x, y+1, n, m, refColor))
            {
                s.push({x,y+1});
            }
        }
        return res;
    }

    // search in a rotated array
    int search(vector<int>& nums, int target) 
    {
        if(nums.size()==1)
        {
            return (nums[0] == target) ? nums[0] : -1;
        }
        //first searching the rotation index (the minimal value)
        int l = 0;
        int u = nums.size() -1;
        int mid = l/2 + (u-l)/2;

        while(l<=u)
        {
            mid = l/2 + (u-l)/2;
            if(nums[mid] == target)
            {
                return mid;
            }
            if(nums[l]<=nums[mid]) // lower is sorted
            {
                if((target>=nums[l])&&(target<nums[mid])) // it's inside the sorted array
                {
                    u = mid-1;
                }
                else
                {
                    l = mid+1;
                }
            }
            else // upper is sorted
            {
                if((target>nums[mid])&&(target<=nums[u]))//target is inside sorted upper part
                {
                    l = mid+1;
                }
                else
                {
                    u = mid-1;
                }
            }

        } 
        return -1;
    }

}




#include <string>
#include <iostream>

namespace logging
{
    class Logger
    {
        public:
        static Logger& getLog()
        {
            static Logger _logger;
            return _logger;
        }

        void log( const std::string& a_rString)
        {
            std::cout <<"Logger: "<< a_rString << std::endl;
        }

        Logger( const Logger&) = delete;
        Logger& operator=(const Logger&) = delete;
        
        private:
        Logger() = default;
        ~Logger() = default;
    }
}

int main(void)
{
    return 0;
}





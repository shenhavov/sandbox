#include <string>
#include <iostream>
#include <fstream>
#include <memory> 

namespace logging
{


    class BaseLogger
    {
        public:
        BaseLogger();
        virtual ~BaseLogger() = default; 

        virtual void log( const std::string& ) = 0;
    }

    class ConsoleLogger : public BaseLogger
    {
        public:
        ConsoleLogger() = default;

        void log (const std::string& a_rInputStr ) override
        {
            std::cout << a_rInputStr << std::endl;
        }
    }

    class FileLogger : public BaseLogger
    {
        public:
        FileLogger()
        {
            std::ofstream logFile("app.log", std::ios::app);
            _logFile = std::move(logFile);
        }

        ~FileLogger()
        {
            _logFile.close();
        }

        void log (const std::string& a_rInputStr ) override
        {
            if (_logFile.is_open()) 
            {
                _logFile << a_rInputStr << std::endl;
            }
        }

        private:
        std::ofstream _logFile;
    }

    class LoggerFactory
    {
        public:
        static std::unique_ptr<BaseLogger> CreateLogger (const std::string& a_rLoggerName)
        {
            std::unique_ptr<BaseLogger> retPtr = nullptr;
            if(a_rLoggerName == "File")
            {
                rePtr = make_unique<FileLogger>();
            }
            else if (a_rLoggerName == "Console")
            {
                rePtr = make_uinque<ConsoleLogger>();
            }
            
            return rePtr;
        }
    }
}
    int main(void)
    {
        auto cnslLogger = LoggerFactory::CreateLogger("Console");
        auto fileLogger = LoggerFactory::CreateLogger("File");

        cnslLogger->log("Hello world console");
        fileLogger->log("Hola mundo file");

        return 0;
    }





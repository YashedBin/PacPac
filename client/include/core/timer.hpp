#pragma once
#include <chrono>
#include <iomanip>
#include <sstream>
#include <ctime>
#include <string>


namespace Core {

class Timer {
    private:
        std::chrono::time_point<std::chrono::high_resolution_clock> startTime, endTime;
        std::string workDone;
        bool emitJSON;

    public:
        Timer(std::string workDone, bool json = false)
            : workDone(workDone), emitJSON(json) {
            startTime = std::chrono::high_resolution_clock::now();
        }
    
        ~Timer() {
            endTime = std::chrono::high_resolution_clock::now();
            auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime);
            output(duration);
        }

        static std::string getFormattedTime() {
            auto now = std::chrono::system_clock::now();
            std::time_t time_t_now = std::chrono::system_clock::to_time_t(now);
            std::tm local_tm = *std::localtime(&time_t_now);
            std::ostringstream oss;
            oss << std::put_time(&local_tm, "%Y-%m-%d %H:%M:%S");
            return oss.str();
        }

        void output(std::chrono::milliseconds duration) {
            if(emitJSON) {
                std::cout << "{\"type\":\"timing\",\"work\":\"" << workDone 
                          << "\",\"duration_ms\":" << duration.count() << "}\n";
            }
            else {
                std::cout << workDone << "\nTime: "
                          << duration.count() << " ms\n";
            }
        }
    };

}

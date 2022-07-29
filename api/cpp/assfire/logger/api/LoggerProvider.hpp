#pragma once

#include "Logger.hpp"
#include "LoggerFactory.hpp"

#include <mutex>
#include <string>
#include <unordered_map>
#include <vector>

namespace assfire::logger {
    class LoggerProvider {
      public:
        static void register_factory(std::shared_ptr<LoggerFactory> factory);
        static std::shared_ptr<Logger> get(const std::string& name);

      private:
        static std::mutex mtx;
        static std::unordered_map<std::string, std::shared_ptr<Logger>> loggers;
        static std::vector<std::shared_ptr<LoggerFactory>> logger_factories;
    };
} // namespace assfire::logger
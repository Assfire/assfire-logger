#pragma once

#include "Logger.hpp"

#include <memory>
#include <string>

namespace assfire::logger {
    class LoggerFactory {
      public:
        virtual ~LoggerFactory()                                               = default;
        virtual std::shared_ptr<Logger> create_logger(const std::string& name) = 0;
    };
} // namespace assfire::logger
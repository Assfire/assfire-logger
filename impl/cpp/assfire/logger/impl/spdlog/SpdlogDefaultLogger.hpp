#pragma once

#include "assfire/logger/api/Logger.hpp"

namespace assfire::logger {
    class SpdlogDefaultLogger : public Logger {
      public:
        SpdlogDefaultLogger() {}
        SpdlogDefaultLogger(LogLevel log_level) : Logger(log_level) {}

        virtual void log_impl(LogLevel level, LogStringView message) const override;
    };
} // namespace assfire::logger
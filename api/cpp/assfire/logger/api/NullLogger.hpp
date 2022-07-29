#pragma once

#include "Logger.hpp"

namespace assfire::logger {
    class NullLogger : public Logger {
      public:
        NullLogger() : Logger(LogLevel::LOG_LEVEL_OFF) {}

      private:
        virtual void log_impl(LogLevel level, LogStringView message) const override {
            // NOP
        };
    };
} // namespace assfire::logger
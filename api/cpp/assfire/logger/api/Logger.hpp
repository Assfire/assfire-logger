#pragma once

#include "LogLevel.hpp"

#include <atomic>
#include <fmt/format.h>
#include <string>

namespace assfire::logger {
    class Logger {
      public:
        virtual ~Logger() = default;

        Logger() : current_level(LogLevel::LOG_LEVEL_INFO) {}
        Logger(LogLevel level) : current_level(level) {}

        template<typename... Args>
        using FormatString = fmt::format_string<Args...>;

        template<typename... Args>
        void trace(FormatString<Args...> fmt, Args&&... args) const {
            log(LogLevel::LOG_LEVEL_TRACE, fmt, std::forward<Args>(args)...);
        }

        template<typename... Args>
        void debug(FormatString<Args...> fmt, Args&&... args) const {
            log(LogLevel::LOG_LEVEL_DEBUG, fmt, std::forward<Args>(args)...);
        }

        template<typename... Args>
        void info(FormatString<Args...> fmt, Args&&... args) const {
            log(LogLevel::LOG_LEVEL_INFO, fmt, std::forward<Args>(args)...);
        }

        template<typename... Args>
        void warn(FormatString<Args...> fmt, Args&&... args) const {
            log(LogLevel::LOG_LEVEL_WARN, fmt, std::forward<Args>(args)...);
        }

        template<typename... Args>
        void error(FormatString<Args...> fmt, Args&&... args) const {
            log(LogLevel::LOG_LEVEL_ERROR, fmt, std::forward<Args>(args)...);
        }

        template<typename... Args>
        void critical(FormatString<Args...> fmt, Args&&... args) const {
            log(LogLevel::LOG_LEVEL_CRITICAL, fmt, std::forward<Args>(args)...);
        }

        void set_level(LogLevel level) {
            current_level = level;
        }

      protected:
        using LogStringView = fmt::basic_string_view<char>;

      private:
        bool level_enabled(LogLevel level) const {
            return current_level <= level;
        }

        template<typename... Args>
        void log(LogLevel level, FormatString<Args...> fmt, Args&&... args) const {
            if (!level_enabled(level)) { return; }

            auto buf = fmt::memory_buffer();
            fmt::format_to(std::back_inserter(buf), fmt, std::forward<Args>(args)...);

            log_impl(level, LogStringView(buf.data(), buf.size()));
        }

        virtual void log_impl(LogLevel level, LogStringView message) const = 0;

        std::atomic<LogLevel> current_level;
    };
} // namespace assfire::logger
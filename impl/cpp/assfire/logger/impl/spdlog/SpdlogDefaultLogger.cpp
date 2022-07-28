#include "SpdlogDefaultLogger.hpp"

#include <spdlog/spdlog.h>

namespace assfire::logger {

    namespace {
        spdlog::level::level_enum to_spdlog_level(LogLevel level) {
            switch (level) {
            case LogLevel::LOG_LEVEL_TRACE: return spdlog::level::trace;
            case LogLevel::LOG_LEVEL_DEBUG: return spdlog::level::debug;
            case LogLevel::LOG_LEVEL_INFO: return spdlog::level::info;
            case LogLevel::LOG_LEVEL_WARN: return spdlog::level::warn;
            case LogLevel::LOG_LEVEL_ERROR: return spdlog::level::err;
            case LogLevel::LOG_LEVEL_CRITICAL: return spdlog::level::critical;
            default: throw std::invalid_argument("Unexpected log level");
            }
        }
    } // namespace

    void SpdlogDefaultLogger::log_impl(LogLevel level, LogStringView msg) const {
        spdlog::log(to_spdlog_level(level), msg);
    }

} // namespace assfire::logger
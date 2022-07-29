#pragma once

#include "assfire/logger/api/LoggerFactory.hpp"

namespace assfire::logger {
    class SpdlogLoggerFactory : public LoggerFactory {
      public:
        virtual std::shared_ptr<Logger> create_logger(const std::string& name) override;

        static void register_static_factory();
    };
} // namespace assfire::logger
#include "SpdlogLoggerFactory.hpp"

#include "SpdlogDefaultLogger.hpp"
#include "assfire/logger/api/LoggerProvider.hpp"

namespace assfire::logger {

    std::shared_ptr<Logger> SpdlogLoggerFactory::create_logger(const std::string& name) {
        return std::make_shared<SpdlogDefaultLogger>();
    }

    void SpdlogLoggerFactory::register_static_factory() {
        LoggerProvider::register_factory(std::make_shared<SpdlogLoggerFactory>());
    }

} // namespace assfire::logger
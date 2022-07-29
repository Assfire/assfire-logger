#include "LoggerProvider.hpp"

namespace assfire::logger {

    std::mutex LoggerProvider::mtx;
    std::unordered_map<std::string, std::shared_ptr<Logger>> LoggerProvider::loggers;
    std::vector<std::shared_ptr<LoggerFactory>> LoggerProvider::logger_factories;

    void LoggerProvider::register_factory(std::shared_ptr<LoggerFactory> factory) {
        std::lock_guard<std::mutex> lck(mtx);
        logger_factories.push_back(factory);
    }

    std::shared_ptr<Logger> LoggerProvider::get(const std::string& name) {
        std::lock_guard<std::mutex> lck(mtx);
        auto iter = loggers.find(name);
        if (iter == loggers.end()) {
            for (auto factory : logger_factories) {
                std::shared_ptr<Logger> instance = factory->create_logger(name);
                if (instance) {
                    loggers.emplace(name, instance);
                    return instance;
                }
            }
        }
        return iter->second;
    }

} // namespace assfire::logger

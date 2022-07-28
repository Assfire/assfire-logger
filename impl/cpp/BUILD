cc_library(
    name = "assfire_logger_cc_impl_spdlog",
    srcs = ["assfire/logger/impl/spdlog/SpdlogDefaultLogger.cpp"],
    hdrs = ["assfire/logger/impl/spdlog/SpdlogDefaultLogger.hpp"],
    include_prefix = "assfire/logger/impl/spdlog",
    strip_include_prefix = "assfire/logger/impl/spdlog",
    visibility = ["//visibility:public"],
    deps = [
        "//api/cpp:assfire_logger_cc_api",
        "@com_github_spdlog_spdlog//:spdlog",
    ],
)

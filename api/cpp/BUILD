cc_library(
    name = "assfire_logger_cc_api",
    srcs = [
        "assfire/logger/api/Logger.cpp",
        "assfire/logger/api/LoggerProvider.cpp",
    ],
    hdrs = [
        "assfire/logger/api/LogLevel.hpp",
        "assfire/logger/api/Logger.hpp",
        "assfire/logger/api/LoggerFactory.hpp",
        "assfire/logger/api/LoggerProvider.hpp",
    ],
    include_prefix = "assfire/logger/api",
    strip_include_prefix = "assfire/logger/api",
    visibility = ["//visibility:public"],
    deps = ["@com_github_fmtlib_fmt//:fmtlib"],
)

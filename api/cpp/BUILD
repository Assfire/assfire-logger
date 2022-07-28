cc_library(
    name = "assfire_logger_cc_api",
    srcs = ["assfire/logger/api/Logger.cpp"],
    hdrs = [
        "assfire/logger/api/LogLevel.hpp",
        "assfire/logger/api/Logger.hpp",
    ],
    visibility = ["//visibility:public"],
    strip_include_prefix = "assfire/logger/api",
    include_prefix = "assfire/logger/api",
    deps = ["@com_github_fmtlib_fmt//:fmtlib"],
)

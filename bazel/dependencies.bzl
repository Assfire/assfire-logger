load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

def assfire_logger_dependencies_spdlog():
    http_archive(
        name = "com_github_fmtlib_fmt",
        urls = ["https://github.com/fmtlib/fmt/releases/download/9.0.0/fmt-9.0.0.zip"],
        sha256 = "fc96dd2d2fdf2bded630787adba892c23cb9e35c6fd3273c136b0c57d4651ad6",
        strip_prefix = "fmt-9.0.0",
        build_file = "@//third_party:fmtlib.BUILD",
        
    )

    http_archive(
        name = "com_github_spdlog_spdlog",
        urls = ["https://github.com/gabime/spdlog/archive/refs/tags/v1.10.0.zip"],
        strip_prefix = "spdlog-1.10.0",
        build_file = "@//third_party:spdlog.BUILD",
    )

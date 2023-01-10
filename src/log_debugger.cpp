#include "log_debugger.h"
#include "log_debugger_db.h"
#include <stdarg.h>
#include <vector>
#include <string>

std::string&& time_stamp()
{
    return std::string("");
}

std::string&& make_prefix(const char* file, const char* line)
{
    LD_LOG_PREFIX prefix;
    prefix.code_path;
    file;
    line;
    prefix.time_stamp;
    time_stamp();
#ifdef LD_ENABLE_SOURCE_CONTROL
    prefix.source_ver;
#endif
#ifdef LD_ENABLE_PROCESS_CONTROL
    prefix.pid;
#ifdef LD_ENABLE_THREAD_CONTROL
    prefix.tid;
#endif
#endif
    return std::string("");
}

bool extract_prefix_string(const char* content, std::string& prefix_str)
{
    return false;
}

std::string&& make_log_content(std::vector<std::string> args)
{

}

void ld_write_log(const char* file, const char* line, const char* fmt, ...)
{
    va_list args;
    va_start(args, fmt);

    std::vector<std::string> vArgs;
    //
    vArgs.push_back(make_prefix(file, line));
    vArgs.push_back(line);

    const char* current = fmt;
    while (*current)
    {
        vArgs.push_back(current);

        current = va_arg(args, const char*);
    }
    va_end(args);

    write_db();
    make_log_content(vArgs);
}

bool log_location(const char* content, LD_LOG_PREFIX& prefix)
{
    std::string prefix_str;
    if (!extract_prefix_string(content, prefix_str))
        return false;

    prefix;
    prefix_str;

    return true;
}

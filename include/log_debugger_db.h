#ifndef LOG_DEBUGGER_DB_H
#define LOG_DEBUGGER_DB_H

#include "logDebugger_common.h"
#include <vector>

typedef struct _log_debugger_db
{
    char code_position_hash[2];
    char code_path[16];
    char code_ver[16];
}LOG_DB;


std::vector<char*> code_positions;

#ifdef LD_ENABLE_SOURCE_CONTROL
bool write_db(const char* log_path, const char* log_version);
#else
bool write_db(const char* log_path);
#endif
bool read_db(LD_LOG_PREFIX* prefix);

#endif
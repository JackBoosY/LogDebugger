#ifndef LOG_DEBBGER_H
#define LOG_DEBBGER_H

#include "logDebugger_common.h"

#define LD_LOGGER(x) ld_write_log(LD_CURRENT_FILE, LD_CURRENT_LINE, x, "")

/*
* Intro: write one log line
* Return: null
* file: current code file
* line: current code line
* ...: log content
*/
void ld_write_log(const char* file, const char* line, const char* fmt, ...);

/*
* Intro: get current log related code location
* Return value: bool
* content: current log line
* prefix: log related code info
*/
bool log_location(const char* content, LD_LOG_PREFIX& prefix);

#endif
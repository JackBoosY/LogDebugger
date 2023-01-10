#ifndef LOG_DEBUGGER_COMMON_H
#define LOG_DEBUGGER_COMMON_H

#define LD_CURRENT_FILE __FILE__
#define LD_CURRENT_LINE __LINE__

#define TIME_STAMP_LEN 8
#define CODE_PATH_LEN 16
#define SOURCE_VER_LEN 16
#define PID_LEN 8
#define TID_LEN 8

typedef struct _ld_log_prefix
{
    char time_stamp[TIME_STAMP_LEN]; // hex time stamp
    char code_path[CODE_PATH_LEN]; // include source file relative path and code line number
#ifdef LD_ENABLE_SOURCE_CONTROL
    char source_ver[SOURCE_VER_LEN]; // source control version
#endif
#ifdef LD_ENABLE_PROCESS_CONTROL
    char pid[PID_LEN]; // process id
#ifdef LD_ENABLE_THREAD_CONTROL
    char tid[TID_LEN]; // thread id
#endif
#endif
}LD_LOG_PREFIX;

#endif

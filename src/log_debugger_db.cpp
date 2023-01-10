#include "log_debugger_db.h"
#include <algorithm>

bool db_is_create = false;

#ifdef LD_ENABLE_SOURCE_CONTROL
void make_position_hash(const char* log_path, const char* log_version, char*& hash)
#else
void make_position_hash(const char* log_path, char*& hash)
#endif
{

}

bool create_db_file()
{
    db_is_create = true;
}


bool write_to_file(LOG_DB& info)
{
    if (!db_is_create)
        create_db_file();


    return true;
}

#ifdef LD_ENABLE_SOURCE_CONTROL
bool write_db(const char* log_path, const char* log_version)
#else
bool write_db(const char* log_path)
#endif
{
    LOG_DB db_info;
    char current_position[2] = { 0 };
#ifdef LD_ENABLE_SOURCE_CONTROL
    make_position_hash(log_path, log_version, (char*&)current_position);
#else
    make_position_hash(log_path, (char*&)current_position);
#endif

    if (std::find(code_positions.begin(), code_positions.end(), current_position))
    {
        return write_to_file(db_info);
    }

    return true;
}

bool read_db(LD_LOG_PREFIX* prefix)
{
    return true;
}
#ifndef LIBRETRODEBUG_H__
#define LIBRETRODEBUG_H__

enum retro_log_level
{
   RETRO_LOG_DEBUG = 0,
   RETRO_LOG_INFO,
   RETRO_LOG_WARN,
   RETRO_LOG_ERROR,

   RETRO_LOG_DUMMY = INT_MAX
};

/* Logging function. Takes log level argument as well. */
typedef void (*retro_log_printf_t)(enum retro_log_level level,
      const char *fmt, ...);

extern retro_log_printf_t log_cb;

#undef puts
#define puts(...) log_cb(RETRO_LOG_INFO, __VA_ARGS__)

#undef printf
#define printf(...) log_cb(RETRO_LOG_INFO, __VA_ARGS__)

#endif

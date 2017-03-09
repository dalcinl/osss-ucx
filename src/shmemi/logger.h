#ifndef _SHMEMI_LOGGER_H
#define _SHMEMI_LOGGER_H 1

#define SHMEMI_BIT_SET(n) (1 << (n))

typedef enum shmem_log {
    LOG_FATAL = SHMEMI_BIT_SET(1),
    LOG_INIT = SHMEMI_BIT_SET(2),
    LOG_FINALIZE = SHMEMI_BIT_SET(3),
    LOG_MEMORY = SHMEMI_BIT_SET(4),
    LOG_ALL = LOG_FATAL | LOG_INIT | LOG_FINALIZE | LOG_MEMORY
} shmem_log_t;

void logger(shmem_log_t level, const char *fmt, ...);

#endif /* ! _SHMEMI_LOGGER_H */
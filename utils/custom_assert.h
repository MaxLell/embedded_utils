/**
 * \file            custom_assert.h
 * \brief           Custom assertion macros for embedded systems
 */

#ifndef CUSTOM_ASSERT_HDR_H
#define CUSTOM_ASSERT_HDR_H

#include <stdint.h>

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

    typedef void (*custom_assert_callback_fn)(const char* file, uint32_t line, const char* expr);

    void custom_assert_failed(const char* file, uint32_t line, const char* expr);
    void custom_assert_register(custom_assert_callback_fn callback);
    void custom_assert_unregister(void);

#ifndef NDEBUG
#define ASSERT(expr)                                                                                                   \
    do                                                                                                                 \
    {                                                                                                                  \
        if (!(expr))                                                                                                   \
        {                                                                                                              \
            custom_assert_failed(__FILE__, __LINE__, #expr);                                                           \
        }                                                                                                              \
    } while (0)
#else
#define ASSERT(expr) ((void)0)
#endif /* NDEBUG */

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* CUSTOM_ASSERT_HDR_H */

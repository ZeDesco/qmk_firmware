#pragma once

#if defined(__AVR__)
#   include <avr/pgmspace.h>
#else
<<<<<<< HEAD
#   define PROGMEM
#   define pgm_read_byte(p)     *((unsigned char*)(p))
#   define pgm_read_word(p)     *((uint16_t*)(p))
#   define pgm_read_dword(p)    *((uint32_t*)(p))
#endif

=======
#    define PROGMEM
#    define memcpy_P(dest, src, n) memcpy(dest, src, n)
#    define pgm_read_byte(address_short) *((uint8_t*)(address_short))
#    define pgm_read_word(address_short) *((uint16_t*)(address_short))
#    define pgm_read_dword(address_short) *((uint32_t*)(address_short))
#    define pgm_read_ptr(address_short) *((void**)(address_short))
#    define strcmp_P(s1, s2) strcmp(s1, s2)
#    define strcpy_P(dest, src) strcpy(dest, src)
#    define strlen_P(src) strlen(src)
>>>>>>> upstream/master
#endif

/**
 * MaNGOS is a full featured server for World of Warcraft, supporting
 * the following clients: 1.12.x, 2.4.3, 3.3.5a, 4.3.4a and 5.4.8
 *
 * Copyright (C) 2005-2019  MaNGOS project <https://getmangos.eu>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 * World of Warcraft, and all World of Warcraft or Warcraft art, images,
 * and lore are copyrighted by Blizzard Entertainment, Inc.
 */

#ifndef MANGOS_COMMON_H
#define MANGOS_COMMON_H

#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <string>
#include <list>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>

#include "ace/Basic_Types.h"

#define PLATFORM_WINDOWS 0
#define PLATFORM_OTHER   1

#define COMPILER_MICROSOFT  0
#define COMPILER_GNU        1
#define COMPILER_BORLAND    2
#define COMPILER_INTEL      3
#define COMPILER_CLANG      4

#define MANGOS_LITTLEENDIAN 0
#define MANGOS_BIGENDIAN    1


// must be first (win 64 also define WIN32)
#if defined( _WIN64 ) || defined( __WIN32__ ) || defined( WIN32 ) || defined( _WIN32 )
#  define PLATFORM PLATFORM_WINDOWS
#else
#  define PLATFORM PLATFORM_OTHER
#endif

#ifdef _MSC_VER
#  define COMPILER COMPILER_MICROSOFT
#elif defined( __BORLANDC__ )
#  define COMPILER COMPILER_BORLAND
#elif defined( __INTEL_COMPILER )
#  define COMPILER COMPILER_INTEL
#elif defined(__clang__)
#  define COMPILER COMPILER_CLANG
#elif defined( __GNUC__ ) && !defined(__clang__)
#  define COMPILER COMPILER_GNU
#else
#  pragma error "FATAL ERROR: Unknown compiler."
#endif

#if COMPILER == COMPILER_GNU || COMPILER == COMPILER_CLANG
#  define ATTR_NORETURN     __attribute__((noreturn))
#  define ATTR_PRINTF(F, V) __attribute__ ((format (printf, F, V)))
#  define ATTR_DEPRECATED   __attribute__((deprecated))
#else
#  define ATTR_NORETURN
#  define ATTR_PRINTF(F, V)
#  define ATTR_DEPRECATED
#endif

#ifndef DECLSPEC_NORETURN
#if COMPILER == COMPILER_MICROSOFT
#  define DECLSPEC_NORETURN __declspec(noreturn)
#else
#  define DECLSPEC_NORETURN
#endif
#endif

#define MANGOS_PATH_MAX FILENAME_MAX                            // ace/os_include/os_limits.h -> ace/Basic_Types.h


typedef ACE_INT64  int64;
typedef ACE_INT32  int32;
typedef ACE_INT16  int16;
typedef ACE_INT8   int8;
typedef ACE_UINT64 uint64;
typedef ACE_UINT32 uint32;
typedef ACE_UINT16 uint16;
typedef ACE_UINT8  uint8;

#if COMPILER != COMPILER_MICROSOFT
typedef uint16      WORD;
typedef uint32      DWORD;
#endif // COMPILER

typedef uint64 OBJECT_HANDLE;

#define I32FMTD     ACE_INT32_FORMAT_SPECIFIER
#define I64FMTD     ACE_INT64_FORMAT_SPECIFIER
#define UI64FMTD    ACE_UINT64_FORMAT_SPECIFIER
#define SIZEFMTD    ACE_SIZE_T_FORMAT_SPECIFIER
#define UI64LIT(N)  ACE_UINT64_LITERAL(N)
#define SI64LIT(N)  ACE_INT64_LITERAL(N)
#define STRINGIZE(a) #a

#if PLATFORM == PLATFORM_WINDOWS
  #define snprintf _snprintf
  #define vsnprintf _vsnprintf
#else
  #define stricmp  strcasecmp
  #define strnicmp strncasecmp
#endif

inline float finiteAlways(float f) { return std::isfinite(f) ? f : 0.0f; }

// used for creating values for respawn for example
#define MAKE_PAIR64(l, h)  uint64( uint32(l) | ( uint64(h) << 32 ) )
#define PAIR64_HIPART(x)   (uint32)((uint64(x) >> 32) & UI64LIT(0x00000000FFFFFFFF))
#define PAIR64_LOPART(x)   (uint32)(uint64(x)         & UI64LIT(0x00000000FFFFFFFF))

#define MAKE_PAIR32(l, h)  uint32( uint16(l) | ( uint32(h) << 16 ) )
#define PAIR32_HIPART(x)   (uint16)((uint32(x) >> 16) & 0x0000FFFF)
#define PAIR32_LOPART(x)   (uint16)(uint32(x)         & 0x0000FFFF)

#ifndef M_PI
#  define M_PI          3.14159265358979323846
#endif

#ifndef M_PI_F
#  define M_PI_F        float(M_PI)
#endif

#ifndef countof
#define countof(array) (sizeof(array) / sizeof((array)[0]))
#endif

inline char* mangos_strdup(const char* source)
{
    char* dest = new char[strlen(source) + 1];
    strcpy(dest, source);
    return dest;
}

#endif

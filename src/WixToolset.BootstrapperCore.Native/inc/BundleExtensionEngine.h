#pragma once
// Copyright (c) .NET Foundation and contributors. All rights reserved. Licensed under the Microsoft Reciprocal License. See LICENSE.TXT file in the project root for full license information.


#if defined(__cplusplus)
extern "C" {
#endif

enum BUNDLE_EXTENSION_LOG_LEVEL
{
    BUNDLE_EXTENSION_LOG_LEVEL_NONE,      // turns off report (only valid for XXXSetLevel())
    BUNDLE_EXTENSION_LOG_LEVEL_STANDARD,  // written if reporting is on
    BUNDLE_EXTENSION_LOG_LEVEL_VERBOSE,   // written only if verbose reporting is on
    BUNDLE_EXTENSION_LOG_LEVEL_DEBUG,     // reporting useful when debugging code
    BUNDLE_EXTENSION_LOG_LEVEL_ERROR,     // always gets reported, but can never be specified
};

enum BUNDLE_EXTENSION_ENGINE_MESSAGE
{
    BUNDLE_EXTENSION_ENGINE_MESSAGE_ESCAPESTRING,
    BUNDLE_EXTENSION_ENGINE_MESSAGE_EVALUATECONDITION,
    BUNDLE_EXTENSION_ENGINE_MESSAGE_FORMATSTRING,
    BUNDLE_EXTENSION_ENGINE_MESSAGE_GETVARIABLENUMERIC,
    BUNDLE_EXTENSION_ENGINE_MESSAGE_GETVARIABLESTRING,
    BUNDLE_EXTENSION_ENGINE_MESSAGE_GETVARIABLEVERSION,
    BUNDLE_EXTENSION_ENGINE_MESSAGE_LOG,
    BUNDLE_EXTENSION_ENGINE_MESSAGE_SETVARIABLENUMERIC,
    BUNDLE_EXTENSION_ENGINE_MESSAGE_SETVARIABLESTRING,
    BUNDLE_EXTENSION_ENGINE_MESSAGE_SETVARIABLEVERSION,
    BUNDLE_EXTENSION_ENGINE_MESSAGE_COMPAREVERSIONS,
};

typedef struct _BUNDLE_EXTENSION_ENGINE_COMPAREVERSIONS_ARGS
{
    DWORD cbSize;
    LPCWSTR wzVersion1;
    LPCWSTR wzVersion2;
} BUNDLE_EXTENSION_ENGINE_COMPAREVERSIONS_ARGS;

typedef struct _BUNDLE_EXTENSION_ENGINE_COMPAREVERSIONS_RESULTS
{
    DWORD cbSize;
    int nResult;
} BUNDLE_EXTENSION_ENGINE_COMPAREVERSIONS_RESULTS;

typedef struct _BUNDLE_EXTENSION_ENGINE_ESCAPESTRING_ARGS
{
    DWORD cbSize;
    LPCWSTR wzIn;
} BUNDLE_EXTENSION_ENGINE_ESCAPESTRING_ARGS;

typedef struct _BUNDLE_EXTENSION_ENGINE_ESCAPESTRING_RESULTS
{
    DWORD cbSize;
    LPWSTR wzOut;
    // Should be initialized to the size of wzOut.
    DWORD cchOut;
} BUNDLE_EXTENSION_ENGINE_ESCAPESTRING_RESULTS;

typedef struct _BUNDLE_EXTENSION_ENGINE_EVALUATECONDITION_ARGS
{
    DWORD cbSize;
    LPCWSTR wzCondition;
} BUNDLE_EXTENSION_ENGINE_EVALUATECONDITION_ARGS;

typedef struct _BUNDLE_EXTENSION_ENGINE_EVALUATECONDITION_RESULTS
{
    DWORD cbSize;
    BOOL f;
} BUNDLE_EXTENSION_ENGINE_EVALUATECONDITION_RESULTS;

typedef struct _BUNDLE_EXTENSION_ENGINE_FORMATSTRING_ARGS
{
    DWORD cbSize;
    LPCWSTR wzIn;
} BUNDLE_EXTENSION_ENGINE_FORMATSTRING_ARGS;

typedef struct _BUNDLE_EXTENSION_ENGINE_FORMATSTRING_RESULTS
{
    DWORD cbSize;
    // The contents of wzOut may be sensitive, should keep encrypted and SecureZeroFree.
    LPWSTR wzOut;
    // Should be initialized to the size of wzOut.
    DWORD cchOut;
} BUNDLE_EXTENSION_ENGINE_FORMATSTRING_RESULTS;

typedef struct _BUNDLE_EXTENSION_ENGINE_GETVARIABLENUMERIC_ARGS
{
    DWORD cbSize;
    LPCWSTR wzVariable;
} BUNDLE_EXTENSION_ENGINE_GETVARIABLENUMERIC_ARGS;

typedef struct _BUNDLE_EXTENSION_ENGINE_GETVARIABLENUMERIC_RESULTS
{
    DWORD cbSize;
    // The contents of llValue may be sensitive, if variable is hidden should keep value encrypted and SecureZeroMemory.
    LONGLONG llValue;
} BUNDLE_EXTENSION_ENGINE_GETVARIABLENUMERIC_RESULTS;

typedef struct _BUNDLE_EXTENSION_ENGINE_GETVARIABLESTRING_ARGS
{
    DWORD cbSize;
    LPCWSTR wzVariable;
} BUNDLE_EXTENSION_ENGINE_GETVARIABLESTRING_ARGS;

typedef struct _BUNDLE_EXTENSION_ENGINE_GETVARIABLESTRING_RESULTS
{
    DWORD cbSize;
    // The contents of wzValue may be sensitive, if variable is hidden should keep value encrypted and SecureZeroFree.
    LPWSTR wzValue;
    // Should be initialized to the size of wzValue.
    DWORD cchValue;
} BUNDLE_EXTENSION_ENGINE_GETVARIABLESTRING_RESULTS;

typedef struct _BUNDLE_EXTENSION_ENGINE_GETVARIABLEVERSION_ARGS
{
    DWORD cbSize;
    LPCWSTR wzVariable;
} BUNDLE_EXTENSION_ENGINE_GETVARIABLEVERSION_ARGS;

typedef struct _BUNDLE_EXTENSION_ENGINE_GETVARIABLEVERSION_RESULTS
{
    DWORD cbSize;
    // The contents of wzValue may be sensitive, if variable is hidden should keep value encrypted and SecureZeroFree.
    LPWSTR wzValue;
    // Should be initialized to the size of wzValue.
    DWORD cchValue;
} BUNDLE_EXTENSION_ENGINE_GETVARIABLEVERSION_RESULTS;

typedef struct _BUNDLE_EXTENSION_ENGINE_LOG_ARGS
{
    DWORD cbSize;
    BUNDLE_EXTENSION_LOG_LEVEL level;
    LPCWSTR wzMessage;
} BUNDLE_EXTENSION_ENGINE_LOG_ARGS;

typedef struct _BUNDLE_EXTENSION_ENGINE_LOG_RESULTS
{
    DWORD cbSize;
} BUNDLE_EXTENSION_ENGINE_LOG_RESULTS;

typedef struct _BUNDLE_EXTENSION_ENGINE_SETVARIABLENUMERIC_ARGS
{
    DWORD cbSize;
    LPCWSTR wzVariable;
    LONGLONG llValue;
} BUNDLE_EXTENSION_ENGINE_SETVARIABLENUMERIC_ARGS;

typedef struct _BUNDLE_EXTENSION_ENGINE_SETVARIABLENUMERIC_RESULTS
{
    DWORD cbSize;
} BUNDLE_EXTENSION_ENGINE_SETVARIABLENUMERIC_RESULTS;

typedef struct _BUNDLE_EXTENSION_ENGINE_SETVARIABLESTRING_ARGS
{
    DWORD cbSize;
    LPCWSTR wzVariable;
    LPCWSTR wzValue;
    BOOL fFormatted;
} BUNDLE_EXTENSION_ENGINE_SETVARIABLESTRING_ARGS;

typedef struct _BUNDLE_EXTENSION_ENGINE_SETVARIABLESTRING_RESULTS
{
    DWORD cbSize;
} BUNDLE_EXTENSION_ENGINE_SETVARIABLESTRING_RESULTS;

typedef struct _BUNDLE_EXTENSION_ENGINE_SETVARIABLEVERSION_ARGS
{
    DWORD cbSize;
    LPCWSTR wzVariable;
    LPCWSTR wzValue;
} BUNDLE_EXTENSION_ENGINE_SETVARIABLEVERSION_ARGS;

typedef struct _BUNDLE_EXTENSION_ENGINE_SETVARIABLEVERSION_RESULTS
{
    DWORD cbSize;
} BUNDLE_EXTENSION_ENGINE_SETVARIABLEVERSION_RESULTS;

extern "C" typedef HRESULT(WINAPI *PFN_BUNDLE_EXTENSION_ENGINE_PROC)(
    __in BUNDLE_EXTENSION_ENGINE_MESSAGE message,
    __in const LPVOID pvArgs,
    __inout LPVOID pvResults,
    __in_opt LPVOID pvContext
    );

#if defined(__cplusplus)
}
#endif

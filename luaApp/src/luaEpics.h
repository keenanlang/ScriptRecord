#ifndef INC_LUAEPICS_H
#define INC_LUAEPICS_H

#include <shareLib.h>

#ifdef __cplusplus
extern "C"
{
#endif
	
	#include "lua.h"
	#include "lualib.h"
	#include "lauxlib.h"
	
	
#ifdef __cplusplus
}

#include <string>

epicsShareFunc std::string luaLocateFile(std::string filename);
#endif

epicsShareFunc int luaLoadScript(lua_State* state, const char* script_file);
epicsShareFunc int luaLoadString(lua_State* state, const char* lua_code);
epicsShareFunc int  luaLoadParams(lua_State* state, const char* param_list);
epicsShareFunc void luaLoadMacros(lua_State* state, const char* macro_list);

epicsShareFunc void luaRegisterLibrary(const char* library_name, lua_CFunction load_func);
epicsShareFunc void luaLoadRegisteredLibraries(lua_State* state);
#endif

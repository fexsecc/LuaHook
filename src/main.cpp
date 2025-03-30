#include <stdio.h>
#include <stdlib.h>
extern "C" {
    #include <lauxlib.h>
    #include <lua.h>
    #include <lualib.h>
}
#include <readline/readline.h> // autocompletion
#include <readline/history.h>  // cmd history

int main (int argc, char *argv[]) {
    using_history();

    char *line;
    int error;
    lua_State *L = luaL_newstate(); // opens lua
    luaL_openlibs(L); // opens std libraries

    while((line = readline("> ")) != NULL) {
        add_history(line);
        error = luaL_loadstring(L, line) || lua_pcall(L, 0, 0, 0);
        if (error) {
            fprintf(stderr, "%s\n", lua_tostring(L, -1));
            lua_pop(L, 1); // pop error message from stack
        }
        free(line);
    }
    clear_history();

    lua_close(L);
    return 0;
}

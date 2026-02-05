-- xmake 3.0.6

set_project("D2MySTL")
set_version("0.1.0")
set_languages("c++23")

add_includedirs(".")
add_plugindirs("d2x/buildtools")

if is_mode("debug") then
    -- xmake f -m debug
    includes("src/xmake.lua")
else
    -- xmake f -m release
    includes("mystl/xmake.lua")
end

includes("tests/xmake.lua")
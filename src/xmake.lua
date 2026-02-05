set_languages("c++23")
add_requires("gtest")

includes("chapter0/xmake.lua")
includes("chapter1/xmake.lua")

target("mystl_tests")
    set_kind("binary")
    add_files("../tests/*.cpp")
    add_deps("chapter0_modules", "chapter1_modules")
    add_packages("gtest")
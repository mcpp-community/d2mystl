add_includedirs(".")

set_project("D2MySTL")
set_version("0.1.0")
set_languages("c++23")

set_policy("build.c++.modules", true)

includes("src/xmake.lua")
includes("tests/xmake.lua")

add_requires("gtest")

target("mystl_tests")
    set_kind("binary")
    add_files("tests/*.cpp")
    add_deps("chapter0_modules", "chapter1_modules")
    add_packages("gtest")
    add_includedirs(".")
    set_values("c++.module.outputdir", "$(buildir)/modules")
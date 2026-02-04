-- Chapter 1: Student implementation build config
target("chapter1_tests")
    set_kind("static")
    set_languages("c++23")
    add_files("global.cppm", "metaInfo/metaInfo.cppm", "array/array.cppm")
    set_values("c++.module.outputdir", "$(builddir)/modules")

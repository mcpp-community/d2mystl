-- Chapter 0: Student implementation build config
target("chapter0_tests")
    set_kind("static")
    set_languages("c++23")
    add_files("global.cppm", "metaInfo/metaInfo.cppm")
    set_values("c++.module.outputdir", "$(builddir)/modules")

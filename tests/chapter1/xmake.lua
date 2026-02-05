target("chapter1_tests")
    add_files("../test_main.cpp")
    add_files(
        "../test_metaInfo.cpp",
        "../test_array.cpp"
    )
    add_files("../../mystl/chapter1/**.cppm")
    add_deps("chapter1_modules")
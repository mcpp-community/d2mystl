target("chapter3_tests")
    add_files("../test_main.cpp")
    add_files(
        "../test_metaInfo.cpp",
        "../test_array.cpp",
        "../test_iterator.cpp",
        "../test_range.cpp"
    )
    if is_mode("debug") then
        add_files("../../src/chapter3/**.cppm")
    else
        add_files("../../mystl/chapter3/**.cppm")
    end
    add_deps("chapter3_modules")
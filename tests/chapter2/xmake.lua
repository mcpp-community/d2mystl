target("chapter2_tests")
    add_files("../test_main.cpp")
    add_files(
        "../test_metaInfo.cpp",
        "../test_array.cpp",
        "../test_iterator.cpp"
    )
    if is_mode("debug") then
        add_files("../../src/chapter2/**.cppm")
    else
        add_files("../../mystl/chapter2/**.cppm")
    end
    add_deps("chapter2_modules")
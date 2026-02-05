target("chapter1_tests")
    add_files("../test_main.cpp")
    add_files(
        "../test_metaInfo.cpp",
        "../test_array.cpp"
    )
    if is_mode("debug") then
        add_files("../../src/chapter1/**.cppm")
    else
        add_files("../../mystl/chapter1/**.cppm")
    end
    add_deps("chapter1_modules")
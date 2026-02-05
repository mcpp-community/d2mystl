target("chapter0_tests")
    add_files("../test_main.cpp")
    add_files("../test_metaInfo.cpp")
    if is_mode("debug") then
        add_files("../../src/chapter0/**.cppm")
    else
        add_files("../../mystl/chapter0/**.cppm")
    end
    add_deps("chapter0_modules")
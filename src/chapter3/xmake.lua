-- Chapter 3: range module
target("chapter3_modules")
    set_kind("moduleonly")
    add_files("global.cppm", { public = true })
    add_files("metaInfo/metaInfo.cppm")
    add_files("../chapter1/array/array.cppm")
    add_files("../chapter2/iterator/iterator.cppm")
    add_files("range/range.cppm")
-- Chapter 2: Iterator module
target("chapter2_modules")
    set_kind("moduleonly")
    add_files("global.cppm", { public = true })
    add_files("metaInfo/metaInfo.cppm")
    add_files("iterator/iterator.cppm")
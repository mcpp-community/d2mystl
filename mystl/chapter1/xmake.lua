-- Chapter 1: Array module
target("chapter1_modules")
    set_kind("moduleonly")
    add_files("global.cppm", { public = true })
    add_files("metaInfo/metaInfo.cppm")
    add_files("array/array.cppm")
-- Chapter 0: MetaInfo module
target("chapter0_modules")
    set_kind("moduleonly")
    add_files("global.cppm", { public = true })
    add_files("metaInfo/metaInfo.cppm")

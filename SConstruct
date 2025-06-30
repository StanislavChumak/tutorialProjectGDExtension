env = SConscript("../godot-cpp/SConstruct") # type: ignore

env.Append(CPPPATH=["src/"])
sources = Glob("src/*.cpp") # type: ignore

library = env.SharedLibrary(
    "demo/bin/gdextension{}{}".format(env["suffix"], env["SHLIBSUFFIX"]),
    source=sources
)

Default(library)  # type: ignore

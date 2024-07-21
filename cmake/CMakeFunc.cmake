function(MakeExecute)

    set(option "")
    set(one_val ExeName)
    set(mul_val ExecutableFiles LinkLib Definition IncludeDirectory TargetPro)

    cmake_parse_arguments(Arg "${option}" "${one_val}" "${mul_val}" ${ARGN})

    add_executable(${Arg_ExeName} ${GUI_TYPE} ${Arg_ExecutableFiles})

    set_target_properties(${Arg_ExeName} ${Arg_TargetPro})

    target_link_libraries(${Arg_ExeName} ${Arg_LinkLib})

    target_compile_definitions(${Arg_ExeName} ${Arg_Definition})

    target_include_directories(${Arg_ExeName} ${Arg_IncludeDirectory})

endfunction()

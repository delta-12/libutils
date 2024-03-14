include(CTest)
enable_testing()

function(add_test_with_valgrind name)
  add_test(NAME ${name} COMMAND ${name})
  add_test(NAME ${name}_valgrind
    COMMAND valgrind
      --tool=memcheck
      --leak-check=full       
      --trace-children=yes
      --show-error-list=yes
      --error-exitcode=2
      --xml=yes
      --xml-file=$<TARGET_FILE:${name}>-valgrind-report.xml
      $<TARGET_FILE:${name}>
)
endfunction()

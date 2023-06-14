#  emcc.sh


# allper: rk.h perdoc.h perhtm.h perdoc.c perhtm.c

#  ./emcc tests/hello_function.cpp -o function.html -s EXPORTED_FUNCTIONS="['_int_sqrt']"

# int mamb_report_personality (   /* in perdoc.o */
#   char *html_output_filename_webview,
#   char *html_output_filename_browser,
#   char *csv_person_string,
#   char *instructions,  /* like "return only csv with all trait scores" */
#   char *string_buffer_for_trait_csv )

# emcc rk.h perdoc.h perhtm.h perdoc.c perhtm.c  -o per_emcc.html   -s EXPORTED_FUNCTIONS="['_main', 'mamb_report_personality']"
#emcc                         perdoc.c perhtm.c  -o per_emcc.html   -s EXPORTED_FUNCTIONS="[         '_mamb_report_personality']"

# ==============================================================
# --------------------------------------------------------------
#  RUN LIKE THIS     $ cls; sh emcc.sh 2>errs; cat errs
# --------------------------------------------------------------
# ==============================================================
#
# e.g.    $ cls; sh emcc.sh 2>errs; cat errs


#set -vx
# set -v
set -x

# 
# # have ".h" files in dir but do not name them here
# emcc rkdebug.c mambutil.c \
#   perdoc.c perhtm.c \
#   grpdoc.c grphtm.c \
#   -o emcc.html \
#   -s EXPORTED_FUNCTIONS="[ \
#       '_mamb_report_personality', \
#       '_seq_find_exact_citPrvCountry', \
#       '_make_per_htm_file', \
#       '_mamb_report_just_2_people'  \
#        ]"
# echo "donedonedonedonedonedonedonedonedonedonedonedonedonedonedonedonedonedonedonedonedonedonedonedonedone"
# # end of  emcc.sh
# 

#       '_mamb_BIGreport_year_in_the_life' \
#       '_mamb_report_BIG_year' \
#        '_mamb_report_BIG_year' \
#   futdoc.c futhtm.c futasp.c \

# EMCC_DEBUG=1  or emcc -v
#  ./emcc -01 -s ASSERTIONS=1 tests/hello_world
# emcc -Werror  rkdebug.c mambutil.c \
#  -s SAFE_HEAP=1 \
#  -s SAFE_HEAP_LOG=1 \
#      '_seq_find_exact_citPrvCountry',\
# But why I get this problem even with EMULATE_FUNCTION_POINTER_CASTS=1 and ALIASING_FUNCTION_POINTERS=0 ?
# -s EMULATE_FUNCTION_POINTER_CASTS=1
# futdoc.c futhtm.c futasp.c \
#  futdoc.c futhtm.c\
#   -s ASSERTIONS=2\
#   -s ALIASING_FUNCTION_POINTERS=0\
#  futdoc.c futhtm.c\

# get err  futdoc.c         \
# no err          futhtm.c\
#   -s SINGLE_FILE=1\

# line below does 10mb -> 0.5mb
#   -O2\
# --closure 1
# emcc rkdebug.c mambutil.c 
#--memory-init-file 1  
# -s WASM=0\
# –closure-compiler 1
# --closure 1
# --closure 2

# Emscripten will emit WebAssembly by default. You can switch that off with -s WASM=0 
# (and then emscripten emits asm.js), which is necessary if you want the output to run in places where wasm support is not present yet, but the downside is larger and slower code.
#  -s EXTRA_EXPORTED_RUNTIME_METHODS='["ccall", "cwrap"]'
#  -s EXTRA_EXPORTED_RUNTIME_METHODS="['ccall', 'cwrap']"
#      'ccall',\
#  -s EXTRA_EXPORTED_RUNTIME_METHODS="['ccall']"
#  --shell-file shell_minimal.html\
#  -s NO_EXIT_RUNTIME=1\
#  -s MODULARIZE=1\
#  -s WASM=0\
#  --memory-init-file 0\
#  -O2\
# -v
# -s ENVIRONMENT=web
#  -s ENVIRONMENT=WEB\
# -s "EXTRA_EXPORTED_RUNTIME_METHODS=['ccall', 'cwrap']"\
# -s EXTRA_EXPORTED_RUNTIME_METHODS=['ccall', 'cwrap']\
# -s EXTRA_EXPORTED_RUNTIME_METHODS=['ccall']\
# -s EXTRA_EXPORTED_RUNTIME_METHODS=['ccall']\
# -s "EXTRA_EXPORTED_RUNTIME_METHODS=['ccall', 'cwrap']"\

#   -O2\
#   --memory-init-file 0\
#   -s MODULARIZE=1\

#     '_mamb_report_best_year',\

emcc    -Werror   rkdebug.c mambutil.c\
  perdoc.c perhtm.c\
  grpdoc.c grphtm.c\
  futdoc.c futhtm.c\
  -o emcc.html\
  -s ASSERTIONS=2\
  -s "EXTRA_EXPORTED_RUNTIME_METHODS=['ccall', 'cwrap']"\
  -s EXPORTED_FUNCTIONS="[\
      '_mamb_report_trait_rank',\
      '_mamb_report_best_day',\
      '_getPltPosSTR',\
      '_seq_find_exact_cpc',\
      '_mamb_report_personality',\
      '_make_per_htm_file',\
      '_mamb_report_just_2_people',\
      '_bin_find_first_city',\
      '_mamb_report_year_in_the_life',\
      '_mamb_report_big_year',\
      '_mamb_report_person_in_group',\
      '_mamb_report_whole_group'
     ]"

echo "donedonedonedonedonedonedonedonedonedonedonedonedonedonedonedonedonedonedonedonedonedonedonedonedonedone done done done done done done DONE"

# end of  emcc.sh


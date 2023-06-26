#!/bin/ksh
# makeprod.sh
#   assemble and minify all the pieces of per_emcc_my2.html
#   to make a production minified version - igotostars.html

#     tfr18.html  next test 7 part consolidated minify
#     1. html_1  from beginning to <style>
#     2. css     GRAB from <style> + 1 to </style> - 1 for minify pgm
#     3. html_2  from "</style>"     to  "// START OF MY C CODE plus JQuery"  (has big image lines)
#     4. emcc    run emcc.sh
#     5. JQ      copy in min version
#     6. non-c   GRAB from "// END OF MY C CODE plus JQuery"  to  "// END of my non-c code for minification"
#     7. add "\n</script> </body> </html>\n"



#   makeprod.sh
#   goldgblsvar.txt	
#   goldclassesinC.txt
#   goldidsinC.txt
#   goldclassesinjs.txt
#   goldidsinjs.txt
#   goldnames.txt
#   shuffle.sh
#   runclo.sh
#   tfrNavPlace.txt
#   tfrNavPlace.c


clear
# set -x



######################################################################
# EXAMPLE: list all WORDS starting with "gbls_" in a file
#  $ grep -o '\<gbls_\w*' tstreplace.html >tfr6
######################################################################




# 
# #      next  find num of occurrences of gbls_
# # 
# #     $ grep -o '\<gbls_tapOrClick\>' prodtst.tmp | wc -l
# #   echo "` grep -o '\<gbls_tapOrClick\>' prodtst.tmp | wc -l ` gbls_tap...
# # 
# # 
# # 
# # 
# # 
# export INPUT_VARNAME_SHORTEN="prodtst.html"
# export LIST_GBLS="goldgblsvar.txt"
# for f in `cat $LIST_GBLS`
# do
#   echo "gbls var = [$f]"  >/dev/tty
# 
#   # grep -o "\<$f\>" $INPUT_VARNAME_SHORTEN
# 
#   echo "` grep -o "\<$f\>" $INPUT_VARNAME_SHORTEN | wc -l ` $f "
# 
#   #echo "========================"
#   
#   # break
# done  > cntgblsvar.txt
# 
# echo ""
#exit



# FYI COUNT OCCURRENCES OF STRING
#  $ grep -o -i qoqqo tstreplace.html | wc -l


#         # shuffle.sh
#         # unsort a sorted file
#         
#         # $ cat tfr8 | awk 'BEGIN{srand();}{print rand()"\t"$0}' | sort -k1 -n | cut -f2- > shuffled_linex.txt
#         
#         awk 'BEGIN{srand();}{print rand()"\t"$0}' $1 | sort -k1 -n | cut -f2- 
#         # end of shuffle.sh
# 





# CCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCC
#   CREATE   "replacementnames.txt"
# CCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCC
# 
# make list of token name of the form "QIOlB"
#
#      where chars come from "0O8BIl1" - 7 chars
#   8*7*7*7 = 2,744
#   7*6*6*6 = 1,512
#  
#export NAME_CHARS_ALL="0O8BIl1"
#export NAME_CHARS_BEG="OBIl"
#   4*6*6*6 =   864


# 
# # all names start with Q or O 
# export NAME_CHARS_ALL="O0QB8"
# export NAME_CHARS_BEG="O0QB8"
# 
# export BEGINNING_LETTER="Q"
# export OUTFIL="replacementnames${BEGINNING_LETTER}.txt"
# #awk ' NR == 0 {
# echo "junk" | awk -v chars_all="$NAME_CHARS_ALL" -v chars_beg="$NAME_CHARS_BEG" -v outfil="$OUTFIL" -v beglet="$BEGINNING_LETTER" '
#   BEGIN {
#     printf("chars_all=[%s], beglet=[%s]\n", chars_all, beglet)
#     split(chars_beg,  chars_beg_arr, "")
#     split(chars_all,  chars_all_arr, "")
#     for (i=1; i <= length(chars_beg); i++) {
#       currchar1 = chars_beg_arr[i] 
#       for (j=1; j <= length(chars_all); j++) {
#         currchar2 = chars_all_arr[j] 
#         for (k=1; k <= length(chars_all); k++) {
#           currchar3 = chars_all_arr[k] 
#           for (m=1; m <= length(chars_all); m++) {
#             currchar4 = chars_all_arr[m] 
#             printf("%s%s%s%s%s\n", beglet, currchar1, currchar2, currchar3, currchar4)   > outfil
#           }
#         }
#       }
#     }
#   }
# '
# export BEGINNING_LETTER="O"
# export OUTFIL="replacementnames${BEGINNING_LETTER}.txt"
# #awk ' NR == 0 {
# echo "junk" | awk -v chars_all="$NAME_CHARS_ALL" -v chars_beg="$NAME_CHARS_BEG" -v outfil="$OUTFIL" -v beglet="$BEGINNING_LETTER" '
#   BEGIN {
#     printf("chars_all=[%s], beglet=[%s]\n", chars_all, beglet)
#     split(chars_beg,  chars_beg_arr, "")
#     split(chars_all,  chars_all_arr, "")
#     for (i=1; i <= length(chars_beg); i++) {
#       currchar1 = chars_beg_arr[i] 
#       for (j=1; j <= length(chars_all); j++) {
#         currchar2 = chars_all_arr[j] 
#         for (k=1; k <= length(chars_all); k++) {
#           currchar3 = chars_all_arr[k] 
#           for (m=1; m <= length(chars_all); m++) {
#             currchar4 = chars_all_arr[m] 
#             printf("%s%s%s%s%s\n", beglet, currchar1, currchar2, currchar3, currchar4)   > outfil
#           }
#         }
#       }
#     }
#   }
# '
# 
# # combine the Q-starters and the O-starters  (625 lines each) 
# #
# cat replacementnamesO.txt replacementnamesQ.txt >replacementnames.txt
# #   fyi           $ wc -l replacemen*
# #                 1250 replacementnames.txt
# #                  625 replacementnamesO.txt
# #                  625 replacementnamesQ.txt
# 
# #wc -l $OUTFIL
# wc -l  replacementnamesO.txt replacementnamesQ.txt replacementnames.txt
# 
#exit


# CCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCC
#   CREATE   "replacementnames.txt"
# CCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCC
# 
# make list of token name of the form "QIOlB"
#
#      where chars come from "0O8BIl1" - 7 chars
#   8*7*7*7 = 2,744
#   7*6*6*6 = 1,512
#  
#export NAME_CHARS_ALL="0O8BIl1"
#export NAME_CHARS_BEG="OBIl"
#   4*6*6*6 =   864
#export NAME_CHARS_ALL="O0QGB8Il1"    # for 5999  = 3,645

# second version
# export NAME_CHARS_ALL="O0QB8Il1"
# export NAME_CHARS_BEG="OQBIl"      # 4-char names    tot num = 5*8*8*8 = 2,560

# 20201108  replace l with D  now all same height
export NAME_CHARS_ALL="O0QB8ID1"
export NAME_CHARS_BEG="OQBID"      # 4-char names    tot num = 5*8*8*8 = 2,560

export BEGINNING_LETTER="O"
export OUTFIL="replacementnames_5888.txt"  # 4-char names 

echo "start    CREATE $OUTFIL"
echo "junk" | awk -v chars_all="$NAME_CHARS_ALL" -v chars_beg="$NAME_CHARS_BEG" -v outfil="$OUTFIL"  '
  BEGIN {
# printf("chars_all=[%s], chars_beg=[%s]\n", chars_all, chars_beg)
    split(chars_beg,  chars_beg_arr, "")
    split(chars_all,  chars_all_arr, "")
    for (i=1; i <= length(chars_beg); i++) {
      currchar1 = chars_beg_arr[i]
      for (j=1; j <= length(chars_all); j++) {
        currchar2 = chars_all_arr[j]
        for (k=1; k <= length(chars_all); k++) {
          currchar3 = chars_all_arr[k]
          for (m=1; m <= length(chars_all); m++) {
            currchar4 = chars_all_arr[m]
# printf("%s%s%s%s\n", currchar1, currchar2, currchar3, currchar4)   > outfil
          }
        }
      }
    }
  }
'
wc $OUTFIL ; head -2 $OUTFIL ;  echo "-----"; tail -2 $OUTFIL  
#exit



# CCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCC




# export PROD_FILE_BEG="per_emcc_my2.html"
 

export RED=`tput setab 1; tput setaf 7`
export REVon=`tput rev`   # reverse video
export Toff=`tput sgr0`


# part 1 of 2 info
echo "================================================================================"
echo " PREPARE input file (prod_input.html) for this script (makeprod.sh) "
echo "================================================================================"
echo " "
echo "${REVon} cp per_emcc_my2.html prod_input.html;  mvim prod_input.html ${Toff} "
echo " "
echo " BEFORE STARTING,  CHANGE prod_input.html "
echo " "
echo " UPDATE version number to next higher number   var gbls_${RED}versionT${Toff}OKEN = 'v03' ; "   
echo "   for version id in middle button and restrict_access dialogue"
echo " "
echo " UPDATE this var value  var ${RED}gbls_thisHTMLis${Toff} = "   
echo "   to be one of these 2:"
echo "      \"for website igotostars.org\" "
echo "      \"for standalone app - not for a website\" "
echo " "
echo "   CONSIDER commenting out  line below if there is no app icon"
echo "      (' sharp imgAppEMBLEM') .css('display','block').css ..."
echo "   CONSIDER changing   var gbls_thisAppDESCRIPTION  = 'free app igotostars.org' "
echo "   CONSIDER changing   var gbls_thisAppEMAIL        = 'boldly@igotostars.org' "
echo "   CONIDER  changing   var gbls_thisAppOneWord      = 'igotostars' "  

# echo "   CONSIDER changing   " echo " <title>igotostars, test astrology</title>"
#   <meta name=\"Description\" content=\"With a scientific attitude of OPEN-MINDED SKEPTICISM, use igotostars to test if astrology works.\">
#  <meta name=\"keywords\" content=\"astrology, free, scientific, open-minded, igotostars\"> "

echo " "
echo " CONSIDER turning on temporary access restriction"
echo "   //var gbls_restrict_access = 'yes';  // passcode due to testing"
# echo " "
# echo " CONSIDER commenting out body of function quickAddPeople() / testPER_put_into_LS()"
# echo "   because it has readable test people data"
echo " "
echo " CONSIDER turning off logging functions "
echo "   A) in javascript - in prod_input.html"
echo "      funct${RED}ion smup_l${Toff}og()     // rkfns  ALSO smup_at(), smup_to() "
echo "      return; // for production  "
echo "      //  console.log();   // search for \"log STRATEGY\" "
echo "   B) in C -  in rkdebug.c"
echo "      //int RKDEBUG=0;/* =0 stops  output in all these debug functions */"
echo "      int RKDEBUG=1;  /* =1 starts output in all these debug functions */"
echo "      Now run emcc.sh to compile the C code into javascript"
echo "      Now put emcc.js into prod_input.html"
echo " "
echo "  3.    in vi, remove BOTH of these 2 "
echo "        - emcc.js code  - C code compiled into javascript by emcc.sh"
echo "        - jquery code"
echo "        This code to be removed is together in one block"
echo "        Go to the start of the code to be removed."
echo "           Search for \"emcc.${RED}js GOES${Toff} HERE   vvvvv\""
echo "        Go to the   end of the code to be removed."
echo "           Search for \"JQUER${RED}Y GOES${Toff} HERE   ^^^^^\""
echo "        SAVE the approx 45,000 lines of code - about 10 megabytes"
echo "           under the name \"${RED}save_jquery_emcc.js${Toff}\""
echo "        in vi, DELETE the approx 45,000 lines of code - about 10 megabytes"
echo "  4. save the smaller prod_input.html"
echo "================================================================================"
echo ""
echo "type y if prod_input.html is prepared by the above and ready to be processed"
read answer
if [ "$answer" != "y" ] ; then
  echo "prepare prod_input.html according to the above instructions and run makeprod.sh again"
  exit 500
fi
# part 1 of 2 info



# echo "exit 112"
# exit 112

#export PROD_FILE_BEG="per_emcc_my2.html"
export PROD_FILE_BEG="prod_input.html" # cp per_emcc.my2.html prod_input.html, then rm jquery code and emcc.js from prod_input.html
export PROD_FILE_TMP1="prodtst.tmp1"
export PROD_FILE_TMP2="prodtst.tmp2"
export PROD_FILE_END="prodtst.html"


# note: rmCcomment.sh is not good enough
# echo "    1. remove C-like comments - rmCcomment.sh "
# rmCcomment.sh $PROD_FILE_BEG  >  $PROD_FILE_TMP1
# cp $PROD_FILE_BEG  $PROD_FILE_TMP2
cp $PROD_FILE_BEG  $PROD_FILE_TMP1
 

# echo "exit 1"
# exit 1 # for test




# 
# #  SPECIAL treatment of ccall - have to replace  BOTH  ccall_fn_name  AND  _ccall_fn_name   using the SAME REPLACEMENt NAME
# #          also replace "ccall"  itself
# #
# #             51058   O8BQB = ccall( 'mamb_report_personality' ,
# #             51068 smup_log('after   ccall mamb_report_personality ');
# #             51104   QO808 = ccall( 'mamb_report_big_year' ,
# #             51357     O8OO0 = ccall( 'mamb_report_just_2_people' ,
# #             51366   smup_log('after   ccall mamb_report_just_2_people');
# #             51461     OB0BQ  = ccall( 'seq_find_exact_cpc' ,
# #             51482       OO800 = ccall( 'seq_find_exact_cpc' ,
# #             53643         QQQQB  = ccall( 'mamb_report_big_year' ,
# #  IN emcc.sh       '_seq_find_exact_cpc',\
# #                   '_mamb_report_personality',\
# #                   '_make_per_htm_file',\
# #                   '_mamb_report_just_2_people',\
# #                   '_mamb_report_big_year'
# #               gbls_HTML_code_for_per = ccall( 'mamb_report_personality' ,
# #               gbls_HTML_code_for_fut = ccall( 'mamb_report_big_year' ,
# #                 gbls_HTML_code_for_ju2 = ccall( 'mamb_report_just_2_people' ,
# #                   retDiffLong2 = ccall( 'seq_find_exact_cpc' ,
# #                     gbls_text_DATA_for_tg  = ccall( 'mamb_report_big_year' ,     
# 
# # CCALL_FNS not used, apparently  20201020
# export CCALL_FNS="
# seq_find_exact_cpc
# mamb_report_personality
# make_per_htm_file
# mamb_report_just_2_people
# mamb_report_big_year
# "
# #echo $CCALL_FNS | while read lin 
# # echo $CCALL_FNS | tr ' ' '\n'  |  while read ccall_fn_name
# # do
# #   echo "ccall_fn_name=$ccall_fn_name"
# # done
# 
# # FYI
# #   var real__seq_find_exact_cpc = asm["_QlIllI"]; asm["_QlIllI"] = function() {
# #     return real__seq_find_exact_cpc.apply(null, arguments);
# # AND
# #   OB80Q  = ccall( 'seq_find_exact_cpc' ,
# 
# # NOTE: need ex to do \< ... \>
# ex  <<-EOF   >/dev/null
#   e $PROD_FILE_TMP
#   g/\<ccall\>/s//QllIll/g
# 
#   g/\<seq_find_exact_cpc\>/s//QlIllI/g
#   g/_seq_find_exact_cpc\>/s//_QlIllI/g
# 
#   g/\<mamb_report_personality\>/s//QIlllI/g
#   g/_mamb_report_personality\>/s//_QIlllI/g
# 
#   g/\<make_per_htm_file\>/s//QlIlIl/g
#   g/_make_per_htm_file\>/s//_QlIlIl/g
# 
#   g/\<mamb_report_just_2_people\>/s//QlllII/g
#   g/_mamb_report_just_2_people\>/s//_QlllII/g
# 
#   g/\<mamb_report_big_year\>/s//QlIIll/g
#   g/_mamb_report_big_year\>/s//_QlIIll/g
#   w $PROD_FILE_TMP
#   q
# EOF
# # exit # for test
# #
# #  SPECIAL treatment of ccall - have to replace  BOTH  ccall_fn_name  AND  _ccall_fn_name   using the SAME REPLACEMENt NAME
# 


#    # dovi.sh    do VI commands on an input file
#    # 
#    # TEMPLATE for doing multiple edits on a file
#    #          - modify the edits 
#    fil=$1
#    ed  <<-EOF   >/dev/null
#      e $fil
#      g/ARDiscrep No:/s/.*//
#      g/Batch Date:/s/.*//
#      g/Transaction Date:/s/.*//
#      g/tagOrder:/s/.*//
#      w $fil
#      q
#    EOF
#    # end of dovi.sh

# lines beginning with smup_log(
# lines beginning with spaces, smup_log(
# lines beginning with spaces, //
# chars from // to eol
# 
  # g/^ *\/\/[^K][^E][^E][^P]/d
  # g/\/\/ /s/\/\/[^K][^E][^E][^P].*$//
# 
# 

# for test, keep smup_log
# g/^[\/ ]*smup_log[(]/d
# g/^ *smup_log[(]/d

# g/^[\/ ]*smup_log[(]/d
# g/^ *smup_log[(]/d

# g/^[\/ ]*smup_log[(]/d
# g/^ *smup_log[(]/d



#  SPECIAL treatment of ccall - have to replace  BOTH  ccall_fn_name  AND  _ccall_fn_name   using the SAME REPLACEMENt NAME

# see cfns.sh done after  construction of prodtst.html by adding emcc.js and jquery
echo " see cfns.sh done after  construction of prodtst.html by adding emcc.js and jquery"

#  SPECIAL treatment of ccall - have to replace  BOTH  ccall_fn_name  AND  _ccall_fn_name   using the SAME REPLACEMENt NAME
#
# 
# NOTE: need ex to do \< ... \>
#  exact string  "ccall" has to be in there, so rm  g/\<ccall\>/s//QllIll/g   from below

#
#  SPECIAL treatment of ccall - have to replace  BOTH  ccall_fn_name  AND  _ccall_fn_name   using the SAME REPLACEMENt NAME


#exit 5  # for test



# #  NOTE: smup_log is kept in and turned off in code 



echo "    3. remove HTML comments"
#remove HTML comments
awk '
BEGIN {
    com_lvl = 0;
}

/<!--/ {
    if (com_lvl == 0) {
        line = $0
        sub(/<!--.*/, "", line)
        printf line
    }
    com_lvl = com_lvl + 1
}

com_lvl == 0

/-->/ {
    if (com_lvl == 1) {
        line = $0
        sub(/.*-->/, "", line)
        print line
    }
    com_lvl = com_lvl - 1;
}
'  $PROD_FILE_TMP1 >  $PROD_FILE_TMP2
# '  $PROD_FILE_BEG  >  $PROD_FILE_TMP1



echo "    1. remove // comments (end of line)"
ed  <<-EOF   >/dev/null
  e $PROD_FILE_TMP2
  g/ \/\/ /s/ \/\/ .*$//
  w $PROD_FILE_TMP1
  q
EOF
#cp  $PROD_FILE_TMP1 $PROD_FILE_TMP2

#echo "exit 102 after 1."
#exit 102

echo "    2. remove // comments (whole line)"
ed  <<-EOF   >/dev/null
  e $PROD_FILE_TMP1
  g/^ *\/\//d
  w $PROD_FILE_TMP2
  q
EOF
# end of dovi.sh
# 



echo "    0. remove /* ... */ comments WITHIN A LINE)"
ed  <<-EOF   >/dev/null
  e $PROD_FILE_TMP2
  g/\/\*.*\*\//s/\/\*.*\*\///
  w $PROD_FILE_TMP1
  q
EOF



#  DO NOT remove smup_log() lines
echo "    -1. remove smup_log() lines"
# echo "DO NOT remove smup_log() lines"
# cp $PROD_FILE_TMP1 $PROD_FILE_TMP2
echo "DO actually remove smup_log() lines  QQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQq"
echo "DO actually remove smup_log() lines  QQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQq"
echo "before ..."
wc  $PROD_FILE_TMP1
cp  $PROD_FILE_TMP1 before.html
wc  before.html

ed  <<-EOF   >/dev/null
  e $PROD_FILE_TMP1
  g/^ *smup_log.*) *; *$/d
  g/^ *smup_at.*) *; *$/d
  w $PROD_FILE_TMP2
  q
EOF

echo "after ..."
cp  $PROD_FILE_TMP2 after.html
wc  after.html
echo "DO actually remove smup_log() lines  QQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQq"
echo "DO actually remove smup_log() lines  QQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQq"




# NOTE: since /* ... */  within a line)  are GONE
# we can remove all lines  from  /^ *\/\*/ to  /\*\//  inclusive
#
echo "    -2. remove MULTI-LINE /* ... */ comments"
rm linesout.txt
export awk=awk
$awk '
{
  line = $0
  rmBEG =   1         # remove /* ... */  numbers rmBEG to rmEND
  rmEND =   9999

# maxToRemove = 999
# if (num_removed >= maxToRemove) { print line; next; }  # print all the rest of lines

  if ( match(line, /^\/[*]/ ) ) {
    # this is BEG of multi-line /* ... */ comment
    areInMultiLine_comment = "yes"
    rmNUM = rmNUM + 1              #  like record num of  /* ... */

    if (rmNUM >= rmBEG  &&  rmNUM <= rmEND) {    # remove this if true
      print "REMOVED  BEG " saveBEG_NR " " line        >> "linesout.txt"
      next  # do not print line
    }
  }

  if ( match(line, /[*]\/$/ ) ) {
    # this is END of multi-line /* ... */ comment
    areInMultiLine_comment = "no"

    if (rmNUM >= rmBEG  &&  rmNUM <= rmEND) {    # remove this if true
      num_removed = num_removed + 1
      print "REMOVED  END " saveBEG_NR " " line  "\n# " rmNUM "\n"  >> "linesout.txt"
      next  # do not print line
    }
  }

  if ( areInMultiLine_comment == "yes") {
    if (rmNUM >= rmBEG  &&  rmNUM <= rmEND) {    # remove this if true
      print "REMOVED  MID " saveBEG_NR " " line        >> "linesout.txt"
      next  # do not print line
    }
  }

  print line   #  print lines not   /* ... */
}
' $PROD_FILE_TMP2  > $PROD_FILE_TMP1


#exit 202 # for test






echo "    4. remove blank lines"
# remove blank lines
ed  <<-EOF   >/dev/null
  e $PROD_FILE_TMP1
  g/^$/d
  w $PROD_FILE_TMP2
  q
EOF


#  FYI    export PROD_FILE_BEG="per_emcc_my2.html"
#  FYI    export PROD_FILE_END="prodtst.html"
cp  $PROD_FILE_TMP2 $PROD_FILE_END

# log-like stuff
#
echo "-------------------------------------------------"
wc -c $PROD_FILE_BEG
wc -c $PROD_FILE_END
echo "-------------------------------------------------"
wc -l $PROD_FILE_BEG
wc -l $PROD_FILE_END

echo "-------------------------------------------------"
CB=`wc -c $PROD_FILE_BEG | awk '{print $1}' `
CE=`wc -c $PROD_FILE_END | awk '{print $1}' `
let diff="$CB - $CE"
let pc="$diff * 100 / $CB"
echo "   $diff  fewer characters  $pc percent"
LB=`wc -l $PROD_FILE_BEG | awk '{print $1}' `
LE=`wc -l $PROD_FILE_END | awk '{print $1}' `
let diff="$LB - $LE"
let pc="$diff * 100 / $LB"
echo "    $diff  fewer lines       $pc percent"
echo "-------------------------------------------------"
#
# log-like stuff


export REPLACEMENT_NAMES="replacementnames.txt"
export NAMES_TO_REPLACE="namestoreplace.txt"


# shuffle replacement names  -  replacementnames_5888.txt
#
echo "shuffle replacement names"
wc replacementnames_5888.txt   # sorted
# from  shuffle.sh # unsort a sorted file


# awk 'BEGIN{srand();}{print rand()"\t"$0}' replacementnames_5888.txt >tfr1
# awk 'BEGIN{srand();}{print rand()"\t"$0}' replacementnames_5888.txt | sort -k1 -n >tfr2
# awk 'BEGIN{srand();}{print rand()"\t"$0}' replacementnames_5888.txt | sort -k1 -n | cut -f2- > tfr3
awk 'BEGIN{srand();}{print rand()"\t"$0}' replacementnames_5888.txt | sort -k1 -n | cut -f2- > $REPLACEMENT_NAMES



#
# shuffle replacement names  -  replacementnames_5888.txt




# cat replacementnames.txt | awk 'BEGIN{srand();}{print rand()"\t"$0}' $1 | sort -k1 -n | cut -f2- > "goldnames.txt"
# cat replacementnames_5888.txt | shuffle.sh > REPLACEMENTnames_5888.txt

wc $REPLACEMENT_NAMES

echo "----------------------------------------------------------"
echo "shuffled replacement names are in $REPLACEMENT_NAMES"
wc $REPLACEMENT_NAMES
echo "----------------------------------------------------------"

# echo "exit 3a  no replace"
# exit 3 # for test

# ends here.  see script below
#    produce $NAMES_TO_REPLACE  




# WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW
# WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW
#
# NOTE: these IDs and classes in the files below are ALL defined in JS with ID= and .classname {}
#       so they are never referenced in C code
#
# NOTE: there are IDs and classes created in C code and referenced in JS code
#       and these ones are NOT renamed and so deleted from goldids.txt and goldclasses.txt
#
#                     ??  A  ones in both,    41  leave alone    do not rename
#                         B  ones in2notin1,  74  change name
#                         C  ones in1notin2,  21  check if unused
#                   -rw-r--r--  1 rk  staff   631 21 Oct 02:10 goldclassesinC.txt
#                   -rw-r--r--  1 rk  staff  1230 21 Oct 02:28 goldclassesinjs.txt
#                         62 goldclassesinC.txt    A + C
#                        115 goldclassesinjs.txt   A + B

# NOTE: do not try to rename CLASSES  -  too messy                                          
#
#in2notin1 goldclassesinC.txt goldclassesinjs.txt > goldclasses.txt #   62  115  >  74 only in 2 (js)
# cat goldgblsvar.txt goldidsinjs.txt goldclasses.txt > $NAMES_TO_REPLACE
#
# NOTE: do not try to rename CLASSES  -  too messy                                          
#  
# UPDATE:  # goldclasses.txt replacement names actually work if these 4 classes are NOT RENAMED
#                   slideInLeft
#                   slideOutRight
#                   slideInRight
#                   slideOutLeft


# cat goldgblsvar.txt goldidsinjs.txt                             goldparams.txt > $NAMES_TO_REPLACE
# cat goldgblsvar.txt                 goldvarvars.txt             goldparams.txt >  $NAMES_TO_REPLACE
# cat goldgblsvar.txt goldidsinjs.txt goldvarvars.txt             goldparams.txt >  $NAMES_TO_REPLACE
# cat goldgblsvar.txt goldidsinjs.txt goldvarvars.txt goldemccfns.txt                 goldparams.txt >  $NAMES_TO_REPLACE





# NOTE: here we grab the list for $NAMES_TO_REPLACE  manually  using the following cmd lines


#echo "exit 105 before replacem"
#exit 105


# tput clear

#    cat  goldgblsvar.txt  goldidsinjs.txt  goldvarvars.txt goldjsfns.txt  > $NAMES_TO_REPLACE
  echo " ========================================================================== "
  echo "    produce $NAMES_TO_REPLACE  - namestoreplace.txt"
  echo "    cat  goldgblsvar.txt  goldidsinjs.txt  goldvarvars.txt goldjsfns.txt  > $NAMES_TO_REPLACE"
  echo " ========================================================================== "

  echo -n "" > goldgblsvar.txt
  echo -n "" > goldidsinjs.txt    # comment out going with HARD-CODED  safer version
  echo -n "" > goldvarvars.txt 
  echo -n "" > goldjsfns.txt
  wc goldgblsvar.txt
  wc goldidsinjs.txt
  wc goldvarvars.txt 
  wc goldjsfns.txt

# echo "exit 201"
# exit 201


  echo "==========  1 of 4  ========================================================="
  echo " goldgblsvar.txt   approx   408 "
#  goldgblsvar.txt   approx   408

  grep -i '^ *var  *gbls'   prodtst.html  > replaceTmp1
  awk -F'[ ;]' '{ print $2 }' replaceTmp1  | sort >  goldgblsvar.txt

  # here, manually check goldgblsvar.txt for dups

  wc goldgblsvar.txt
  echo "_____________________________________________________________________________"
  echo ""



  echo "==========  2 of 4  ========================================================="
  echo " goldjsfns.txt   approx   140 "

  grep -i "^ *function.*)"  prodtst.html > replaceTmp1
  sed "/function()/d"       replaceTmp1  > replaceTmp2
  sed "s/^ *//"             replaceTmp2  > replaceTmp1
  grep -o " .*("            replaceTmp1  > replaceTmp2 # matches fn name up to '('
  sed "s/[ (]*$//"          replaceTmp2  > replaceTmp1
  sed "s/^ *//"             replaceTmp1  > replaceTmp2
  sed "s/(//"               replaceTmp2  > replaceTmp1

  sort replaceTmp1 > goldjsfns.txt
  wc goldjsfns.txt
  echo "_____________________________________________________________________________"
  echo ""


  # NO HARD-CODED 20210421 # resort to HARD-CODED   goldidsinjs.txt   HARD-CODED    approx 433 

  echo "==========  3 of 4  ========================================================="
  echo " goldidsinjs.txt   approx 433 "
  echo " resort to HARD-CODED  goldidsinjs.txt  HARD-CODED   approx 433 HARD-CODED"

 grep -o "\<id='[^']*'" prodtst.html >  replaceTmp1 # matches id=' ... up to FIRST '

  #   this replaces lines like:
  #id='smup_divNAVB'
  #   with lines like:
  #smup_divNAVB
  sed "s/.*\'\([^\']*\)\'/\1/" replaceTmp1  | sort >  goldidsinjs.txt
  wc  goldidsinjs.txt

  # here, manually check goldidsinjs.txt for dups


  # certain IDs have their names built or parsed, so remove them
  echo " certain IDs have their names built or parsed, so remove them from shortening"
ed <<-EOF >/dev/null
  e goldidsinjs.txt
  g/^PIKbyr[0-9]/d
  g/^bday[0-9][0-9]/d
  g/^bmth[0-9][0-9]/d
  g/^tgCANVAS[0-9][0-9]/d
  g/^tgDATA[0-9][0-9]/d
  g/^tgHDR[0-9][0-9]/d
  g/^tgYR[0-9][0-9]/d
  g/^PICKyr[0-9][0-9]/d
  w goldidsinjs.txt
  q
EOF


  wc goldidsinjs.txt
  echo "_____________________________________________________________________________"
  echo ""


  echo "============  4 of 4  ======================================================="
  echo  goldvarvars.txt   approx 808
  

#  grep -i ' var '   prodtst.html  > replaceTmp1  
  grep -i '^ *var '   prodtst.html  > replaceTmp1  

  wc replaceTmp1
# tail -2 replaceTmp1

  # this replaces lines like:
  #     var rect = el.getBoundingClientRect();
  # with lines like:
  #rect
  #
ed  replaceTmp1  <<-EOF >/dev/null
  g/ = .*$/s///
  g/ *$/s///
  g/;*$/s///
  g/ *$/s///
  g/^ */s///
  g/^var /s///
  w replaceTmp2
  q
EOF

  sort replaceTmp2 | uniq > goldvarvars.txt

  # here, manually check goldvarvars.txt for dups

  wc goldvarvars.txt
  echo "_____________________________________________________________________________"
  echo "============================================================================="
  echo ""
  




    # fyi export REPLACEMENT_NAMES="replacementnames.txt"
    #     export NAMES_TO_REPLACE="namestoreplace.txt"




# cat  goldgblsvar.txt  goldidsinjs.txt  goldvarvars.txt goldjsfns.txt  > $NAMES_TO_REPLACE
# cat  goldgblsvar.txt  goldidsinjs.txt  goldvarvars.txt goldjsfns.txt  > $NAMES_TO_REPLACE



# FIND CULPRIT
# echo "CULPRIT goldvarvars.txt  2    "
#   cat  goldgblsvar.txt  goldidsinjs.txt                  goldjsfns.txt  > $NAMES_TO_REPLACE

cat  goldgblsvar.txt  goldidsinjs.txt  goldvarvars.txt goldjsfns.txt | sort | uniq  >  $NAMES_TO_REPLACE

# 
# # cat  goldgblsvar.txt  goldidsinjs.txt  goldvarvars.txt goldjsfns.txt | sort | uniq  >  $NAMES_TO_REPLACE
# # echo "CULPRIT goldvarvars.txt  UNIQ    "
# 
# cat  goldgblsvar.txt                   goldvarvars.txt goldjsfns.txt | sort | uniq  >  $NAMES_TO_REPLACE
# echo "CULPRIT goldidsinjs.txt   ?? "
# 
# cat "CULPRIT was goldidsinjs.txt  "
# 







  # special cases to rename
  echo "whereCalledFrom"       >>  $NAMES_TO_REPLACE
  echo "where_called_from"     >>  $NAMES_TO_REPLACE
  echo "arg_whereFrom"         >>  $NAMES_TO_REPLACE
  echo "arg_where_from"        >>  $NAMES_TO_REPLACE
  echo "arg_whereCalledFrom"   >>  $NAMES_TO_REPLACE
  echo "arg_where_called_from" >>  $NAMES_TO_REPLACE


  wc goldgblsvar.txt
  wc goldidsinjs.txt
  wc goldvarvars.txt 
  wc goldjsfns.txt
  echo ""

  echo " ========================================================================== "

  # "    produce $NAMES_TO_REPLACE  - namestoreplace.txt"
  # "    cat  goldgblsvar.txt  goldidsinjs.txt  goldvarvars.txt goldjsfns.txt  > $NAMES_TO_REPLACE"
  # " ========================================================================== "


  # here, do SAME NAME CHECK


  echo "----------------------------------------------------------"
  echo "shuffled replacement names are in $REPLACEMENT_NAMES"
  wc $REPLACEMENT_NAMES
  echo "names to replace are in $NAMES_TO_REPLACE"
  wc $NAMES_TO_REPLACE
  echo "----------------------------------------------------------"
  echo ""
  echo ""
  echo ""
sleep 3

# echo "exit 8"
# exit 8

  #  goldgblsvar.txt  goldidsinjs.txt  goldvarvars.txt


# 
# ==================================================
#    produce $NAMES_TO_REPLACE  -namesToReplace.sh
# ==================================================



# ==================================================

# 
#   # remove comments in gold files
# echo "    2b. remove comments in file  $NAMES_TO_REPLACE"
# ed  <<-EOF   >/dev/null
#   e $NAMES_TO_REPLACE
#   g/^ *\/\//d
#   g/^ *#/d
#   w $NAMES_TO_REPLACE
#   q
# EOF


# WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW
# WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW


# cp $PROD_FILE_END tstreplace.html     # cp prodtst.html tstreplace.html
# fil="tstreplace.html"
lincnt="0"


# # note: used ex below because ed did not support g/\<$n\>/s//bozo/


#
# if syntax
# #     if [ $a == $b ]
# #     then
# #        echo "a is equal to b"
# #     else
# #        echo "a is not equal to b"
# #     fi
# 

# set -vx 
# write edit cmds into file named temped
# 
echo "    3. put edit cmds into file named temped  (about 4 minutes) "
date

echo -n "" >temped
paste $NAMES_TO_REPLACE $REPLACEMENT_NAMES | while read lin
do
  let lincnt="$lincnt + 1"
# if [ $lincnt -ge "512" ] 
# then
# exit
# fi

  a=($(echo "$lin" | tr ' ' '\n'))  # unpaste
  old="${a[0]}"
  new="${a[1]}"
  if [ "$new" == "" ] ; then break ; fi

#echo $lin >>temped

#grep  /base64,iVBORw0.*id=\'$old\'/  $PROD_FILE_END >> temped
# $ grep  'base64,iVBORw0.*id=.imgNEWP\>'  testin 


# echo -n "" >testout
# grep  "base64,iVBORw0.*id=.$old\>"   $PROD_FILE_END  >> testout 
# echo  "base64,iVBORw0.*id=.$old\>"   $PROD_FILE_END  >> testout 
# 
# grep  "base64,iVBORw0.*id=.IMG_sel_homg_MA\>"   $PROD_FILE_END  >> testout 
# echo  "base64,iVBORw0.*id=.IMG_sel_homg_MA\>"   $PROD_FILE_END  >> testout 




    # find out if this NAME_TO_REPLACE ($old)  is in a /base64,iVBORw0/ line
    # AND it appears in a string   id='$old'
    #
    is_iVBOR_ID="no"
    if  grep -q "base64,iVBORw0.*id=.$old\>"  $PROD_FILE_END 
    then
      is_iVBOR_ID="yes"
#echo "is_iVBOR_ID = yes"  >> temped
#grep "base64,iVBORw0.*id=.$old\>"  $PROD_FILE_END >> temped
#echo "exit test 100"
#exit 100
    fi

      # printf "old=[$old]  new=[$new]\n" 
      #         old=[gbls_nav_place_now]  new=[QOQQO]
# echo "g/base64,iVBORw0/s/ id=\'$old\'/ id=\'$new\'/g"  >> temped #     edit large image lines
#     echo "g/ id=\'$old\'/s//id=\'$new\'/g"    >> temped #     edit large image lines

    if [ "$is_iVBOR_ID" == "yes" ]  
    then
#   # for long ivbor lines change   id='$old'>    to    id='$new'>    
      echo "g/base64,iVBORw0.*id=\'$old\'/s/ id=\'$old\'/ id=\'$new\'/g"  >> temped #     edit large image lines
#echo "exit test 101"
#exit 101
    fi

  echo "v/base64,iVBORw0/s/\<$old\>/$new/g" >> temped # v = skip editing large image lines

done


wc temped
date 

#echo "exit 83"
#exit 83



#   ex  <<-EOF   >/dev/null
#     e $fil
# i
# `cat temped`    
# .
#     w $fil
#     q
# EOF


# write ex invocation PLUS edit cmds (temped) into file named MY_EX_CMD.sh
# 
echo "    4. put ex invocation PLUS edit cmds (temped) into file named \"MY_EX_CMD.sh\""
echo "  ex  <<-EOF   >/dev/null
    e $PROD_FILE_END
`cat temped`
    w $PROD_FILE_END
    q
EOF $fil "  > MY_EX_CMD.sh





wc MY_EX_CMD.sh


# echo "exit 85"
# exit 85


# execute MY_EX_CMD.sh
#
date
echo "    5. execute MY_EX_CMD.sh  `wc -l MY_EX_CMD.sh` lines  (about 4 minutes MORE)"
sh MY_EX_CMD.sh   # execute MY_EX_CMD.sh
date


#  FYI    export PROD_FILE_BEG="per_emcc_my2.html"
#  FYI    export PROD_FILE_END="prodtst.html"





echo "-------------------------------------------------"
wc -c $PROD_FILE_BEG
wc -c $PROD_FILE_END
echo "-------------------------------------------------"
CB=`wc -c $PROD_FILE_BEG | awk '{print $1}' `
CE=`wc -c $PROD_FILE_END | awk '{print $1}' `
let diff="$CB - $CE"
let pc="$diff * 100 / $CB"
echo " $diff  fewer characters  $pc percent"
echo "-------------------------------------------------"

echo "-------------------------------------------------"
wc -l $PROD_FILE_BEG
wc -l $PROD_FILE_END
echo "-------------------------------------------------"
LB=`wc -l $PROD_FILE_BEG | awk '{print $1}' `
LE=`wc -l $PROD_FILE_END | awk '{print $1}' `
let diff="$LB - $LE"
let pc="$diff * 100 / $LB"
echo "   $diff  fewer lines       $pc percent"
echo "-------------------------------------------------"


# part 2 of 2 info
echo "================================================================================"
echo "FYI,  here the input file \"prod_input.html\" is changed"
echo "      and renamed into \"prodtst.html\""
echo " "
echo "NOW,  finish making prodtst.html by PUTTING BACK  emcc.js and jquery to it"
echo "${REVon}    mvim prodtst.html ${Toff}"
echo "  2.    in vi, "
echo "        Go to the start of the code to be put back"
echo "           Search for the line  \"<script type='t${RED}ext/ja${Toff}vascript'>\" "
echo "        On the next line READ IN the lines from the file you saved earlier- "
echo "        ${RED}:r save_jquery_emcc.js ${Toff}"
echo "  3.    ${RED}:w prodtst.html ${Toff}"
echo " "
echo "AFTERWARDS, "
echo "${REVon} sh cfns.sh ${Toff} "
echo "             cfns.sh takes \"prodtst.html\" as input "
echo "             and writes out a changed version of \"prodtst.html\" . "
echo "             This \"prodtst.html\" is the final production version"  
echo "${REVon}   cp prodtst.html igotostars_PROD.html ${Toff} "
echo "${REVon}   cp prodtst.html index.html ${Toff} "
echo "================================================================================"
echo " "
echo "================================================================================"
echo "for GITHUB  AND"
echo " for updating goDaddy using /Users/rk/github_files/igotostars_PROD.html"
echo " for updating goDaddy using index.html"
echo "AFTERWARDS,"
echo "${REVon}   sh cpToGithub.sh ${Toff}"
echo "             creates  /Users/rk/github_files/non_emsdk.cpio"
echo "for GITHUB"
echo "================================================================================"


echo "exit 99"
exit  99









# below this not used anymore  (FOR NOW)


# 
# export MINIFY_PGM="/Users/rk/_PC/usr/Apple/_C/_wrk/free/closure-compiler/minify_2.3.4_darwin_386/minify"
# 
# 
# awk '{  
#   print $0
#   if ($0 ~ /<style>/) exit
# }' per_emcc_my2.html >ig2s_1.html
# 
# echo "     1. html_1  from beginning to <style>"
# ${MINIFY_PGM} ig2s_1.html > ig2s_1.min
# 
# 
# echo "     2. css     GRAB CSS code after <style> and before </style> "
# awk '{  
#   if ($0 ~ /<\/style>/)  exit
#   if ($0 ~ /<style>/) {
#     write_now = "yes"
#     next                        # note that <style> line is in ig2s_1  and  </style> is in ig2s_3
#   }
#   if (write_now == "yes") print $0
# }' per_emcc_my2.html >ig2s_2.css
# 
# ${MINIFY_PGM} ig2s_2.css > ig2s_2.min
# 
# 
# echo "     3. html_2  GRAB html from </style>  to where jquery starts (has image files) "
# awk '{  
#   if ($0 ~ /ig2s_3_END/)            last_line = "yes"
#   if (last_line == "yes") {
#     print $0
#     exit
#   }
#   if ($0 ~ /<\/style>/)             write_now = "yes"
#   if (write_now == "yes") print $0
# }' per_emcc_my2.html >ig2s_3.html
# 
# ${MINIFY_PGM} ig2s_3.html > ig2s_3.min
# 
# 
# echo "     4. jQuery    copy in min version"
# 
# 
# #cp jquery-3.3.1.js ig2s_4.js
# cp jquery-3.3.1.min.js ig2s_4.min
# 
# 
# echo "     5. C CODE   run emcc.sh   and insert emcc.js here"
# rm emcc.js
# emcc.sh  >emcc.errs   # this produces emcc.js if no errs
# tail -10 emcc.errs
# 
# cp emcc.js ig2s_5.js
# #cp emcc.html.mem   ig2s_5.min
# #cat emcc.js  emcc.html.mem  >> ig2s_5.min
# 
# ${MINIFY_PGM} emcc.js > ig2s_5.min
# 
# 
# echo "     5b. html code that transitions to NON-C  (includes doument-ready-function start line) "
# awk '{  
#   if ($0 ~ /ig2s_5b_END/)          last_line = "yes"
#   if (last_line == "yes") {
#     print $0
#     exit
#   }
#   if ($0 ~ /ig2s_5b_START/)        write_now = "yes"
#   if (write_now == "yes") print $0
# }' per_emcc_my2.html > ig2s_5b.html          # this includes document ready function
# 
# #${MINIFY_PGM} ig2s_5b.html > ig2s_5b.min
# 
# 
# #     6. non-c   GRAB from "// END OF MY C CODE plus JQuery"  to  "// END of my non-c code for runclo minification"
# echo "     6.  NON-C js - GRAB all javascript code to be minified"
# awk '{  
#   if ($0 ~ /ig2s_6_END/)           last_line = "yes"
#   if (last_line == "yes") {
#     print $0
#     exit
#   }
#   if ($0 ~ /ig2s_6_START/)          write_now = "yes"
#   if (write_now == "yes")  print $0
# }' per_emcc_my2.html  >  ig2s_6.js 
# 
# 
# #export JS_TO_MINIFY="ig2s_6.js.rm"
# export JS_TO_MINIFY="ig2s_6.js"
# 
# #        run closure on i2s_6.js
# # echo "     6. run closure on i2s_6.js   NON-C"
# #      --jscomp_warning ambiguousFunctionDecl\
# # java -jar /Users/rk/_PC/usr/Apple/_C/_wrk/free/closure-compiler/compiler-latest/closure-compiler-v20180910.jar \
# #      --js ${JS_TO_MINIFY}\
# #      --compilation_level ADVANCED_OPTIMIZATIONS\
# #      --jscomp_warning checkVars\
# #      --js_output_file ${JS_TO_MINIFY}.min  2>runclo.errs
# 
# ${MINIFY_PGM} ig2s_6.js > ig2s_6.min
# 
# 
# #     7. add "\n</script> </body> </html>\n"
# echo "     7. html  GRAB stuff at end including </script> </body> </html>"
# awk '{  
#   if ($0 ~ /ig2s_7_START/)  write_now = "yes"
#   if (write_now == "yes")  print $0
# }' per_emcc_my2.html >ig2s_7.html
# 
# #{MINIFY_PGM} ig2s_7.html > ig2s_7.min
# 
# 
# #wc -c ig2s_1.min ig2s_2.min ig2s_3.min ig2s_4.min ig2s_5.min ig2s_5b.min ig2s_6.min ig2s_7.html
# #cat   ig2s_1.min ig2s_2.min ig2s_3.min ig2s_4.min ig2s_5.min ig2s_5b.min ig2s_6.min ig2s_7.html > prodtmp.html
# 
# #wc -c ig2s_1.html ig2s_2.css ig2s_3.html ig2s_4.js ig2s_5.js ig2s_5b.html ig2s_6.js  ig2s_7.html
# #cat   ig2s_1.html ig2s_2.css ig2s_3.html ig2s_4.js ig2s_5.js ig2s_5b.html ig2s_6.js  ig2s_7.html > prodtmp.html
# 
# wc -c ig2s_1.min ig2s_2.min ig2s_3.min ig2s_4.min ig2s_5.min ig2s_5b.html ig2s_6.min  ig2s_7.html
# cat   ig2s_1.min ig2s_2.min ig2s_3.min ig2s_4.min ig2s_5.min ig2s_5b.html ig2s_6.min  ig2s_7.html > prodtmp.html
# 
# 
# ls -l prodtmp.html
# 
# # for some reason, you need the beginning of jquery to be at the start of a new line
# # so change this to this:
# #< // ig2s_5b_END html - GRAB html that includes doument-ready-function start/*!* jQuery JavaScript Library v3.3.1
# #---
# #> // ig2s_5b_END html - GRAB html that includes doument-ready-function start
# #> /*!* jQuery JavaScript Library v3.3.1
# #
# awk '{  
#   sub(/[\/][*][!][*] jQuery/, "\n/*!* jQuery", $0)
#   print $0
# }' prodtmp.html >prod.html
# 


# end of makeprod.sh

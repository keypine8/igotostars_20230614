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


# second version
export NAME_CHARS_ALL="O0QB8Il1"
export NAME_CHARS_BEG="OQBIl"      # 4-char names    tot num = 5*8*8*8 = 2,560
export BEGINNING_LETTER="O"
export OUTFIL="replacementnames_5888.txt"  # 4-char names 
#awk ' NR == 0 {
echo "junk" | awk -v chars_all="$NAME_CHARS_ALL" -v chars_beg="$NAME_CHARS_BEG" -v outfil="$OUTFIL"  '
  BEGIN {
    printf("chars_all=[%s], chars_beg=[%s]\n", chars_all, chars_beg)
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
            printf("%s%s%s%s\n", currchar1, currchar2, currchar3, currchar4)   > outfil
          }
        }
      }
    }
  }
'
#exit



# CCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCC




# export PROD_FILE_BEG="per_emcc_my2.html"
# 
# NOTE: before running this, manually remove all emcc.js code and jquery code from per_emcc_my2.html
# 
#export PROD_FILE_BEG="lastgood.html"
export PROD_FILE_BEG="per_emcc_my2.html"

export PROD_FILE_TMP1="prodtst.tmp1"
export PROD_FILE_TMP2="prodtst.tmp2"
export PROD_FILE_END="prodtst.html"


# rmCcomment.sh not good enough
#
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


# 
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


echo "    -1. remove smup_log() lines"
ed  <<-EOF   >/dev/null
  e $PROD_FILE_TMP1
  g/smup_log.*;/d
  g/smup_at.*;/d
  w $PROD_FILE_TMP2
  q
EOF



# NOTE: since /* ... */  within a line)  are GONE
# we can remove all lines  from  /^ *\/\*/ to  /\*\//  inclusive
#
echo "    -2. remove MULTI-LINE /* ... */ comments"
rm linesout.txt
export awk=awk
$awk '
{
  line = $0
  maxToRemove = 999
  if (num_removed >= maxToRemove) { print line; next; }  # print all the rest of lines
  
  if ( match(line, /^\/[*]/ ) ) {
    # this is BEG of multi-line /* ... */ comment
    areInMultiLine_comment = "yes"
    saveBEG_NR = NR
    print "REMOVED  BEG " saveBEG_NR " " line        >> "linesout.txt"
    next  # do not print line 
  } 

  if ( match(line, /[*]\/$/ ) ) {
    # this is END of multi-line /* ... */ comment
    areInMultiLine_comment = "no"
    num_removed = num_removed + 1 
    print "REMOVED  END " saveBEG_NR " " line  "\n# " num_removed "\n"  >> "linesout.txt"
    next  # do not print line 
  }

  if ( areInMultiLine_comment == "yes") {
    print "REMOVED  MID " saveBEG_NR " " line        >> "linesout.txt"
    next  # do not print line 
  }  

  print line   #  print lines not   /* ... */
}
' $PROD_FILE_TMP2  > $PROD_FILE_TMP1  




# echo exit 2  for test
# exit 2 # for test



# NOTE: since /* ... */  within a line)  are GONE
# we can remove all lines  from  /^ *\/\*/ to  /\*\//  inclusive
#
echo "    -2. remove MULTI-LINE /* ... */ comments"
rm linesout.txt
export awk=awk
$awk '
{

rmOnly = 999   # rm only this many


    line = $0
    
    if ( match(line, /^\/[*]/ ) ) {
      # this is BEG of multi-line /* ... */ comment
      areInMultiLine_comment = "yes"
#     if (cnt_commentsRemoved < rmOnly) print "\n\nBEG " NR " " line >> "linesout.txt"
      saveBEG_NR = NR

      if (cnt_commentsRemoved >= rmOnly)  print line 
#     else print "REMOVED  BEG " saveBEG_NR " " line   "   "  cnt_commentsRemoved ", " rmOnly >> "linesout.txt"
      else print "REMOVED  BEG " saveBEG_NR " " line                                          >> "linesout.txt"

      next 
    } 

    if ( match(line, /[*]\/$/ ) ) {
      # this is END of multi-line /* ... */ comment
      areInMultiLine_comment = "no"
# print "[" line "]"  >> "linesout.txt"
# print "END " saveBEG_NR " " line  >> "linesout.txt"

    if (cnt_commentsRemoved >= rmOnly) { print line }
    else {
      cnt_commentsRemoved = cnt_commentsRemoved + 1;   # both beg and end
      print "REMOVED  END " saveBEG_NR " " line                                              >> "linesout.txt"
      print "REMOVED  END " saveBEG_NR "   "  cnt_commentsRemoved " of " rmOnly "\n\n"  >> "linesout.txt"
      next  # do not print line 
    }
    next 
  }


  if ( areInMultiLine_comment == "yes") {
# print "MID " NR " " line >> "linesout.txt"

    if (cnt_commentsRemoved >= rmOnly)  print line 
#   else print "REMOVED  MID " saveBEG_NR " " line   "   "  cnt_commentsRemoved ", " rmOnly >> "linesout.txt"
    else print "REMOVED  MID " saveBEG_NR " " line                                          >> "linesout.txt"
    next 
  }  

print line   #  print lines not   /* ... */
}
' $PROD_FILE_TMP2  > $PROD_FILE_TMP1  




# echo "exit 3a"
# exit 3 # for test





# 
# echo "    -1. remove lines starting with  star,[not a slash/] /*[^/]/"
# echo "    -1. CONVENTION - on multi-line /* ... */, start all in-between lines with ^*  "
# # remove (do not print) lines starting with ^,star,[not a slash/] /*[^/]/"
# #
# export awk=awk
# $awk '
# {
#     line = $0
#     if ( match(line, /^[*][^\/]/) ) {
#       # line has pattern 
#       num_not_written_out =  num_not_written_out + 1
#       if (num_not_written_out <= 32) {   # for test
#         # do not print this line
#         print NR " " line > "linesout.txt"
#       } else {
#         print  line
#       }
#     } else {
#       print  line
#     }
# 
# }
# ' $PROD_FILE_TMP1  > $PROD_FILE_TMP2  
# #
# # remove (do not print) lines starting with ^,star,[not a slash/] /*[^/]/"
# 








# echo "    -1. remove lines starting with  star,[not a slash/] /*[^/]/"
# echo "    -1. CONVENTION - on multi-line /* ... */, start all in-between lines with ^*  "
# #g/^[*] /d
# # v/^[*][^/]/d
# # g/^[*][^/]/d
# ed  <<-EOF   >/dev/null
#   e $PROD_FILE_TMP1
#   g/^[*] /d
#   w $PROD_FILE_TMP2
#   q
# EOF




# 
# echo "    4. remove blank lines"
# # remove blank lines
# ed  <<-EOF   >/dev/null
#   e $PROD_FILE_TMP1
#   g/^$/d
#   w $PROD_FILE_TMP2
#   q
# EOF

echo "should not get here"

#cp  $PROD_FILE_TMP $PROD_FILE_END



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



# exit 9 # for test



# shuffle replacement names
# cat replacementnames.txt | awk 'BEGIN{srand();}{print rand()"\t"$0}' $1 | sort -k1 -n | cut -f2- > "goldnames.txt"
cat replacementnames_5888.txt | shuffle.sh > goldnames_5888.txt



export REPLACEMENT_NAMES="goldnames_5888.txt"
export NAMES_TO_REPLACE="namestoreplace.txt"




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
  cat goldgblsvar.txt goldidsinjs.txt goldvarvars.txt goldemccfns.txt goldnoncfns.txt goldparams.txt goldclasses.txt >  $NAMES_TO_REPLACE

  # remove comments in gold files
echo "    2b. remove comments in file  $NAMES_TO_REPLACE"
ed  <<-EOF   >/dev/null
  e $NAMES_TO_REPLACE
  g/^ *\/\//d
  g/^ *#/d
  w $NAMES_TO_REPLACE
  q
EOF


# WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW
# WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW


cp $PROD_FILE_END tstreplace.html     # cp prodtst.html tstreplace.html
fil="tstreplace.html"
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


# write edit cmds into file named temped
# 
echo "    3. put edit cmds into file named temped"
echo "" >temped
paste $NAMES_TO_REPLACE $REPLACEMENT_NAMES | while read lin
do
  let lincnt="$lincnt + 1"

  a=($(echo "$lin" | tr ' ' '\n'))  # unpaste
  old="${a[0]}"
  new="${a[1]}"
  if [ "$new" == "" ] ; then break ; fi

# printf "old=[$old]  new=[$new]\n" 

  echo "g/\<$old\>/s//$new/g" >> temped
#         old=[gbls_nav_place_now]  new=[QOQQO]
#         old=[gbls_TScontext]  new=[QOOOO]
#         old=[gbls_DIVTEXT_temp]  new=[QOQOO]

#if [ $lincnt -eq 153 ] ; then break ; fi
# if [ $lincnt -eq 9 ] ; then break ; fi
done


#   ex  <<-EOF   >/dev/null
#     e $fil
# i
# `cat temped`    
# .
#     w $fil
#     q
# EOF


# write ex invocation PLUS edit cmds (temped) into file named MY_EX_CMD
# 
echo "    4. put ex invocation PLUS edit cmds (temped) into file named \"MY_EX_CMD\""
echo "  ex  <<-EOF   >/dev/null
    e $fil
`cat temped`    
    w $fil
    q
EOF $fil "  > MY_EX_CMD


# execute MY_EX_CMD
#
echo "    5. execute MY_EX_CMD  `wc -l MY_EX_CMD` lines"
sh MY_EX_CMD   # execute MY_EX_CMD


PROD_FILE_END="tstreplace.html"


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





exit


# below this not used anymore  (FOR NOW!)  

export MINIFY_PGM="/Users/rk/_PC/usr/Apple/_C/_wrk/free/closure-compiler/minify_2.3.4_darwin_386/minify"


awk '{  
  print $0
  if ($0 ~ /<style>/) exit
}' per_emcc_my2.html >ig2s_1.html

echo "     1. html_1  from beginning to <style>"
${MINIFY_PGM} ig2s_1.html > ig2s_1.min


echo "     2. css     GRAB CSS code after <style> and before </style> "
awk '{  
  if ($0 ~ /<\/style>/)  exit
  if ($0 ~ /<style>/) {
    write_now = "yes"
    next                        # note that <style> line is in ig2s_1  and  </style> is in ig2s_3
  }
  if (write_now == "yes") print $0
}' per_emcc_my2.html >ig2s_2.css

${MINIFY_PGM} ig2s_2.css > ig2s_2.min


echo "     3. html_2  GRAB html from </style>  to where jquery starts (has image files) "
awk '{  
  if ($0 ~ /ig2s_3_END/)            last_line = "yes"
  if (last_line == "yes") {
    print $0
    exit
  }
  if ($0 ~ /<\/style>/)             write_now = "yes"
  if (write_now == "yes") print $0
}' per_emcc_my2.html >ig2s_3.html

${MINIFY_PGM} ig2s_3.html > ig2s_3.min


echo "     4. jQuery    copy in min version"


#cp jquery-3.3.1.js ig2s_4.js
cp jquery-3.3.1.min.js ig2s_4.min


echo "     5. C CODE   run emcc.sh   and insert emcc.js here"
rm emcc.js
emcc.sh  >emcc.errs   # this produces emcc.js if no errs
tail -10 emcc.errs

cp emcc.js ig2s_5.js
#cp emcc.html.mem   ig2s_5.min
#cat emcc.js  emcc.html.mem  >> ig2s_5.min

${MINIFY_PGM} emcc.js > ig2s_5.min


echo "     5b. html code that transitions to NON-C  (includes doument-ready-function start line) "
awk '{  
  if ($0 ~ /ig2s_5b_END/)          last_line = "yes"
  if (last_line == "yes") {
    print $0
    exit
  }
  if ($0 ~ /ig2s_5b_START/)        write_now = "yes"
  if (write_now == "yes") print $0
}' per_emcc_my2.html > ig2s_5b.html          # this includes document ready function

#${MINIFY_PGM} ig2s_5b.html > ig2s_5b.min


#     6. non-c   GRAB from "// END OF MY C CODE plus JQuery"  to  "// END of my non-c code for runclo minification"
echo "     6.  NON-C js - GRAB all javascript code to be minified"
awk '{  
  if ($0 ~ /ig2s_6_END/)           last_line = "yes"
  if (last_line == "yes") {
    print $0
    exit
  }
  if ($0 ~ /ig2s_6_START/)          write_now = "yes"
  if (write_now == "yes")  print $0
}' per_emcc_my2.html  >  ig2s_6.js 


#export JS_TO_MINIFY="ig2s_6.js.rm"
export JS_TO_MINIFY="ig2s_6.js"

#        run closure on i2s_6.js
# echo "     6. run closure on i2s_6.js   NON-C"
#      --jscomp_warning ambiguousFunctionDecl\
# java -jar /Users/rk/_PC/usr/Apple/_C/_wrk/free/closure-compiler/compiler-latest/closure-compiler-v20180910.jar \
#      --js ${JS_TO_MINIFY}\
#      --compilation_level ADVANCED_OPTIMIZATIONS\
#      --jscomp_warning checkVars\
#      --js_output_file ${JS_TO_MINIFY}.min  2>runclo.errs

${MINIFY_PGM} ig2s_6.js > ig2s_6.min


#     7. add "\n</script> </body> </html>\n"
echo "     7. html  GRAB stuff at end including </script> </body> </html>"
awk '{  
  if ($0 ~ /ig2s_7_START/)  write_now = "yes"
  if (write_now == "yes")  print $0
}' per_emcc_my2.html >ig2s_7.html

#{MINIFY_PGM} ig2s_7.html > ig2s_7.min


#wc -c ig2s_1.min ig2s_2.min ig2s_3.min ig2s_4.min ig2s_5.min ig2s_5b.min ig2s_6.min ig2s_7.html
#cat   ig2s_1.min ig2s_2.min ig2s_3.min ig2s_4.min ig2s_5.min ig2s_5b.min ig2s_6.min ig2s_7.html > prodtmp.html

#wc -c ig2s_1.html ig2s_2.css ig2s_3.html ig2s_4.js ig2s_5.js ig2s_5b.html ig2s_6.js  ig2s_7.html
#cat   ig2s_1.html ig2s_2.css ig2s_3.html ig2s_4.js ig2s_5.js ig2s_5b.html ig2s_6.js  ig2s_7.html > prodtmp.html

wc -c ig2s_1.min ig2s_2.min ig2s_3.min ig2s_4.min ig2s_5.min ig2s_5b.html ig2s_6.min  ig2s_7.html
cat   ig2s_1.min ig2s_2.min ig2s_3.min ig2s_4.min ig2s_5.min ig2s_5b.html ig2s_6.min  ig2s_7.html > prodtmp.html


ls -l prodtmp.html

# for some reason, you need the beginning of jquery to be at the start of a new line
# so change this to this:
#< // ig2s_5b_END html - GRAB html that includes doument-ready-function start/*!* jQuery JavaScript Library v3.3.1
#---
#> // ig2s_5b_END html - GRAB html that includes doument-ready-function start
#> /*!* jQuery JavaScript Library v3.3.1
#
awk '{  
  sub(/[\/][*][!][*] jQuery/, "\n/*!* jQuery", $0)
  print $0
}' prodtmp.html >prod.html

# end of makeprod.sh

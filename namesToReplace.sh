# ==================================================
#    produce $NAMES_TO_REPLACE  -namesToReplace.sh
#      goldgblsvar.txt  goldidsinjs.txt  goldvarvars.txt
# ==================================================
# 

tput clear

#  goldgblsvar.txt   approx   408 
  echo " goldgblsvar.txt   approx   408 "
  grep -i '^ *var  *gbls'   prodtst.html  > replaceTmp1
  awk -F'[ ;]' '{ print $2 }' replaceTmp1  | sort >  goldgblsvar.txt 

  # here, manually check goldgblsvar.txt for dups

  wc goldgblsvar.txt 
  tail -2 goldgblsvar.txt 
  echo "_____________________________________________________________________________"
  echo "_____________________________________________________________________________"

#  goldidsinjs.txt   approx 1,090 
 echo " goldidsinjs.txt   approx 1,090 "
 grep -o "\<id='[^']*'" prodtst.html >  replaceTmp1 # matches id=' ... up to FIRST '

  #   this replaces lines like:
  #id='smup_divNAVB'
  #   with lines like:
  #smup_divNAVB
  sed "s/.*\'\([^\']*\)\'/\1/" replaceTmp1  | sort >  goldidsinjs.txt

  # here, manually check goldidsinjs.txt for dups

  wc goldidsinjs.txt
  tail -2 goldidsinjs.txt
  echo "_____________________________________________________________________________"
  echo "_____________________________________________________________________________"
  
#  goldvarvars.txt   approx 808
  echo  goldvarvars.txt   approx 808
  grep -i ' var '   prodtst.html  > replaceTmp1  

  wc replaceTmp1
  tail -2 replaceTmp1
  
  # this replaces lines like:
  #     var rect = el.getBoundingClientRect();
  # with lines like:
  #rect
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
  tail -2 goldvarvars.txt
  
  echo "_____________________________________________________________________________"
  echo "_____________________________________________________________________________"
  
  sleep 3
  mvim  goldgblsvar.txt  goldidsinjs.txt  goldvarvars.txt
# cat  goldgblsvar.txt  goldidsinjs.txt  goldvarvars.txt >tfr9; mvim tfr9   2315 lines

exit

  #  SAME NAME CHECK
  #  goldgblsvar.txt  goldidsinjs.txt  goldvarvars.txt


# 
# ==================================================
#    produce $NAMES_TO_REPLACE  -namesToReplace.sh
# ==================================================

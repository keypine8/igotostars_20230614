# cfns.sh

export PROD_FILE_END="prodtst.html"


#export MY_NAMES_TO_REPLACE="mamb_report_trait_rank\
echo "\c" > myCfns.tmp

echo "mamb_report_trait_rank
mamb_report_best_day
getPltPosSTR
seq_find_exact_cpc
mamb_report_personality
make_per_htm_file
mamb_report_just_2_people
bin_find_first_city
mamb_report_year_in_the_life
mamb_report_big_year
mamb_report_person_in_group
mamb_report_whole_group" | while read fnName
do
  echo "$fnName"  >> myCfns.tmp
done

export NUM_Cfns=`cat myCfns.tmp | wc -l`

tail -n ${NUM_Cfns} replacementnames.txt > myCnew.tmp  # grab  last few replacementnames (assume not used already)

echo "\c" >temped
paste myCfns.tmp myCnew.tmp | while read lin
do
  let lincnt="$lincnt + 1"

  a=($(echo "$lin" | tr ' ' '\n'))  # unpaste
  old="${a[0]}"
  new="${a[1]}"
  if [ "$new" == "" ] ; then break ; fi

# echo "v/base64,iVBORw0/s/\<$old\>/$new/g" >> temped # v = skip editing large image lines
  echo "%s/\<$old\>/$new/g" >> temped # v = skip editing large image lines
  echo "%s/\<_$old\>/_$new/g" >> temped # v = skip editing large image lines

done

wc temped
cat temped


# write ex invocation PLUS edit cmds (temped) into file named MY_EX_CMD2.sh
# 
echo "    4. put ex invocation PLUS edit cmds (temped) into file named \"MY_EX_CMD2.sh\""
echo "  ex  <<-EOF   >/dev/null
    e $PROD_FILE_END
`cat temped`
    w $PROD_FILE_END
    q
EOF $fil "  > MY_EX_CMD2.sh

cat MY_EX_CMD2.sh


# execute MY_EX_CMD2.sh
#
echo "    5. execute MY_EX_CMD2.sh "
sh MY_EX_CMD2.sh   # execute MY_EX_CMD.sh


exit 10
#echo -n $MY_NAMES_TO_REPLACE | while read fnName



#   OLD VERSION
# echo "------------------------------------------------------------------"
# echo "------------------------------------------------------------------"
# echo "    5. C function names"
# echo "SPECIAL treatment of ccall - have to replace  BOTH  ccall_fn_name  AND  _ccall_fn_name   using the SAME REPLACEMENt NAME"
# wc  $PROD_FILE_END
# 
# ex  <<-EOF   >/dev/null
#   e $PROD_FILE_END
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
# 
# 
#   w $PROD_FILE_END
#   q
# EOF
# echo "------------------------------------------------------------------"
# echo "------------------------------------------------------------------"
# wc  $PROD_FILE_END
# echo "-------------------------------------------------"

# end of cfns.sh

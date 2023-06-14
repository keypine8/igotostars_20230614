# prunehtml.sh

export KEEP_THIS_MANY=50   # about a months worth

#delete_me=`ls -t tfr[0-9][0-9]*.html | sed "1,${KEEP_THIS_MANY}d"`  # grab oldest
delete_me=`ls -t tfr[0-9]*.html | sed "1,${KEEP_THIS_MANY}d"`  # grab oldest

echo $delete_me

echo "-------------------------------------------"
echo "removing these files:"
for f in $delete_me
do
  ls -lt $f
done

for f in $delete_me
do
#  echo "  /bin/rm $f"      # delete oldest
  /bin/rm $f               # delete oldest
done

echo "-----------  files left -------------------"
ls -lrt tfr[0-9][0-9]*.html
echo "-------------------------------------------"

# end of prunehtml.sh

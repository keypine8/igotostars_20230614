# cpToGithub.sh

# entire dir tree at  /Users/rk/_PC/usr/Apple/_C/_wrk/free/emsdk-portable

export DIR_TO_COPY_FROM=/Users/rk/_PC/usr/apple/_c/_wrk/free
export DIR_TO_COPY_TO=/Users/rk/github_files


echo "cd $DIR_TO_COPY_FROM"
cd $DIR_TO_COPY_FROM

# person_*
# gvimrc_SAVE*
# *track*
# icon*
# appNav*

# remove big files to copy to github
#
# console.c
# igotostars_PROD.html
# prodtst.html
# OLD.txt
# -rwxrwxrwx  1 rk  staff  792144896 25 Jan  2021 emdsk.cpio
# -rwxrwxrwx  1 rk  staff  269542881 25 Jan  2021 emdsk.cpio.gzip
# -rw-r--r--  1 rk  staff   11947305 11 Feb 15:06 igotostars_PROD.html
# -rwxrwxrwx  1 rk  staff   46367232 11 Feb 15:06 non_emsdk.cpio
# -rw-r--r--  1 rk  staff   11947305 11 Feb 15:06 prodtst.html
# -rw-r--r--  1 rk  staff    9944569 20 Jan  2021 save_emcc.js
#
# remove big files to copy to github

FILES_TO_COPY="
MAMB_mindmap.m
Makefile
cfns.sh
cpToGithub.sh
emcc.sh
futasp.c
futdefs.h
futdoc.c
futdoc.h
futhtm.c
futhtm.h
goldCfns.txt
goldclassesinC.txt
goldclassesinjs.txt
goldgblsvar.txt
goldidsinC.txt
goldidsinjs.txt
goldnames.txt
goldparams.txt
goldvarvars.txt
grpdoc.c
grpdoc.h
grphtm.c
gvimrc_SAVE_20200131_HTMLandJS
igotostarsDevel_emsdkFiles.txt
igotostarsDevel_info.txt
incocoa.c
incocoa.h
jquery-3.3.1.js
macVimSynHIcategories.txt
makeprod.sh
mambutil.c
mkbak
namesToReplace.sh
per_emcc_my2.html
perdoc.c
perdoc.h
perhtm.c
perhtm.h
prunehtml.sh
rk.h
rkdebug.c
rkdebug.h
rkdebug_externs.h
rktest.c
rktest.sh
s.sh
save_emcc.js
save_jquery
shuffle.sh"


for fil in $FILES_TO_COPY
do
  echo "cp $DIR_TO_COPY_FROM/$fil $DIR_TO_COPY_TO"
  cp -p "$fil" "$DIR_TO_COPY_TO"
  #  -p    Cause cp to preserve the following attributes of each source file
  #  in the copy: modification time, access time, file flags, file mode,
  #  user ID, and group ID, as allowed by permissions.  Access Control
  #  Lists (ACLs) and Extended Attributes (EAs), including resource
  #  forks, will also be preserved.
  #
done  


# 20230312  do not do
# 
# # put non-emdsk files into cpio
# echo  "$FILES_TO_COPY"  |  cpio -o  > $DIR_TO_COPY_TO/non_emsdk.cpio
# 
# 20230312  do not do



# end of cpToGithub.sh

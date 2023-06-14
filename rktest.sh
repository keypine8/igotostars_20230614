# this is rktest.sh

# #include <mcheck.h>
#   void mtrace(void)
#   void muntrace(void)
#
# Note that you need to compile with the -g option to get useful output.
# gcc yourProgram.c -g
#
#   there is a Perl script, of the same name, that can be downloaded
#   to accomplish the same task. The mtrace syntax is as follows:
#     mtrace <exec_file_name> <malloc_trace_filename> 
# 
# MALLOC_TRACE="t.leak"
# export MALLOC_TRACE

rm t.incocoa   2>/dev/null
rm t.out       2>/dev/null
rm t.data_per  2>/dev/null
rm t.data      2>/dev/null

#time incocoa.exe   2>t.incocoa  >t.data

time incocoa.exe   2>t.out

exit  # ------------------------------------------------------------------------



# mkdir ./futin1  2>/dev/null
# mkdir ./fdocin1 2>/dev/null

# PP  PP  PP  PP  PP  PP  PP  PP  PP  PP  PP  PP  PP  PP  PP  PP  PP  PP  PP  PP  PP  PP  

 time fut.exe "Robin" 2013 10 17 1946 2 1 0 5 73.34   2>t.futdoc   
# time per.exe "Robin"      10 17 1946 2 1 0 5 73.34   2>t.perdoc  
# time per.exe "Robin"      10 17 1946 2 1 0 5 73.34                #

# time fut.exe "Fred" 2013 9 3 1947 9 33 1 5 84.21   2>t.futdoc    # 10 args + pgmname

#time fut.exe "Delia" 2008 12 13 1971 12 15 0 "-01" "-019.05"   2>t.futdoc    # 10 args + pgmname (correct)
#time fut.exe "Delia" 2008 12 13 1971 12 15 1 "-01" "-019.05"   2>t.futdoc    # 10 args + pgmname
#time fut.exe "Delia" 2008 12 13 1971 1 15 0 "-01" "-019.05"   2>t.futdoc    # 10 args + pgmname

# time fut.exe "Fred2" 2014 4 9 2013 12 1 0 5 84.21   2>t.futdoc    # 10 args + pgmname

# time per.exe "Fred" 9 3 1947 9 33 1 " 05" " 084.21"   2>t.perdoc    # 9 args + pgmname

exit

# PP  PP  PP  PP  PP  PP  PP  PP  PP  PP  PP  PP  PP  PP  PP  PP  PP  PP  PP  PP  PP  PP  


# FUT FUT FUT FUT FUT FUT FUT FUT FUT FUT FUT FUT FUT FUT FUT FUT FUT FUT FUT FUT FUT FUT 
# times fut.exe "Fred" 2013 9 3 1947 10 33 1 5 84.21   2>t.futdoc    # 10 args + pgmname
# time -p fut.exe "Fred" 2013 9 3 1947 10 33 1 5 84.21   2>t.futdoc    # 10 args + pgmname

#  time fut.exe "Fred" 2013 9 3 1947 10 33 1 5 84.21   2>t.futdoc    # 10 args + pgmname
#    real    0m0.750s
#    user    0m0.187s
#    sys     0m0.531s

#time fut.exe "Fred" 2013 9 3 1947 10 33 1 5 84.21                 # 10 args + pgmname
#time fut.exe "Fred" 2013 9 3 1947 10 33 1 5 84.21   2>t.futdoc    # 10 args + pgmname
#time fut.exe "Delia" 2008 12 13 1971 12 15 0 -1 -19.05   2>t.futdoc    # 10 args + pgmname

#echo " -  starting fut.exe "Fred" 2013 9 3 1947 10 33 1 5 84.21 " 
# time fut.exe "Fred" 2013 9 3 1947 10 33 1 5 84.21   2>t.futdoc    # 10 args + pgmname

echo "time fut.exe "Delia" 2008 12 13 1971 12 15 0 -1 -19.05"
time fut.exe "Delia" 2008 12 13 1971 12 15 0 -1 -19.05   2>t.futdoc    # 10 args + pgmname

# test yr in life = birth year 
#echo "time fut.exe "Delia" 1971 12 13 1971 12 15 0 -1 -19.05"
#time fut.exe "Delia" 1971 12 13 1971 12 15 0 -1 -19.05   2>t.futdoc    # 10 args + pgmname

# test yr in life = birth year 
#echo " -  starting fut.exe "Fred" 1947 9 3 1947 10 33 1 5 84.21 " 
# time fut.exe "Fred" 1947 9 3 1947 10 33 1 5 84.21   2>t.futdoc    # 10 args + pgmname

#echo " -  starting fut.exe "Fred2" 2013 9 3 1947 10 33 1 5 84.21 " 
# time fut.exe "Fred2" 2014 4 9 2013 12 1 0 5 84.21   2>t.futdoc    # 10 args + pgmname

# FUT FUT FUT FUT FUT FUT FUT FUT FUT FUT FUT FUT FUT FUT FUT FUT FUT FUT FUT FUT FUT FUT 


echo " -  finished fut.exe "

exit

# OLD export ID=fut_1inp  # test input
# OLD fut.exe futin1/$ID fdocin1/ 88 42 


# end of rktest.sh

# this works
#
# set -x
# /bin/gcc -I. -L /usr/i686-pc-mingw32/sys-root/mingw/lib   calcchrt.o futasp.o futdoc.o -o fut.exe
#
# exit
#
#
# see this:
# $ CYGWIN:/cygdrive/c/usr/apple/c/wrk
# $ sh rktest.sh
# + /bin/gcc -I. -L /usr/i686-pc-mingw32/sys-root/mingw/lib calcchrt.o futasp.o futdoc.o -o fut.exe
# futdoc.o:futdoc.c:(.text+0x27d0): undefined reference to `_min'
# collect2: ld returned 1 exit status
# + exit

# <.> ld err fu.texe
#  ld returned 1 exit status 
# undefined reference to `_MIN'   (used var min for minute *plus* fn min(a,b)


# shallow = MIN((ch->level / 13) + 2, 5);
# 
# $ make 
# gcc -Wall -O -ggdb -DNOCRYPT -DQMFIXES -c -o obj/scan.o scan.c 
# scan.c: In function `do_scan': 
# scan.c:75: warning: implicit declaration of function `MIN' 
# rm -f rom 
# gcc -O -ggdb -o rom obj/ability.o obj/act_comm.o obj/act_enter.o obj/act_info.o obj/a 
# ct_move.o obj/act_obj.o obj/act_wiz.o obj/alias.o obj/ban.o obj/bit.o obj/board.o obj 
# /comm.o obj/const.o obj/db.o obj/db2.o obj/effects.o obj/fight.o obj/flags.o obj/hand 
# ler.o obj/healer.o obj/hedit.o obj/ignore.o obj/interp.o obj/lookup.o obj/magic.o obj 
# /magic2.o obj/mem.o obj/mob_cmds.o obj/mob_prog.o obj/music.o obj/nanny.o obj/olc.o o 
# bj/olc_act.o obj/olc_mpcode.o obj/olc_save.o obj/recycle.o obj/save.o obj/scan.o obj/ 
# skills.o obj/special.o obj/string.o obj/tables.o obj/update.o 
# obj/scan.o: In function `do_scan': 
# /cygdrive/c/qmud/src/scan.c:75: undefined reference to `_MIN' 
# /cygdrive/c/qmud/src/scan.c:79: undefined reference to `_MIN' 
# obj/scan.o: In function `do_scout': 
# /cygdrive/c/qmud/src/scan.c:193: undefined reference to `_MIN' 
# /cygdrive/c/qmud/src/scan.c:197: undefined reference to `_MIN' 
# collect2: ld returned 1 exit status 
# make: *** [rom] Error 1
#
# line 75, 79, 193 and 197, all contain "shallow = MIN((ch->level / 13) + 2, 5);"

# <.>

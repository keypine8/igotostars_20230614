# shuffle.sh
# unsort a sorted file

# $ cat tfr8 | awk 'BEGIN{srand();}{print rand()"\t"$0}' | sort -k1 -n | cut -f2- > shuffled_linex.txt

awk 'BEGIN{srand();}{print rand()"\t"$0}' $1 | sort -k1 -n | cut -f2- 


# end of shuffle.sh

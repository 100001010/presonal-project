for i in {01..15}
do
    echo "$1_$i.in"
    ./"$2" <"$1_$i.in" >"$1_$i.out"
done

for i in {1..5}
do
    echo "$1_$i.in"
    ./"$2" <"$1_$i.in" >"$1_$i.out"
done

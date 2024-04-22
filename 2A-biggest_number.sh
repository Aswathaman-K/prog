echo "Enter three Numbers:" 
read a b c

if [ $a -gt $b ] && [ $a -gt $c ] 
then
echo "$a is Greatest"
elif [ $b -gt $c ] && [ $b -gt $a ] 
then
echo "$b is Greatest" 
else
echo "$c is Greatest!"
fi


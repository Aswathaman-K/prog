echo "Enter the number of N" 
read n
sum=0
for (( i=0; i<=n; i++ )) 
do
sum=$((sum + i)) 
done
echo -e "The sum of first N number is \t $sum"

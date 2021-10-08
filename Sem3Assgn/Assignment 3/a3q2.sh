args=("$@")
op=${args[0]}
len=${#args[@]}

add(){
    sum=0;
    for (( i=1;i<len;i++ ))
    do
      sum=$(( sum + ${args[i]} ))
    done
    echo "Sum is $sum"
}

sub(){
    sub=${args[1]}
    for (( i=2;i<len;i++ ))
    do
        sub=$(( sub - ${args[i]} ))
    done
    echo "Difference is $sub"
}

mul(){
    mul=1
    for (( i=0;i<len;i++ ))
    do
        mul=$(( mul * ${args[i]} ))
    done
    echo "Product is $mul"
}

div(){
    div=${args[1]}
    for (( i=2;i<len;i++ ))
    do
      div=$(( div / ${args[i]} ))
    done
    echo "Quotient is $div"
}

exp(){
    exp=${args[len-1]}
    for (( i=len-2; i>0;i-- ))
    do
        exp=$(( exp ** ${args[i]} ))
    done
    echo "Exponential is $exp"
}

if [[ "$op" == "add" ]]
then
    add
elif [[ "$op" == "sub" ]]
then
    sub
elif [[ "$op" == "mul" ]]
then
    mul
elif [[ "$op" == "div" ]]
then
    div
elif [[ "$op" == "exp" ]]
then
    exp
else
echo "command not found"
fi
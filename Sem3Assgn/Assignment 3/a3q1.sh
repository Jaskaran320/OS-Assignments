echo "Enter the date in the format dd/mm/yyyy : "
# month = 1,3,5,7,8,10,12 then d>0 and d<32
# month = 4,6,9,11 then d>0 and d<31
# month = 2, then if year%4==0 then d<30 and d>0 else d<29 and d>0
read date
month=${date:3:2}
day=${date:0:2}
year=${date:6:4}
if [ $month -eq "1" ] || [ $month -eq "3" ] || [ $month -eq "5" ] || [ $month -eq "7" ] || [ $month -eq "8" ] || [ $month -eq "10" ] || [ $month -eq "12" ]
then
    if [ $day -gt "0" ] && [ $day -lt "32" ]
    then
        cal ${date:3:2} ${date:6:4}
    else
        echo "Wrong date entered"
    fi
elif [ $month -eq "4" ] || [ $month -eq "6" ] || [ $month -eq "9" ] || [ $month -eq "11" ]
then
    if [ $day -gt "0" ] && [ $day -lt "31" ]
    then
        cal ${date:3:2} ${date:6:4}
    else
        echo "Wrong date entered"
    fi
elif [ $month -eq "2" ] 
then 
    if [  $(expr $year % 4) != "0" ]
    then
        if [ $day -lt "29" ] && [ $day -gt "0" ]
        then
            cal ${date:3:2} ${date:6:4}
        else
            echo "Wrong date entered"
        fi
    else
        if [ $day -lt "30" ] && [ $day -gt "0" ]
        then
            cal ${date:3:2} ${date:6:4}
        else
            echo "Wrong date entered"
        fi
    fi
else 
    echo "Wrong month enterd"
fi
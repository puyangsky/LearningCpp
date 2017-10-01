git add -n
echo "continue?y/n:"
read contin
if [[ $contin != 'y' && $contin != 'Y' ]];then
	exit 1;
fi
git add .
echo "input commit message:"
read msg
echo $msg
git commit -m "$msg"
git push origin master

if [ $# != 2 ]; then
	echo "Usage\n\tgit_initial_push name path/to/token/file"
fi
name=$1
token=$(cat $2)

git init
git add -A
git commit -m "initial commit"
git remote add origin https://aussie114:$token@github.com/aussie114/$name.git
git push -u origin master

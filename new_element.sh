if [ $# != 1 ]; then
	echo "No file name specified"
	exit
fi

element=$1
ELEMENT="${1^^}"

if [ -f "include/$element.h" ] || [ -f "src/$element.c" ]; then
    echo "element with that name already exists"
	exit
fi

printf "#ifndef %s_H\n#define %s_H\nextern GtkWidget * %s;\nvoid create_%s();\n#endif" $ELEMENT $ELEMENT $element $element > include/$element.h
printf "#include <gtk/gtk.h>\n\nGtkWidget * %s\n\nvoid create_%s()\n{\n}\n" $element $element > src/$element.c

#!/bin/bash

B="master"
while git co $B > /dev/null
do
    read A B <<< $(git log --pretty=format:"%h" | head -n2 | xargs)
    dirname=../git_diffs/"$(git log --pretty=format:"%s" | head -n1)"
    mkdir -p "$dirname"
    git diff-tree -t $A $B | awk '{print $5" "$6}' | while read ACTION FILE
    do
        if [ "$ACTION" = "M" ] || [ "$ACTION" = "D" ]; then
            if [ -f "$FILE" ] || [ -d "$FILE" ]; then
                cp -r "$FILE" "$dirname"/
                echo "cp -r "$FILE" $dirname/"
            fi
        fi
    done
    if [ ! $B ]; then
        break
    fi
#    sleep 1
done
